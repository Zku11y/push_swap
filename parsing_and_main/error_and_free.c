/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:38:43 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/10 18:22:20 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear_nodes(t_list **lst)
{
	t_list	*ptr;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		free(ptr);
	}
	*lst = NULL;
}

void	ft_error(t_list *stack)
{
	if (stack)
		ft_lstclear_nodes(&stack);
	write(1, "\e[1;31mError\e[0m", 17);
	check_leaks();
	exit(EXIT_FAILURE);
}
