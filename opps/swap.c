/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:10:20 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/27 16:04:35 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap(t_list **stack)
{
    int tmp;
    t_list *head;

    if(!stack || !(*stack) || !((*stack)->next))
        return;
    head = *stack;
    tmp = head->number;
    head->number = (head->next)->number;
    (head->next)->number = tmp;
}
