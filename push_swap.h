/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:34:11 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/27 16:07:11 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdbool.h>

void del(void *content);
int num_check(char *str);
void swap(t_list **stack);
// void rev_stack(t_list **stack);
void rev_rotate(t_list **stack);
void check_sort(t_list **stack);
int ft_atoi_mod(const char *str);
int skip_space(int i, char *str);
void prev_assign(t_list **stack);
t_list *ft_lstnew_mod(int number);
int skip_numbers(int i, char *str);
void algo_manager(t_list **stack_a);
void check_rev_sort(t_list **stack);
void rotate(t_list **stack);
int assign_manager(char *str, t_list **stack_a);
#endif
