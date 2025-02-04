/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:16:40 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/04 19:28:06 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi_long(const char *str)
{
	int			i;
	long long	answer;
	int			sign;

	i = 0;
	answer = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
		answer = (answer * 10) + (str[i++] - '0');
	return ((long)(answer * sign));
}

int	error_check(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	int		*arr;
	long	tmp;
	int		i;
	int		j;

	i = 1;
	arr = ft_calloc(ac, sizeof(int));
	while (i <= ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j++]))
				return (-1);
		}
		tmp = ft_atoi_long(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN || arr[tmp])
		{
			write(1, "\033[1;31mErrorsuka\033[0m\n", 17);
			return (-1);
		}
		arr[tmp] = tmp;
		ft_lstadd_back(stack_a, ft_lstnew((void *)(intptr_t)arr[tmp]));
		ft_lstadd_back(stack_b, ft_lstnew(0));
		i++;
	}
	return (0);
}

void	print_content(void *content)
{
	ft_printf("%d\n", (int)content);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (-1);
	stack_a = malloc(sizeof(t_list));
	stack_b = malloc(sizeof(t_list));
	if (stack_a == NULL || stack_b == NULL)
	{
		write(1, "\033[1;31mError1\033[0m\n", 17);
		return (0);
	}
	if (error_check(ac - 1, av, &stack_a, &stack_b) == -1)
	{
		write(1, "\033[1;31mError2\033[0m\n", 17);
		return (0);
	}
	write(1, "\e[1;32mSuccess!\e[0m\n", 21);
	ft_printf("\e[1;33mstack a size = %d, stack b size = %d\e[0m\n",
		ft_lstsize(stack_a), ft_lstsize(stack_b));
	// ft_lstiter(stack_a, print_content);
	return (0);
}

// In case of error,
// it must display "Error" followed by a ’\n’ on the standard error.
// Errors: some arguments aren’t integers,some arguments are
// bigger than an integer and/or there are duplicates
// ft_printf("%s\n", av[i]);