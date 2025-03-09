/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:10:26 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/09 19:43:45 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **from, t_list **to, char *name)
{
	t_list	*tmp;
	int		fd;

	if (!from || !to || !(*from))
		return ;
	tmp = *from;
	*from = tmp->next;
	if (*from)
		(*from)->prev = NULL;
	tmp->next = *to;
	if (*to)
		(*to)->prev = tmp;
	*to = tmp;
	fd = open("./opps/operations.txt", O_RDWR | O_CREAT | O_APPEND);
	if (fd == -1)
		return (clear_exit(from, to, EXIT_FAILURE));
	write(fd, "p", 1);
	write(fd, name, 1);
	write(fd, "\n", 1);
	close(fd);
}
