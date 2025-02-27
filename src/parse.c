/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:19:53 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/27 16:15:58 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



int	num_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
        i = skip_space(i, str);
        if (str[i] == '-' || str[i] == '+')
        {
            i++;
            if (!ft_isdigit(str[i]))
            {
                ft_printf("\e[1;3;44mSign Problem\e[0m");
                exit(EXIT_FAILURE);
            }
        }
        i = skip_numbers(i, str);
        if ((str[i] != '\0') && (str[i] != ' '))
        {
            ft_printf("\e[1;3;45mNot a Number, Space or End of String\e[0m");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
int skip_space(int i, char *str)
{
    while(str[i] == ' ')
        i++;
    return (i);
}

int skip_numbers(int i, char *str)
{
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    return (i);
}
