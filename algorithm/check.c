/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:11:18 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/28 15:49:13 by mdakni           ###   ########.fr       */
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
int check_rev_sort(t_list **stack)
{
    int tmp;
    int biggest;
    t_list *big;

    if (!stack || !(*stack) || !((*stack)->next))
        return(-1);
    big = find_biggest_nb(stack);
    tmp = big->number;
    biggest = tmp;
    while (big)
    {
        if(big->number > tmp)
            return (ft_printf("\e[1;31mnot  reverse sorted!\e[0m\n"));
        tmp = big->number;
        big = big->next;
    }
    big = *stack;
    while(big->number != biggest)
    {
        if(big->number > tmp)
            return (ft_printf("\e[1;31mnot reverse sorted!\e[0m\n"));
        tmp = big->number;
        big = big->next;
    }
    return (ft_printf("\e[1;31mreverse sorted!\e[0m\n") ,rot_stack(stack, false), ft_lstclear(stack, del), -1);
}
// {
//     int tmp;
//     t_list *iter;

//     if (!stack || !(*stack) || !((*stack)->next))
//         return;
//     iter = *stack;
//     while(iter->next)
//     {
//         tmp = iter->number;
//         if (tmp < (iter->next)->number)
//         {
//             ft_printf("\e[1;31mnot reverse sorted!\e[0m\n");
//             return;
//         }
//         iter = iter->next;
//     }
//     ft_printf("\e[1;32mits reverse sorted!\e[0m\n");
// }
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
    return (rot_stack(stack, true), ft_lstclear(stack, del), -1);
}
void rot_stack(t_list **stack, bool min)
{
    t_list *num;
    t_list *current;
    int pos;
    int size;

    lst_print(*stack);
    current = *stack;
    if(min == true)
        num = find_smallest_nb(stack);
    else
        num = find_biggest_nb(stack);
    size = ft_lstsize(*stack);
    pos = 1;
    while (current && current != num)
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
