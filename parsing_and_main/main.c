/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:34:43 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/07 13:57:02 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("\e[1;33mcontent type shit %d\e[0m\n", current->nb);
		current = current->next;
	}
}

void	lst_print(t_list *head)
{
	int	data;
	int	size;

	size = 0;
	if (!head)
		ft_printf("\033[1;31mhead 5awi a zmr\033[0m\n");
	while (head)
	{
		size++;
		data = head->nb;
		if (data == 0)
			ft_printf("\033[1;31m%d\033[0m", 0);
		else
			ft_printf("\033[1;34m%d\033[0m", data);
		ft_printf("\033[1;37m->\033[0m");
		head = head->next;
	}
	ft_printf("\033[1;35mNULL\033[0m");
	ft_printf("\033[1;33m %d\033[0m\n", size);
}
int	main(int ac, char **av)
{
	t_list *stack_a;
	t_list *stack_b;
	int i;
	int args;

	if (ac < 2)
		return (-1);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	args = parsing(ac, av, &stack_a, &stack_b);
	lst_print(stack_a);
	// print_list(stack_a);
	// print_list(stack_b);
	ft_printf("\e[1;32mthe size of stack a is = \e[0m%d\n", args);
	ft_printf("\e[1;32mthe size of stack b is = \e[0m%d\n", args);

	return (0);
}