/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:55:09 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/21 15:51:09 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../includes/libft/libft.h"
# include "../includes/printf/ft_printf.h"

// Operation functions
void	swap(t_list **stack, char *name);
void	rotate(t_list **stack, char *name);
void	rev_rotate(t_list **stack, char *name);
void	push(t_list **from, t_list **to, char *name);

// checker functions
int		num_check(char *str);
void	check_dup(t_list **stack);
void	read_input(t_list **stack_a, t_list **stack_b);
void	checker_sorted(t_list **stack_a, t_list **stack_b);

// misc functions
void	del(void *content);
t_list	*ft_lstnew_mod(int number);
void	prev_assign(t_list **stack);
int		skip_space(int i, char *str);
int		skip_numbers(int i, char *str);
int		assign_manager(char *str, t_list **stack_a);
int		ft_atoi_mod(const char *str, t_list **stack_a);
void	clear_exit(t_list **stack_a, t_list **stack_b, int exit_code);
#endif
