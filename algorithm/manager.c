/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:28:52 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/03 12:58:21 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void algo_manager(t_list **stack_a)
{
    // check_sort(stack_a);
    if (check_sort(stack_a) == -1)
        clear_exit(stack_a, EXIT_FAILURE);
    else
    {
        rot_stack(stack_a, true);
        clear_exit(stack_a, EXIT_SUCCESS);
    }
    check_rev_sort(stack_a);
}
void clear_exit(t_list **stack, int exit_code)
{
    ft_lstclear(stack, del);
    exit(exit_code);
}
