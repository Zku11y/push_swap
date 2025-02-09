/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:05:02 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/09 13:02:10 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack, char *op)
{
	t_ints	temp;

	temp = (*stack)->nb;
	if ((*stack)->next)
	{
		(*stack)->nb = ((*stack)->next)->nb;
		((*stack)->next)->nb = temp;
	}
	if (op)
		ft_printf("%s\n", op);
}
