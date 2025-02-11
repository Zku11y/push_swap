/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:34:11 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/11 13:42:57 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdbool.h>

# define NONE 2147483649

void	check_leaks(void);
void    lst_print(t_list *head);
t_ints	*arr_assign(int args);
void	ft_error(t_list *stack);
void	swap(t_list **stack, char *op);
void	ft_lstclear_nodes(t_list **lst);
void	rotate(t_list **stack, char *op);
t_ints	ft_atoi_ps(const char *str, int i);
void	dup_check(int args, t_list **stack_a);
void	reverse_rotate(t_list **stack, char *op);
int		parsing(int ac, char **av, t_list **stack_a);
int		assign_stack(t_list **stack_a, t_ints content);
void push(t_list **stack_a, t_list **stack_b, char *op);
#endif
