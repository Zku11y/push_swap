/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:28:52 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/03 18:07:56 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_checker(t_list **stack_a)
{
    int check;
    int size;
    t_list *stack_b;

    size = ft_lstsize(*stack_a);
    check = check_sort(stack_a);
    if (check == 0)
        clear_exit(stack_a, EXIT_SUCCESS);
    else
    {
        if (size == 3)
        {
            handle_3(stack_a);
            ft_printf("\e[1;42mhandled 3 unsorted!\e[0m\n");
            lst_print(*stack_a);
        }
         else if (size == 4)
        {
            stack_b = stack_b_maker(stack_a);
            handle_4(stack_a, &stack_b);
            ft_lstclear(&stack_b, del);
        }
        else if (size == 5)
        {
            stack_b = stack_b_maker(stack_a);
            handle_5(stack_a, &stack_b);
            ft_lstclear(&stack_b, del);
        }
    }
}
void clear_exit(t_list **stack, int exit_code)
{
    ft_lstclear(stack, del);
    exit(exit_code);
}
