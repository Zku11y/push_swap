/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:11:18 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/27 17:35:40 by mdakni           ###   ########.fr       */
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
    rev_stack(stack);
}
void rev_stack(t_list **stack)
{
    t_list *stack_b;
    t_list *iter;
    t_list *iter2;

    iter = *stack;
    iter2 = stack_b;
    while (stack)
    {
        ft_lstadd_back(&stack_b, ft_lstnew(NULL));

        iter = iter->next;
    }
}
