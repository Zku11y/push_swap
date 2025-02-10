/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:40 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/11 00:38:28 by mdakni           ###   ########.fr       */
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
		return (ft_lstclear_nodes(stack_a), ft_error(NULL));
	head = *stack_a;
	while (head)
	{
		i = 0;
		while (!(arr[i].none))
		{
			if (arr[i].value == head->nb.value)
				return (free(arr), ft_lstclear_nodes(stack_a), ft_error(NULL));
			i++;
		}
		arr[i] = head->nb;
		head = head->next;
	}
	free(arr);
}

int assign_stack(t_list **stack, t_ints content) {
    t_list *node = malloc(sizeof(t_list)); // Allocate memory
    if (!node) {
        // Handle allocation failure
        return (-1);
    }
    node->nb = content;
    node->next = NULL;
    // Add node to the stack
    if (*stack == NULL) {
        *stack = node;
    } else {
        t_list *current = *stack;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
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

	i = 1;
	size = 0;
	while (i < ac)
	{
		j = 0;
		if (check_empty(av[i]) == -1)
			return (ft_lstclear_nodes(stack_a), ft_error(NULL), -1);
		while (av[i][j])
		{
			tmp = ft_atoi_ps(av[i], j);
			if (tmp.error == true || assign_stack(stack_a, tmp) == -1)
				return (ft_lstclear_nodes(stack_a), ft_error(NULL), -1);
			size++;
			j = tmp.temp;
		}
		i++;
	}
	return (size);
}
