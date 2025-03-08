/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:30:21 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/08 14:23:52 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void del(void *content)
{
    content = NULL;
}

int assign_manager(char *str, t_list **stack_a)
{
    int i;
    int num;
    t_list *tmp;

    i = 0;
    while (str[i])
    {
        i = skip_space(i, str);
		if (!str[i])
			break;
		num = ft_atoi_mod(str + i, stack_a);
		tmp = ft_lstnew_mod(num);
        if(tmp == NULL)
			clear_exit(stack_a, NULL, EXIT_FAILURE);
        ft_lstadd_back(stack_a, tmp);
        i = skip_numbers(i, str);
    }
    return 0;
}

void prev_assign(t_list **stack)
{
	t_list *iter;

	if(!stack || !(*stack) || !((*stack)->next))
		return;
	iter = *stack;
	iter->prev = NULL;
	(iter->next)->prev = iter;
	iter = iter->next;
	while (iter->next)
	{
		(iter->next)->prev = iter;
		iter = iter->next;
	}
}
