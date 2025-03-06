/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:17:06 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/06 11:51:37 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void algo_manager(t_list **stack_a, t_list **stack_b)
{
    t_list *cheapest_a;
    t_list *cheapest_b;

    push(stack_a, stack_b, "b");
    push(stack_a, stack_b, "b");
    if ((*stack_b)->number <  (*stack_b)->next->number)
        swap(stack_b, stack_a, "b");
    // ft_printf("\e[1;35mBefore Operation...\e[0m\nStack_a => ");
    // lst_print(*stack_a);
    // ft_printf("stack_b => ");
    // lst_print(*stack_b);
    while((*stack_a))
    {
        cheapest_a = cheapest_manager(stack_a, stack_b);
        cheapest_b = b_position(stack_b, cheapest_a->number);
        // ft_printf("\e[1;35mbefore rotating %d to top of a...\e[0m\nStack_a => ", cheapest_a->number);
        // lst_print(*stack_a);
        // ft_printf("stack_b => ");
        // lst_print(*stack_b);
        apply_moves(stack_a, stack_b, cheapest_a, "a");
        // ft_printf("\e[1;35mafter rotating %d to top of a...\e[0m\nStack_a => ", cheapest_a->number);
        // lst_print(*stack_a);
        // ft_printf("stack_b => ");
        // lst_print(*stack_b);
        // ft_printf("\e[1;35mbefore rotating %d to top of b...\e[0m\nStack_a => ", cheapest_b->number);
        // lst_print(*stack_a);
        // ft_printf("stack_b => ");
        // lst_print(*stack_b);
        apply_moves(stack_b, stack_a, cheapest_b, "b");
        // ft_printf("\e[1;35mafter rotating %d to top of b...\e[0m\nStack_a => ", cheapest_b->number);
        // lst_print(*stack_a);
        // ft_printf("stack_b => ");
        // lst_print(*stack_b);
        push(stack_a, stack_b, "b");
        // ft_printf("\e[1;35mafter pushing %d to top of b...\e[0m\nStack_a => ", cheapest_a->number);
        // lst_print(*stack_a);
        // ft_printf("stack_b => ");
        // lst_print(*stack_b);
        // file_clear(stack_a, stack_b);
    }
    // apply_moves(stack_b, stack_a, find_biggest_nb(stack_b), "b");
    // ft_printf("\e[1;32mAfter moving stack b's biggest...\e[0m\nStack_a => ");
    // lst_print(*stack_a);
    // ft_printf("stack_b => ");
    // lst_print(*stack_b);
    while((*stack_b))
        push(stack_b, stack_a, "a");
    // ft_printf("\e[1;32mAfter major push...\e[0m\nStack_a => ");
    // lst_print(*stack_a);
    // ft_printf("stack_b => ");
    // lst_print(*stack_b);
    rot_stack(stack_a, true);
    // ft_printf("\e[1;32mAfter Operation...\e[0m\nStack_a => ");
    // lst_print(*stack_a);
    // ft_printf("stack_b => ");
    // lst_print(*stack_b);
}
