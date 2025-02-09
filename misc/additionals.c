/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:55:06 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/09 10:28:10 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ints	*arr_assign(int args)
{
	int		i;
	t_ints	*arr;

	arr = ft_calloc(args, sizeof(t_ints));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < args)
	{
		arr[i].value = 0;
		arr[i].temp = 0;
		arr[i].error = false;
		arr[i++].none = true;
	}
	return (arr);
}
