/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:19:53 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 14:37:37 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	check_empty(char *str)
{
	int	i;

	i = skip_space(0, str);
	if (str[i] == '\0')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

int	num_check(char *str)
{
	int	i;

	i = 0;
	check_empty(str);
	while (str[i])
	{
		i = skip_space(i, str);
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (!ft_isdigit(str[i]))
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
		}
		i = skip_numbers(i, str);
		if ((str[i] != '\0') && (str[i] != ' '))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

int	skip_space(int i, char *str)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

int	skip_numbers(int i, char *str)
{
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}
