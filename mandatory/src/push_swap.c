/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:07:02 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 16:02:07 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	leak_ts(void)
{
	system("leaks -q push_swap");
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*stack_a;

	i = 1;
	stack_a = NULL;
	if (ac == 1)
		return (0);
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
	sort_checker(&stack_a);
	ft_lstclear(&stack_a, del);
	return (0);
}
