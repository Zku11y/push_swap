/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:28:36 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/06 14:24:11 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*ptr;

	printf("\e[1;31mlst last entered!!!\e[0m\n");
	printf("\e[1;31mcontent = %d, next = %p\e[0m\n", lst->content,
		(void *)lst->next);
	ptr = lst;
	if (!ptr)
	{
		return (NULL);
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}
