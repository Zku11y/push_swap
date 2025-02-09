/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:40 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/09 10:31:11 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ints	ft_atoi_ps(const char *str, int i)
{
	long long	answer;
	int			sign;
	t_ints		final;

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
	if ((answer * sign) > INT_MAX || (answer * sign) < INT_MIN || (str[i] != ' '
			&& str[i] != '\0'))
		return (final.value = 0, final.none = true, final.error = true, final);
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (final.value = (int)(answer * sign), final.none = false,
		final.temp = i, final.error = false, final);
}

void	dup_check(int args, t_list **stack_a)
{
	int		i;
	t_list	*head;
	t_ints	*arr;

	arr = arr_assign(args);
	if (!arr)
		ft_error(*stack_a);
	head = *stack_a;
	while (head)
	{
		i = 0;
		while (!(arr[i].none))
		{
			if (arr[i].value == head->nb.value)
			{
				free(arr);
				ft_error(*stack_a);
			}
			i++;
		}
		arr[i] = head->nb;
		head = head->next;
	}
	free(arr);
}

int	assign_stack(t_list **head, t_list **stack_a, t_ints content)
{
	t_list	*node;

	node = ft_calloc(1, sizeof(t_list));
	if (node == NULL)
		return (-1);
	if (*stack_a == NULL)
	{
		node->nb = content;
		*stack_a = node;
		*head = *stack_a;
		return (0);
	}
	node->nb = content;
	node->next = NULL;
	(*head)->next = node;
	*head = node;
	return (0);
}
int	check_empty(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (-1);
	return (0);
}

int	parsing(int ac, char **av, t_list **stack_a)
{
	int		i;
	int		j;
	int		size;
	t_ints	tmp;
	t_list	*head;

	i = 1;
	size = 0;
	head = *stack_a;
	while (i < ac)
	{
		j = 0;
		if (check_empty(av[i]) == -1)
			ft_error(*stack_a);
		while (av[i][j])
		{
			tmp = ft_atoi_ps(av[i], j);
			if (tmp.error == true || assign_stack(&head, stack_a, tmp) == -1)
				ft_error(*stack_a);
			size++;
			j = tmp.temp;
		}
		i++;
	}
	return (size);
}
