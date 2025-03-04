/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:11:18 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/04 11:15:18 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_sort(t_list **stack)
{
    int tmp;
    int smallest;
    t_list *small;

    if (!stack || !(*stack) || !((*stack)->next))
        return(0);
    small = find_smallest_nb(stack);
    tmp = small->number;
    smallest = tmp;
    while (small)
    {
        if(small->number < tmp)
            return (ft_printf("\e[1;31mnot sorted!\e[0m\n"), 1);
        tmp = small->number;
        small = small->next;
    }
    small = *stack;
    while(small->number != smallest)
    {
        if(small->number < tmp)
            return (ft_printf("\e[1;31mnot sorted!\e[0m\n"), 1);
        tmp = small->number;
        small = small->next;
    }
    return (rot_stack(stack, true), 0);
}
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
        return(0);
    big = find_biggest_nb(stack);
    tmp = big->number;
    biggest = tmp;
    while (big)
    {
        if(big->number > tmp)
            return (ft_printf("\e[1;31mnot  reverse sorted!\e[0m\n"), 1);
        tmp = big->number;
        big = big->next;
    }
    big = *stack;
    while(big->number != biggest)
    {
        if(big->number > tmp)
            return (ft_printf("\e[1;31mnot reverse sorted!\e[0m\n"), 1);
        tmp = big->number;
        big = big->next;
    }
    return (ft_printf("reverse sorted!"), rot_stack(stack, false), 0);
}
void rot_and_rev(int pos, int size, t_list **stack)
{
    if (size % 2 == 0)
    {
        while (pos <= (size / 2) && pos-- > 1)
            rotate(stack, NULL,"ra\n");
        while(pos > (size / 2) && pos++ <= size)
            rev_rotate(stack, NULL,"rra\n");
    }
    else
    {
        while (pos <= ((size / 2) + 1) && pos-- > 1)
            rotate(stack, NULL,"ra\n");
        while(pos > ((size / 2) + 1) && pos++ <= size)
            rev_rotate(stack, NULL,"rra\n");
    }
}

void rot_stack(t_list **stack, bool min)
{
    t_list *num;
    t_list *current;
    int pos;
    int size;

    // lst_print(*stack);
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
    rot_and_rev(pos, size, stack);
    // lst_print(*stack);
}
