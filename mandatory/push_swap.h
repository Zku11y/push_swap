/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:34:11 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 13:35:01 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/libft/libft.h"
# include "../includes/printf/ft_printf.h"
# include <stdbool.h>

typedef struct range
{
	int		min;
	int		max;
}			t_range;

typedef struct cheapest
{
	bool	ra;
	bool	rb;
	int		moves_a;
	int		moves_b;
	int		far;
	t_list	*a;
	t_list	*b;
}			t_cheap;

// Operation functions
void		rot_stack(t_list **stack, bool min, char name);
void		push(t_list **from, t_list **to, char *name);
void		swap(t_list **stack, char *name);
void		rotate(t_list **stack, char *name);
void		rev_rotate(t_list **stack, char *name);

// Small Algorithm functions
void		handle_3(t_list **stack);
void		handle_4(t_list **stack_a, t_list **stack_b);
void		handle_5(t_list **stack_a, t_list **stack_b);
int			assign_manager(char *str, t_list **stack_a);

// Big Algorithm functions (THE MOST IMPORTANT PART OF THE CODE)
void		algo_manager(t_list **stack_a, t_list **stack_b);
int			calc_moves(t_list **stack, t_list *current);
void		apply_moves(t_list **s1, t_list *num, char *n);

// checker functions
void		check_dup(t_list **stack);
int			num_check(char *str);
int			check_sort(t_list **stack, t_list **stack_b);
void		sort_checker(t_list **stack_a);
int			check_rev_sort(t_list **stack);

// misc functions
void		del(void *content);
t_list		*ft_lstnew_mod(int number);
int			ft_atoi_mod(const char *str, t_list **stack_a);
int			skip_space(int i, char *str);
int			skip_numbers(int i, char *str);
t_list		*find_biggest_nb(t_list **stack);
t_list		*find_smallest_nb(t_list **stack);
void		prev_assign(t_list **stack);
void		clear_exit(t_list **stack_a, t_list **stack_b, int exit_code);

#endif
