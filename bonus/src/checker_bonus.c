/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:13:51 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 16:25:34 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	main(int ac, char **av)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	i = 1;
	if (ac == 1)
		return (0);
	stack_a = NULL;
	while (i < ac)
	{
		num_check(av[i]);
		assign_manager(av[i], &stack_a);
		i++;
	}
	if (ft_lstsize(stack_a) == 0)
		return (write(2, "Error\n", 6), ft_lstclear(&stack_a, del), 0);
	check_dup(&stack_a);
	prev_assign(&stack_a);
	read_input(&stack_a, &stack_b);
	clear_exit(&stack_a, &stack_b, EXIT_SUCCESS);
}

void	optimization(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strncmp(str, "rr\n", 3) == 0)
	{
		rotate(stack_a, NULL);
		if (*stack_b)
			rotate(stack_b, NULL);
	}
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
	{
		rev_rotate(stack_a, NULL);
		if (*stack_b)
			rev_rotate(stack_b, NULL);
	}
}

int	apply_move(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strncmp(str, "rr\n", 3) == 0 || ft_strncmp(str, "rrr\n", 4) == 0)
		optimization(stack_a, stack_b, str);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate(stack_a, NULL);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rev_rotate(stack_a, NULL);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate(stack_b, NULL);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rev_rotate(stack_b, NULL);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		swap(stack_a, NULL);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap(stack_b, NULL);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		push(stack_b, stack_a, NULL);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		push(stack_a, stack_b, NULL);
	else
		return (-1);
	return (0);
}

void	checker_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		tmp;

	current = *stack_a;
	tmp = current->number;
	while (current)
	{
		if (current->number < tmp)
		{
			ft_printf("KO\n");
			clear_exit(stack_a, stack_b, EXIT_SUCCESS);
		}
		tmp = current->number;
		current = current->next;
	}
	ft_printf("OK\n");
	clear_exit(stack_a, stack_b, EXIT_SUCCESS);
}

void	read_input(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (apply_move(stack_a, stack_b, str) == -1)
		{
			free(str);
			clear_exit(stack_a, stack_b, EXIT_FAILURE);
		}
		free(str);
		str = get_next_line(0);
	}
	if (*stack_b != NULL)
	{
		ft_printf("KO\n");
		clear_exit(stack_a, stack_b, EXIT_SUCCESS);
	}
	checker_sorted(stack_a, stack_b);
}
