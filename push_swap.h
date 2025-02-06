/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:08:16 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/05 20:59:19 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_list
{
	int					content;
	struct stack_list	*next;
}						t_stack;

void					ft_lstadd_back(t_stack **lst, t_stack *new);
void					ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack					*ft_lstlast(t_stack *lst);
t_stack					*ft_lstnew(int content);
int						ft_lstsize(t_stack *lst);
int						error_check(int ac, char **av, t_stack **stack_a,
							t_stack **stack_b);
long					ft_atoi_long(char **str);
#endif