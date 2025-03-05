/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:17:06 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/05 16:51:10 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void algo_manager(t_list **stack_a, t_list **stack_b)
{
    t_list *cheapest_a;
    t_list *cheapest_b;

    push(stack_a, stack_b, "pa");
    push(stack_a, stack_b, "pa");
    if ((*stack_b)->number <  (*stack_b)->next->number)
        swap(stack_b, stack_a, "sb");
    cheapest_a = cheapest_manager(stack_a, stack_b);
    cheapest_b = b_position(stack_b, cheapest_a->number);
    ft_printf("cheapest a = %d\n", cheapest_a->number);
    ft_printf("cheapest b = %d\n", cheapest_b->number);
    clear_exit(stack_a, stack_b, EXIT_SUCCESS);
}
