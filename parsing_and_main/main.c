/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:34:43 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/11 00:40:17 by mdakni           ###   ########.fr       */
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
		data = head->nb.value;
		if (data == 0)
			ft_printf("\033[1;31m%d\033[0m", 0);
		else if (data < 0)
			ft_printf("\033[3;1;36m%d\033[0m", data);
		else
			ft_printf("\033[1;34m%d\033[0m", data);
		ft_printf("\033[1;37m -> \033[0m");
		head = head->next;
	}
	ft_printf("\033[1;35mNULL\033[0m");
	ft_printf("\033[1;33m %d\033[0m\n", size);
}

void	stack_b_list(t_list **stack_b, t_list **stack_a, int args)
{
	t_list	*head;
	t_ints	n;
	int		i;

	head = *stack_b;
	i = 0;
	n.value = 0;
	n.none = true;
	n.error = false;
	n.temp = 0;
	while (i < args)
	{
		if (assign_stack(stack_b, n) == -1)
		{
			ft_lstclear_nodes(stack_b);
			ft_lstclear_nodes(stack_a);
			ft_error(NULL);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		args;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	args = parsing(ac, av, &stack_a);
	ft_printf("args = %d, ac = %d\n", args, ac);
	if (ac <= 2 || args == -1 || stack_a == NULL)
	{
		ft_lstclear_nodes(&stack_a);
		ft_printf("\033[1;32mITS HERE FINALLY FOUND IT\033[0m");
		check_leaks();
		return (-1);
	}
	dup_check(args, &stack_a);
	// stack_b_list(&stack_b, &stack_a, args);
	// reverse_rotate(&stack_a, "rra");
	// ft_printf("\e[1;42mReverse Rotate :\e[0m\n");
	// lst_print(stack_a);
	// lst_print(stack_b);
	// rotate(&stack_a, "ra");
	// ft_printf("\e[1;43mRotate :\e[0m\n");
	// lst_print(stack_a);
	// lst_print(stack_b);
	// push(&stack_a, &stack_b, "pb");
	// ft_printf("\e[1;45mPush 1 :\e[0m\n");
	// lst_print(stack_a);
	// lst_print(stack_b);
	// push(&stack_a, &stack_b, "pb");
	// ft_printf("\e[1;45mPush 2 :\e[0m\n");
	// lst_print(stack_a);
	// lst_print(stack_b);
	// push(&stack_a, &stack_b, "pb");
	// ft_printf("\e[1;45mPush 3 :\e[0m\n");
	// lst_print(stack_a);
	// lst_print(stack_b);
	// ft_printf("\e[1;32mthe size of stack a is = \e[0m%d\n", args);
	// ft_printf("\e[1;32mthe size of stack b is = \e[0m%d\n", args);
	ft_lstclear_nodes(&stack_a);
	ft_lstclear_nodes(&stack_b);
	check_leaks();
	return (0);
}
