/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:47:27 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/19 16:03:16 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_smallest(t_list **stack, t_list *biggest)
{
	if (biggest->next == NULL)
		swap(stack, "a");
	else
		rotate(stack, "a");
}

void	handle_middle(t_list **stack, t_list *smallest)
{
	if (smallest->next == NULL)
	{
		rotate(stack, "a");
		swap(stack, "a");
	}
}

void	handle_biggest(t_list **stack, t_list *smallest)
{
	if (smallest->next == NULL)
		rev_rotate(stack, "a");
	else
	{
		rev_rotate(stack, "a");
		swap(stack, "a");
	}
}

void	handle_3(t_list **stack)
{
	t_list	*tmp;
	t_list	*smallest;
	t_list	*biggest;

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
