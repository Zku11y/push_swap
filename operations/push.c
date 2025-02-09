/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:43:04 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/09 11:00:40 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_ints	tmp;

	reverse_rotate(stack_b);
	tmp = (*stack_b)->nb;
	(*stack_b)->nb = (*stack_a)->nb;
	(*stack_a)->nb = tmp;
	rotate(stack_a);
}
