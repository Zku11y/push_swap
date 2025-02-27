/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:10:25 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/27 16:02:31 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_list **stack)
{
    t_list *old_head;
    t_list *old_tail;

    if (!stack || !(*stack) || !((*stack)->next))
        return;
    old_head = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    old_head->next = NULL;
    old_tail = ft_lstlast(*stack);
    old_tail->next = old_head;
    old_head->prev = old_tail;
}
void rev_rotate(t_list **stack)
{
    t_list *old_head;
    t_list *old_tail;

    old_head = *stack;
    old_tail = ft_lstlast(old_head);
    (old_tail->prev)->next = NULL;
    old_tail->prev = NULL;
    old_tail->next = old_head;
    old_head->prev = old_tail;
    *stack = old_tail;
}
