/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:15:35 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/06 13:05:25 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

t_stack	*ft_lstnew(int data)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	printf("data before put in list = %d\n", data);
	ptr->content = data;
	printf("data after put in list = %d\n", ptr->content);
	ptr->next = NULL;
	return (ptr);
}
