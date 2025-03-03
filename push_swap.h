/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:34:11 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/03 12:52:36 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdbool.h>

void    del(void *content);
int     num_check(char *str);
void    swap(t_list **stack);
void    rot_stack(t_list **stack, bool min);
void    check_dup(t_list **stack);
int     check_sort(t_list **stack);
int     ft_atoi_mod(const char *str);
int     skip_space(int i, char *str);
void    prev_assign(t_list **stack);
t_list  *ft_lstnew_mod(int number);
void    lst_print(t_list *head);
int     skip_numbers(int i, char *str);
void    algo_manager(t_list **stack_a);
int     check_rev_sort(t_list **stack);
void    rotate(t_list **stack, char name);
t_list  *find_biggest_nb(t_list **stack);
t_list  *find_smallest_nb(t_list **stack);
void    rev_rotate(t_list **stack, char name);
void    clear_exit(t_list **stack, int exit_code);
int     assign_manager(char *str, t_list **stack_a);
#endif
