/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:47:27 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/04 09:25:06 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void handle_smallest(t_list **stack, t_list *biggest)
{
    if (biggest->next == NULL)
        swap(stack, NULL,"sa\n");
    else
        rotate(stack, NULL,"ra\n");
}
void handle_middle(t_list **stack, t_list *smallest)
{
    if (smallest->next == NULL)
    {
        rotate(stack, NULL,"ra\n");
        swap(stack, NULL, "sa\n");
    }
}
void handle_biggest(t_list **stack, t_list *smallest)
{
    if (smallest->next == NULL)
        rev_rotate(stack, NULL, "rra\n");
    else
    {
        rev_rotate(stack, NULL,"rra\n");
        swap(stack, NULL,"sa\n");
    }
}

void handle_3(t_list **stack)
{
    t_list *tmp;
    t_list *smallest;
    t_list *biggest;

    tmp = *stack;
    smallest = find_smallest_nb(stack);
    biggest = find_biggest_nb(stack);
    if (smallest == tmp->next)
        handle_smallest(stack, biggest);
    else if (biggest == tmp->next)
        handle_biggest(stack, smallest);
     else
         handle_middle(stack, smallest);
}
