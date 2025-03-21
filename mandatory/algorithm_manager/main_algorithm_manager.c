/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:17:06 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 13:27:50 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_null(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
}

void	index_assign(t_list **stack)
{
	int		size;
	int		i;
	t_list	*current;
	t_list	*min;

	index_null(stack);
	size = ft_lstsize(*stack);
	current = *stack;
	i = 0;
	min = NULL;
	while (i < size)
	{
		min = NULL;
		current = *stack;
		while (current)
		{
			if (current->index == -1 && (!min || current->number < min->number))
				min = current;
			current = current->next;
		}
		if (min)
			min->index = i++;
	}
}

void	move_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		min;
	int		max;

	min = 0;
	max = (ft_lstsize(*stack_a) * 0.05 + 10);
	while (*stack_a)
	{
		ptr = *stack_a;
		if (min <= ptr->index && ptr->index <= max)
		{
			push(stack_a, stack_b, "b");
			min++;
			max++;
		}
		else if (ptr->index < min)
		{
			push(stack_a, stack_b, "b");
			rotate(stack_b, "b");
			min++;
			max++;
		}
		else if (ptr->index > max)
			rotate(stack_a, "a");
	}
}

void	algo_manager(t_list **stack_a, t_list **stack_b)
{
	index_assign(stack_a);
	move_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		apply_moves(stack_b, find_biggest_nb(stack_b), "b");
		push(stack_b, stack_a, "a");
	}
}
