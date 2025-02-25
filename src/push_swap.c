/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:07:02 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/25 18:12:57 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void leak_ts(void)
{
    system("leaks push_swap");
}

int main(int ac, char **av)
{
    int i;
    t_list *stack_a;
    t_list *stack_b;

    atexit(leak_ts);
    i = 1;
    stack_a = NULL;
    stack_b = NULL;
    while (i < ac)
    {
        num_check(av[i]);
        assign_manager(av[i], &stack_a, &stack_b);
        ft_printf("av[i] = %s\n", av[i]);
        i++;
    }
    return 0;
}
