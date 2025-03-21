/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:47:59 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 13:34:44 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*find_smallest_nb(t_list **stack)
{
	int		nb;
	t_list	*current;
	t_list	*small;

	current = *stack;
	small = current;
	nb = current->number;
	while (current)
	{
		if (current->number < nb)
		{
			nb = current->number;
			small = current;
		}
		current = current->next;
	}
	return (small);
}

t_list	*find_biggest_nb(t_list **stack)
{
	int		nb;
	t_list	*current;
	t_list	*big;

	current = *stack;
	big = current;
	nb = current->number;
	while (current)
	{
		if (current->number > nb)
		{
			nb = current->number;
			big = current;
		}
		current = current->next;
	}
	return (big);
}

int	calc_moves(t_list **stack, t_list *current)
{
	t_list	*tmp;
	int		pos;
	int		size;
	int		moves;

	pos = 0;
	moves = 0;
	tmp = *stack;
	size = ft_lstsize(*stack);
	while (tmp && tmp != current)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= (size / 2))
	{
		while (pos-- > 0)
			moves++;
	}
	else
	{
		while (pos++ < size)
			moves++;
	}
	return (moves);
}

void	apply_moves(t_list **s1, t_list *num, char *n)
{
	t_list	*tmp;
	int		pos;
	int		size;

	pos = 0;
	tmp = *s1;
	size = ft_lstsize(*s1);
	while (tmp && tmp != num)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= (size / 2))
	{
		while (pos-- > 0)
			rotate(s1, n);
	}
	else
	{
		while (pos++ < size)
			rev_rotate(s1, n);
	}
}
