/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:27:09 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/28 11:42:08 by mdakni           ###   ########.fr       */
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
