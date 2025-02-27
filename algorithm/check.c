/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:11:18 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/27 15:59:38 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void check_sort(t_list **stack)
{
    int tmp;
    t_list *iter;

    if (!stack || !(*stack) || !((*stack)->next))
        return;
    iter = *stack;
    while(iter->next)
    {
        tmp = iter->number;
        if (tmp > (iter->next)->number)
        {
            ft_printf("\e[1;31mnot sorted!\e[0m\n");
            return;
        }
        iter = iter->next;
    }
    ft_printf("\e[1;32mits sorted!\e[0m\n");
}
void check_rev_sort(t_list **stack)
{
    int tmp;
    t_list *iter;

    if (!stack || !(*stack) || !((*stack)->next))
        return;
    iter = *stack;
    while(iter->next)
    {
        tmp = iter->number;
        if (tmp < (iter->next)->number)
        {
            ft_printf("\e[1;31mnot reverse sorted!\e[0m\n");
            return;
        }
        iter = iter->next;
    }
    ft_printf("\e[1;32mits reverse sorted!\e[0m\n");
    
}
// void rev_stack(t_list **stack)
// {
    
// }