/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:10:25 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/09 19:43:52 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **stack, t_list **stack_b, char *name)
{
	t_list	*old_head;
	t_list	*old_tail;
	int		fd;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	old_head = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	old_head->next = NULL;
	old_tail = ft_lstlast(*stack);
	old_tail->next = old_head;
	old_head->prev = old_tail;
	fd = open("./opps/operations.txt", O_RDWR | O_CREAT | O_APPEND);
	if (fd == -1)
		return (clear_exit(stack, stack_b, EXIT_FAILURE));
	write(fd, "r", 1);
	write(fd, name, 1);
	write(fd, "\n", 1);
	close(fd);
}

void	rev_rotate(t_list **stack, t_list **stack_b, char *name)
{
	t_list	*old_head;
	t_list	*old_tail;
	int		fd;

	old_head = *stack;
	old_tail = ft_lstlast(old_head);
	(old_tail->prev)->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = old_head;
	old_head->prev = old_tail;
	*stack = old_tail;
	fd = open("./opps/operations.txt", O_RDWR | O_CREAT | O_APPEND);
	if (fd == -1)
		return (clear_exit(stack, stack_b, EXIT_FAILURE));
	write(fd, "rr", 2);
	write(fd, name, 1);
	write(fd, "\n", 1);
	close(fd);
}
