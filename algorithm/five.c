/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:48:15 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/03 18:07:36 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void handle_5(t_list **stack_a, t_list **stack_b)
{
    t_list *smallest;
    int size;

    smallest = find_smallest_nb(stack_a);
    size = ft_lstsize(*stack_a);
    rot_stack(stack_a, true);
    push(stack_a, stack_b);
    ft_printf("\nafter first push stack a = ");
    lst_print(*stack_a);
    ft_printf("\nafter first push stack b = ");
    lst_print(*stack_b);
    handle_4(stack_a, stack_b);
    push(stack_b, stack_a);
    ft_printf("\nafter second push stack a = ");
    lst_print(*stack_a);
    ft_printf("\nafter second push stack b = ");
    lst_print(*stack_b);
}
