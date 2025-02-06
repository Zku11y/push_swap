/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:34:55 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/06 14:59:46 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

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
	while ((**str >= '0' && **str <= '9') && (**str != '\0'))
	{
		if (answer > INT_MAX || (**str < 0 && **str > 9) || !**str)
			return (2147483648);
		answer = (answer * 10) + (**str - '0');
		(*str)++;
	}
	printf("\e[1;34mptr inside ft_atoi_long = %d\e[0m\n", **str);
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

int	arg_num(int ac, char **av)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = 0;
	while (i <= ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			while ((av[i][j] == ' ') || (av[i][j] >= 9 && av[i][j] <= 13))
				j++;
			if (av[i][j])
			{
				size++;
				while ((av[i][j] != ' ') && (av[i][j] < 9 || av[i][j] > 13)
					&& (av[i][j] != '\0'))
					printf("number of arguments is = %c\n", av[i][j++]);
			}
		}
		i++;
	}
	return (size);
}

int	error_check(int ac, char **av, t_stack **stack_a, t_stack **stack_b)
{
	int			i;
	long long	tmp;
	char		*ptr;
	int			*arr;

	i = 1;
	ac = arg_num(ac, av);
	printf("ac = %d\n", ac);
	arr = ft_calloc(ac, sizeof(int));
	while (i < ac)
	{
		ptr = av[i++];
		while ((*ptr) != '\0')
		{
			printf("problem position 1, also heres ptr = %s\n", ptr);
			tmp = ft_atoi_long(&ptr);
			printf("tmp = %lld, ptr = %s\n", tmp, ptr);
			printf("problem position 2, also heres ptr = %s\n", ptr);
			if (tmp > INT_MAX || tmp < INT_MIN)
			{
				write(1, "\033[1;31mErrorsuka\033[0m\n", 17);
				return (-1);
			}
			printf("tmp 2 = %d\n", (int)tmp);
			ft_lstadd_back(stack_a, ft_lstnew((int)tmp));
			ft_lstadd_back(stack_b, ft_lstnew(0));
		}
	}
	return (0);
}
