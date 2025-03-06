/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:34:11 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/06 14:25:30 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdbool.h>
# include <fcntl.h>

// Operation functions
void    rot_stack(t_list **stack, bool min);
void    push(t_list **from, t_list **to, char *name);
void    swap(t_list **stack, t_list **stack_b, char *name);
void    rotate(t_list **stack, t_list **stack_b,char *name);
void    rev_rotate(t_list **stack, t_list **stack_b, char *name);

// Small Algorithm functions
void    handle_3(t_list **stack);
void    handle_4(t_list **stack_a, t_list **stack_b);
void    handle_5(t_list **stack_a, t_list **stack_b);
int     assign_manager(char *str, t_list **stack_a);

// Big Algorithm functions (THE MOST IMPORTANT PART OF THE CODE)
void    algo_manager(t_list **stack_a, t_list **stack_b);
t_list  *cheapest_manager(t_list **stack_a, t_list **stack_b);
t_list  *b_position(t_list **stack_b, int a);
int     calc_moves(t_list **stack, t_list *current);
t_list  *find_cheapest(t_list **stack, int *arr);
void    apply_moves(t_list **s1, t_list **s2, t_list *num, char *n);
t_list  *small_or_big(t_list **stack_b, int a);

// checker functions
void    check_dup(t_list **stack);
int     num_check(char *str);
int     check_sort(t_list **stack, t_list **stack_b);
void    sort_checker(t_list **stack_a);
int     check_rev_sort(t_list **stack);

// misc functions
int     trunc_fd();
void    del(void *content);
void    lst_print(t_list *head);
t_list  *ft_lstnew_mod(int number);
void    prev_assign(t_list **stack);
int     ft_atoi_mod(const char *str);
int     skip_space(int i, char *str);
int     skip_numbers(int i, char *str);
t_list  *find_biggest_nb(t_list **stack);
t_list  *find_smallest_nb(t_list **stack);
void    file_clear(t_list **stack_a, t_list **stack_b);
void    clear_exit(t_list **stack_a, t_list **stack_b, int exit_code);

#endif
