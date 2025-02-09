/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:22:11 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/09 13:02:48 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **stack, char *op)
{
	t_list	*temp_last;
	t_list	*temp_second;
	t_list	*temp_head;

	temp_last = *stack;
	temp_head = *stack;
	temp_second = temp_head->next;
	if (temp_second)
	{
		while (temp_last->next)
			temp_last = temp_last->next;
		temp_last->next = temp_head;
		*stack = temp_head->next;
		temp_head->next = NULL;
	}
	if (op)
		ft_printf("%s\n", op);
}
void	reverse_rotate(t_list **stack, char *op)
{
	t_list	*temp_last;
	t_list	*temp_first;
	t_list	*temp_before_last;

	temp_first = *stack;
	temp_before_last = *stack;
	if (temp_before_last->next)
	{
		while ((temp_before_last->next)->next)
			temp_before_last = temp_before_last->next;
		temp_last = temp_before_last->next;
		temp_before_last->next = NULL;
		temp_last->next = temp_first;
		*stack = temp_last;
	}
	if (op)
		ft_printf("%s\n", op);
}
