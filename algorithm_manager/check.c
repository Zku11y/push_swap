/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:11:18 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/16 14:24:40 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_list **stack, t_list **stack_b)
{
	int		tmp;
	int		smallest;
	t_list	*small;

	if (!stack || !(*stack) || !((*stack)->next))
		return (clear_exit(stack, stack_b, EXIT_SUCCESS), 0);
	small = find_smallest_nb(stack);
	tmp = small->number;
	smallest = tmp;
	while (small)
	{
		if (small->number < tmp)
			return (1);
		tmp = small->number;
		small = small->next;
	}
	small = *stack;
	while (small->number != smallest)
	{
		if (small->number < tmp)
			return (1);
		tmp = small->number;
		small = small->next;
	}
	return (rot_stack(stack, true, 'a'), 0);
}

void	check_dup(t_list **stack)
{
	int		*list;
	int		size;
	t_list	*tmp;
	int		i;

	list = malloc(ft_lstsize(*stack) * sizeof(t_list));
	if (!list)
		return (clear_exit(stack, NULL, 1));
	tmp = *stack;
	size = 0;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->number == list[i])
				return (free(list), clear_exit(stack, NULL, 1));
			i++;
		}
		list[i] = tmp->number;
		size++;
		tmp = tmp->next;
	}
	free(list);
}

int	check_rev_sort(t_list **stack)
{
	int		tmp;
	int		biggest;
	t_list	*big;

	if (!stack || !(*stack) || !((*stack)->next))
		return (0);
	big = find_biggest_nb(stack);
	tmp = big->number;
	biggest = tmp;
	while (big)
	{
		if (big->number > tmp)
			return (1);
		tmp = big->number;
		big = big->next;
	}
	big = *stack;
	while (big->number != biggest)
	{
		if (big->number > tmp)
			return (1);
		tmp = big->number;
		big = big->next;
	}
	return (rot_stack(stack, false, 'a'), 0);
}

void	rot_and_rev(int pos, int size, t_list **stack, char name)
{
	if (size % 2 == 0)
	{
		while (pos <= (size / 2) && pos-- > 1)
			rotate(stack, NULL, &name);
		while (pos > (size / 2) && pos++ <= size)
			rev_rotate(stack, NULL, &name);
	}
	else
	{
		while (pos <= ((size / 2) + 1) && pos-- > 1)
			rotate(stack, NULL, &name);
		while (pos > ((size / 2) + 1) && pos++ <= size)
			rev_rotate(stack, NULL, &name);
	}
}

void	rot_stack(t_list **stack, bool min, char name)
{
	t_list	*num;
	t_list	*current;
	int		pos;
	int		size;

	current = *stack;
	if (min == true)
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
	rot_and_rev(pos, size, stack, name);
}
