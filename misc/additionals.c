/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:55:06 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/08 12:13:34 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	*arr_assign(int args)
{
	int		i;
	long	*arr;

	arr = ft_calloc(args, sizeof(long));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < args)
		arr[i++] = (long)(INT_MAX) + 2;
	return (arr);
}
