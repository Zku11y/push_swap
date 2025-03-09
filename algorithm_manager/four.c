/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:47:57 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/09 19:43:23 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;
	int		size;

	smallest = find_smallest_nb(stack_a);
	size = ft_lstsize(*stack_a);
	rot_stack(stack_a, true, 'a');
	push(stack_a, stack_b, "b");
	handle_3(stack_a);
	push(stack_b, stack_a, "a");
}
