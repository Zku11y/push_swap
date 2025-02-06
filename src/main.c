/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:16:40 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/06 14:05:18 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	// stack_a = malloc(sizeof(t_stack));
	// stack_b = malloc(sizeof(t_stack));
	// if (stack_a == NULL || stack_b == NULL)
	// {
	// 	write(1, "\033[1;31mError1\033[0m\n", 17);
	// 	return (0);
	// }
	if (error_check(ac - 1, av, &stack_a, &stack_b) == -1)
	{
		write(1, "\033[1;31mError2\033[0m\n", 17);
		return (0);
	}
	write(1, "\e[1;32mSuccess!\e[0m\n", 21);
	ft_printf("\e[1;33mstack a size = %d, stack b size = %d\e[0m\n",
		ft_lstsize(stack_a), ft_lstsize(stack_b));
	return (0);
}

// ft_lstiter(stack_a, print_content);
// In case of error,
// it must display "Error" followed by a ’\n’ on the standard error.
// Errors: some arguments aren’t integers,some arguments are
// bigger than an integer and/or there are duplicates
// ft_printf("%s\n", av[i]);