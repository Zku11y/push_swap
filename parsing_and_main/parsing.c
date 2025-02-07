/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:40 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/07 13:58:22 by mdakni           ###   ########.fr       */
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
		return (final.b = -1, final);
	final.a = (int)(answer * sign);
	final.b = i;
	return (final);
}

int	assign_stack(t_list **head, t_list **stack_a, int content)
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
int	parsing(int ac, char **av, t_list **stack_a, t_list **stack_b)
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
		while (av[i][j])
		{
			tmp = ft_atoi_ps(av[i], j);
			if (tmp.b == -1 || assign_stack(&head, stack_a, tmp.a) == -1)
				ft_error(*stack_a, *stack_b);
			size++;
			j = tmp.b;
		}
		i++;
	}
	return (size);
}
