/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:10:26 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/03 16:19:15 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push(t_list **from, t_list **to)
{
    t_list *tmp;

    if (!from || !to || !(*from))
        return;
    tmp = *from;
    *from = tmp->next;
    if (*from)
        (*from)->prev = NULL;
    tmp->next = *to;
    if (*to)
        (*to)->prev = tmp;
    *to = tmp;
}
