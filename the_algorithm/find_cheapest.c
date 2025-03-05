/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:29:00 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/05 17:27:51 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list *cheapest_manager(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp_a;
    t_list *tmp_b;
    t_list *cheapest;
    int *arr;
    int i;

    i = 0;
    arr = malloc(ft_lstsize(*stack_a) * sizeof(int));
    if (arr == NULL)
        return (clear_exit(stack_a, stack_b, EXIT_FAILURE), NULL);
    tmp_a = *stack_a;
    while(tmp_a)
    {
        tmp_b = b_position(stack_b, tmp_a->number);
        arr[i] = calc_moves(stack_a, tmp_a) + calc_moves(stack_b, tmp_b);
        tmp_a = tmp_a->next;
        i++;
    }
    cheapest = find_cheapest(stack_a, arr);
    return (free(arr), cheapest);
}
t_list *find_cheapest(t_list **stack, int *arr)
{
    int i;
    int smallest;
    t_list *current;

    i = 0;
    current = *stack;
    smallest = 0;
    while (i < ft_lstsize(*stack))
    {
        if (arr[i] < arr[smallest])
            smallest = i;
        i++;
    }
    i = 0;
    while (current && i++ < smallest)
        current = current->next;
    return (current);
}
t_list *b_position(t_list **stack_b, int a)
{
    int tmp;
    long long prev;
    t_list *smallest;
    t_list *current;

    if(!*stack_b ||!(*stack_b)->next)
        return (*stack_b);
    current = *stack_b;
    tmp = current->number;
    smallest = current;
    prev = -2147483650;
    while (current)
    {
        if (current->number < a && current->number > prev)
        {
            prev = current->number;
            smallest = current;
        }
        current = current->next;
    }
    return (smallest);
}
int calc_moves(t_list **stack, t_list *current)
{
    t_list *tmp;
    int pos;
    int size;
    int moves;

    pos = 0;
    moves = 0;
    tmp = *stack;
    size = ft_lstsize(*stack);
    while (tmp && tmp != current)
    {
        pos++;
        tmp = tmp->next;
    }
    if (pos <= (size / 2))
    {
        while (pos-- > 0)
            moves++;
    }
    else
    {
        while (pos++ < size)
            moves++;
    }
    return (moves);
}
