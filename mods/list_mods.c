/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mods.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:49:28 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/27 13:02:59 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew_mod(int number)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->number = number;
	ptr->next = NULL;
	return (ptr);
}
int	ft_atoi_mod(const char *str)
{
	int			i;
	long long	answer;
	int			sign;

	i = 0;
	answer = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
		answer = (answer * 10) + (str[i++] - '0');
	if ((answer * sign) > INT_MAX || (answer * sign) < INT_MIN)
    {
		ft_printf("\e[1;41mNumber out of range of int! sign = %d\e[0m\n", sign);
		exit(EXIT_FAILURE);
	}
    return ((int)(answer * sign));
}
