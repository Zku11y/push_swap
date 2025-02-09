/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:38:43 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/08 11:15:00 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del(void *content)
{
	free(content);
}
void	ft_error(t_list *stack)
{
	ft_lstclear(&stack, del);
	write(1, "\e[1;31mError\e[0m", 17);
	exit(EXIT_FAILURE);
}
