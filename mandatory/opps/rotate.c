/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:10:25 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 16:16:58 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **stack, char *name)
{
	t_list	*old_head;
	t_list	*old_tail;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	old_head = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	old_head->next = NULL;
	old_tail = ft_lstlast(*stack);
	old_tail->next = old_head;
	old_head->prev = old_tail;
	if (name)
	{
		write(1, "r", 1);
		write(1, name, 1);
		write(1, "\n", 1);
	}
}

void	rev_rotate(t_list **stack, char *name)
{
	t_list	*old_head;
	t_list	*old_tail;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	old_head = *stack;
	old_tail = ft_lstlast(old_head);
	(old_tail->prev)->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = old_head;
	old_head->prev = old_tail;
	*stack = old_tail;
	if (name)
	{
		write(1, "rr", 2);
		write(1, name, 1);
		write(1, "\n", 1);
	}
}
