/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:43:04 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/08 20:45:27 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	int tmp;

	tmp = (*stack_a)->nb;
	(*stack_a)->nb = (*stack_b)->nb;
	(*stack_b)->nb = tmp;
}