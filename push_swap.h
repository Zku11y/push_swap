/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:34:11 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/09 10:42:41 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdbool.h>

# define NONE 2147483649

void	del(void *content);
void	swap(t_list **stack);
t_ints	*arr_assign(int args);
void	rotate(t_list **stack);
void	ft_error(t_list *stack);
void	reverse_rotate(t_list **stack);
t_ints	ft_atoi_ps(const char *str, int i);
void	dup_check(int args, t_list **stack_a);
void	push(t_list **stack_a, t_list **stack_b);
int		parsing(int ac, char **av, t_list **stack_a);
int		assign_stack(t_list **head, t_list **stack_a, t_ints content);
#endif
