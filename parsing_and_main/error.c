/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:38:43 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/07 13:12:05 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del(void *content)
{
	free(content);
}
void	ft_error(t_list *stack_a, t_list *stack_b)
{
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
	write(1, "\e[1;31mError\e[0m", 17);
	exit(EXIT_FAILURE);
}
