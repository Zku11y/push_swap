/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:17:06 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/09 19:43:39 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_manager(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_a;
	t_list	*cheapest_b;

	push(stack_a, stack_b, "b");
	push(stack_a, stack_b, "b");
	if ((*stack_b)->number < (*stack_b)->next->number)
		rotate(stack_b, stack_a, "b");
	while ((*stack_a))
	{
		cheapest_a = cheapest_manager(stack_a, stack_b);
		cheapest_b = b_position(stack_b, cheapest_a->number);
		apply_moves(stack_a, stack_b, cheapest_a, "a");
		apply_moves(stack_b, stack_a, cheapest_b, "b");
		push(stack_a, stack_b, "b");
	}
	while ((*stack_b))
		push(stack_b, stack_a, "a");
	rot_stack(stack_a, true, 'a');
}
