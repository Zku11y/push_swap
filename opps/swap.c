/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:10:20 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/06 12:22:04 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void swap(t_list **stack, t_list **stack_b, char *name)
{
    int tmp;
    t_list *head;
    int fd;

    if(!stack || !(*stack) || !((*stack)->next))
        return;
    head = *stack;
    tmp = head->number;
    head->number = (head->next)->number;
    (head->next)->number = tmp;
    fd = open("./opps/operations.txt", O_RDWR | O_CREAT | O_APPEND);
    if (fd == -1)
        return(ft_printf("\e[1;31mopen file error...\e[0m\n"), clear_exit(stack, stack_b, EXIT_FAILURE));
    write(fd, "s", 1);
    write(fd, name, 1);
    write(fd, "\n", 1);
    // ft_printf("s%s\n", name);
    close(fd);
}
