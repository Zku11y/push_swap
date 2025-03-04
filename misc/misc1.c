/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:27:09 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/03 15:49:51 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list *find_smallest_nb(t_list **stack)
{
    int nb;
    t_list *current;
    t_list *small;
    current = *stack;
    small = current;
    nb = current->number;
    while (current)
    {
        if (current->number < nb)
        {
            nb = current->number;
            small = current;
        }
        current = current->next;
    }
    return (small);
}
t_list *find_biggest_nb(t_list **stack)
{
    int nb;
    t_list *current;
    t_list *big;
    current = *stack;
    big = current;
    nb = current->number;
    while (current)
    {
        if (current->number > nb)
        {
            nb = current->number;
            big = current;
        }
        current = current->next;
    }
    return (big);
}
t_list *stack_b_maker(t_list **stack_a)
{
    int size;
    int i;
    t_list *stack_b;

    i = 0;
    stack_b = NULL;
    size = ft_lstsize(*stack_a);
    while(i++ < size)
        ft_lstadd_back(&stack_b, ft_lstnew_mod(0));
    return (stack_b);
}