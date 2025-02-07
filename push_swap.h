/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:34:11 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/07 13:44:09 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct two_ints
{
	int	a;
	int	b;
}		t_ints;

void	ft_error(t_list *stack_a, t_list *stack_b);
t_ints	ft_atoi_ps(const char *str, int i);
int		parsing(int ac, char **av, t_list **stack_a, t_list **stack_b);
#endif
