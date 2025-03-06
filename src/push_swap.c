/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:07:02 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/06 12:39:33 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void leak_ts(void)
{
    system("leaks push_swap");
}

void	lst_print(t_list *head)
{
	int	data;
	int	size;

	size = 0;
	if (!head)
		ft_printf("\033[1;31mhead 5awi a zmr\033[0m\n");
	while (head)
	{
		size++;
		data = head->number;
		if (data == 0)
			ft_printf("\033[1;31m%d\033[0m", 0);
		else if (data < 0)
			ft_printf("\033[3;1;36m%d\033[0m", data);
		else
			ft_printf("\033[1;34m%d\033[0m", data);
		ft_printf("\033[1;37m -> \033[0m");
		head = head->next;
	}
	ft_printf("\033[1;35mNULL\033[0m");
	ft_printf("\033[1;33m %d\033[0m\n", size);
}

int main(int ac, char **av)
{
    int i;
    t_list *stack_a;

    // atexit(leak_ts);
    i = 1;
    stack_a = NULL;
    while (i < ac)
    {
        num_check(av[i]);
        assign_manager(av[i], &stack_a);
        i++;
    }
	check_dup(&stack_a);
	prev_assign(&stack_a);
	sort_checker(&stack_a);
	ft_lstclear(&stack_a, del);
	return 0;
}
