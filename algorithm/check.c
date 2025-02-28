/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:11:18 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/28 11:51:06 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void check_dup(t_list **stack)
{
    int *list;
    int size;
    t_list *tmp;
    int i;

    list = malloc(ft_lstsize(*stack) * sizeof(t_list));
    if (!list)
        return(ft_lstclear(stack, del), exit(EXIT_FAILURE));
    tmp = *stack;
    size = 0;
    while (tmp)
    {
        i = 0;
        while(i < size)
        {
            if (tmp->number == list[i])
                return(ft_printf("\e[1;45mdup found!\e[0m\n") ,free(list), ft_lstclear(stack, del), exit(EXIT_FAILURE));
            i++;
        }
        list[i] = tmp->number;
        size++;
        tmp = tmp->next;
    }
    ft_printf("\e[1;44mno dups found!\e[0m\n");
    free(list);
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
int check_sort(t_list **stack)
{
    int tmp;
    int smallest;
    t_list *small;

    if (!stack || !(*stack) || !((*stack)->next))
        return(-1);
    small = find_smallest_nb(stack);
    tmp = small->number;
    smallest = tmp;
    while (small)
    {
        if(small->number < tmp)
            return (ft_printf("\e[1;31mnot sorted!\e[0m\n"));
        tmp = small->number;
        small = small->next;
    }
    small = *stack;
    while(small->number != smallest)
    {
        if(small->number < tmp)
            return (ft_printf("\e[1;31mnot sorted!\e[0m\n"));
        tmp = small->number;
        small = small->next;
    }
    return (ft_printf("\e[1;32mits sorted!\e[0m\n"), rot_stack(stack), ft_lstclear(stack, del),-1);
}
void rot_stack(t_list **stack)
{
    t_list *smallest;
    t_list *current;
    int pos;
    int size;

    lst_print(*stack);
    current = *stack;
    smallest = find_smallest_nb(stack);
    size = ft_lstsize(*stack);
    pos = 1;
    while (current && current != smallest)
    {
        pos++;
        current = current->next;
    }
    while(pos <= (size / 2) && pos-- > 1)
        rotate(stack, 'a');
    while(pos > (size / 2) && pos++ <= size)
        rev_rotate(stack, 'a');
    lst_print(*stack);
}
