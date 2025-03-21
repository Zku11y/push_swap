/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:11:18 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 15:57:17 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	check_dup(t_list **stack)
{
	int		*list;
	int		size;
	t_list	*tmp;
	int		i;

	list = malloc(ft_lstsize(*stack) * sizeof(t_list));
	if (!list)
		return (clear_exit(stack, NULL, 1));
	tmp = *stack;
	size = 0;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->number == list[i])
				return (free(list), clear_exit(stack, NULL, 1));
			i++;
		}
		list[i] = tmp->number;
		size++;
		tmp = tmp->next;
	}
	free(list);
}

void	prev_assign(t_list **stack)
{
	t_list	*iter;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	iter = *stack;
	iter->prev = NULL;
	(iter->next)->prev = iter;
	iter = iter->next;
	while (iter->next)
	{
		(iter->next)->prev = iter;
		iter = iter->next;
	}
}
