/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:10:20 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/09 19:45:20 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack, t_list **stack_b, char *name)
{
	int		tmp;
	t_list	*head;
	int		fd;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	head = *stack;
	tmp = head->number;
	head->number = (head->next)->number;
	(head->next)->number = tmp;
	fd = open("./opps/operations.txt", O_RDWR | O_CREAT | O_APPEND);
	if (fd == -1)
		return (clear_exit(stack, stack_b, EXIT_FAILURE));
	write(fd, "s", 1);
	write(fd, name, 1);
	write(fd, "\n", 1);
	close(fd);
}
