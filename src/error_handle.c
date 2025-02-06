/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:34:55 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/05 21:02:50 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atoi_long(char **str)
{
	long long	answer;
	int			sign;

	answer = 0;
	sign = 1;
	while ((**str == ' ') || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while ((**str >= '0' && **str <= '9'))
	{
		answer = (answer * 10) + (**str - '0');
		(*str)++;
	}
	if ((answer * sign) > INT_MAX || (**str < 0 && **str > 9) || !**str)
		return (2147483648);
	if ((answer * sign) < -2147483648)
		return (-2147483649);
	return ((answer * sign));
}

// int	handle_argument(char **str)
// {
// 	int		i;
// 	int		j;
// 	char	arr[12];

// 	i = 0;
// 	j = 0;
// 	while (*str)
// 	{
// 		if (str[i] != ' ' && str[i] != '\t' && (str[i] <= '0' || str[i] >= '9'))
// 		{
// 			write(1, "\e[1;31mError\e[0m\n", 18);
// 			return (-1);
// 		}
// 		else if (str[i] >= '0' && str[i] <= '9')
// 			arr[j++] = str[i];
// 		i++;
// 	}
// }

int	error_check(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
	int			i;
	long long	tmp;
	char		*ptr;

	i = 1;
	while (i <= ac)
	{
		ptr = av[i++];
		while (*ptr)
		{
			tmp = ft_atoi_long(&ptr);
			if (tmp > INT_MAX || tmp < INT_MIN)
			{
				write(1, "\033[1;31mErrorsuka\033[0m\n", 17);
				ft_printf("%d\n", (int)tmp);
				return (-1);
			}
			ft_lstadd_back(stack_a, ft_lstnew((int)tmp));
			ft_lstadd_back(stack_b, ft_lstnew(0));
		}
	}
	return (0);
}
