/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:30:21 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 14:01:38 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	del(void *content)
{
	content = NULL;
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

int	assign_manager(char *str, t_list **stack_a)
{
	int		i;
	int		num;
	t_list	*tmp;

	i = 0;
	while (str[i])
	{
		i = skip_space(i, str);
		if (!str[i])
			break ;
		num = ft_atoi_mod(str + i, stack_a);
		tmp = ft_lstnew_mod(num);
		if (tmp == NULL)
			clear_exit(stack_a, NULL, EXIT_FAILURE);
		ft_lstadd_back(stack_a, tmp);
		i = skip_numbers(i, str);
	}
	return (0);
}
