/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:30:24 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/10 22:47:58 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <dlfcn.h>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int					malloc_counter = 0;

#define line_len 1024
typedef struct s_call
{
	long			address;
	unsigned long	size;
	char			line[line_len];
}					t_call;

#define array_size 1024

t_call				allocs_array[array_size];

static int			total_leaks_size(void);
static void			print_allocs(void);

void	ff(void)
{
	system("leaks -q push_swap");
}
// ================================== PUBLIC ==================================

void	check_leaks(void)
{
	int	total;

	if (malloc_counter != 0)
	{
		total = total_leaks_size();
		fprintf(stderr,
				"\e[1;41m\nLEAKS: there are \e[0m"
				"\e[1;41m%d leaks. TOTAL size: %d bytes\e[0m\n\n",
				malloc_counter,
				total);
		print_allocs();
	}
	atexit(ff);
}

// ================================= INTERNAL =================================

static void			*(*real_malloc)(unsigned long) = 0;
static void			(*real_free)(void *) = 0;

t_call	*find_empty_position(void)
{
	for (int i = 0; i < array_size; i++)
		if (allocs_array[i].address == 0)
			return (&(allocs_array[i]));
	return (0);
}

static void	add_call(t_call *call)
{
	t_call	*position;

	position = find_empty_position();
	if (position == 0)
	{
		fprintf(stderr,
				"\e[1;31mThere is no room left for `allocs_array`\e[0m\n"
				"Please increase its size\n");
		exit(1);
	}
	memcpy(position, call, sizeof(t_call));
}

static void	remove_call(long address)
{
	for (int i = 0; i < array_size; i++)
	{
		if (allocs_array[i].address == address)
		{
			allocs_array[i].address = 0;
			allocs_array[i].size = 0;
			allocs_array[i].line[0] = '\0';
			return ;
		}
	}
	fprintf(stderr,
			"\e[1;41mTrying to free memory that have already freed or \e[0m"
			"\e[1;41mhaven't ever allocated\e[0m\n"
			"\e[1;41mAddress 0x%lx not found in `allocs_array`\e[0m\n",
			address);
	exit(2);
}

static void	print_call(t_call *call)
{
	fprintf(stderr,
			"\e[1;43mLeak at address:\e[0m"
			"\e[1;31m 0x%lx Leaked %ld bytes\n%s\e[0m\n\n",
			call->address,
			call->size,
			call->line);
}

static void	print_allocs(void)
{
	for (int i = 0; i < array_size; i++)
		if (allocs_array[i].address != 0)
			print_call(&(allocs_array[i]));
}

static int	total_leaks_size(void)
{
	int	total;

	total = 0;
	for (int i = 0; i < array_size; i++)
		if (allocs_array[i].address != 0)
			total += allocs_array[i].size;
	return (total);
}

// ================================== MALLOC ==================================

static void	malloc_init(void)
{
	real_malloc = (void *(*)(unsigned long))dlsym(RTLD_NEXT, "malloc");
	if (real_malloc == 0)
		fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
	memset(&allocs_array, 0, sizeof(allocs_array));
}

static char	*split_to_only_func(char *s)
{
	int	len;
	int	space_count;

	len = strlen(s);
	space_count = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
			space_count++;
		if (space_count == 3)
			return (s + i);
	}
	return (s);
}

static void	cp_stack(char *dst, char **s_arr, int size)
{
	int		total_len;
	char	*function;
	int		current_len;

	total_len = 0;
	for (int i = 0; i < size; i++)
	{
		function = split_to_only_func(s_arr[i]);
		current_len = strlen(function);
		total_len += current_len;
		if (total_len + 2 > line_len)
			return ;
		if (total_len != current_len)
		{
			dst[0] = '\n';
			dst += 1;
		}
		strncpy(dst, function, current_len + 1);
		dst += current_len;
	}
}

void	*malloc(unsigned long size)
{
	void	*p;
	t_call	call;
	void	*callstack[128];
	int		frames;
	char	**strs;

	if (real_malloc == 0)
		malloc_init();
	p = 0;
	p = real_malloc(size);
	call.address = (long)p;
	call.size = size;
	call.line[0] = '\0';
	frames = backtrace(callstack, 128);
	strs = backtrace_symbols(callstack, frames);
	cp_stack(call.line, strs, frames);
	add_call(&call);
	malloc_counter++;
	return (p);
}

// =================================== FREE ===================================

static void	free_init(void)
{
	real_free = (void (*)(void *))dlsym(RTLD_NEXT, "free");
	if (real_free == 0)
		fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
}

void	free(void *p)
{
	if (real_free == 0)
		free_init();

	remove_call((long)p);
	real_free(p);
	malloc_counter--;
}