/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:28:52 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 14:33:47 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_checker(t_list **stack_a)
{
	int		size;
	t_list	*stack_b;

	size = ft_lstsize(*stack_a);
	stack_b = NULL;
	if (check_sort(stack_a, &stack_b) == 0)
		clear_exit(stack_a, &stack_b, EXIT_SUCCESS);
	else
	{
		if (size == 3)
			handle_3(stack_a);
		else if (size == 4)
			handle_4(stack_a, &stack_b);
		else if (size == 5)
			handle_5(stack_a, &stack_b);
		else
			algo_manager(stack_a, &stack_b);
		ft_lstclear(&stack_b, del);
	}
}

void	clear_exit(t_list **stack_a, t_list **stack_b, int exit_code)
{
	if (exit_code == EXIT_FAILURE)
		write(2, "Error\n", 6);
	ft_lstclear(stack_a, del);
	if (stack_b)
		ft_lstclear(stack_b, del);
	exit(exit_code);
}
