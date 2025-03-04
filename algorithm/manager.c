/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:28:52 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/04 11:14:38 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_checker(t_list **stack_a)
{
    int check;
    int size;
    t_list *stack_b;

    size = ft_lstsize(*stack_a);
    stack_b = NULL;
    if (trunc_fd() == -1)
        clear_exit(stack_a, &stack_b, EXIT_FAILURE);
    check = check_sort(stack_a);
    if (check == 0)
    {
        file_clear(stack_a, &stack_b);
        clear_exit(stack_a, &stack_b, EXIT_SUCCESS);
    }
    else
    {
        if (size == 3)
            handle_3(stack_a);
        else if (size == 4)
            handle_4(stack_a, &stack_b);
        else if (size == 5)
            handle_5(stack_a, &stack_b);
        ft_lstclear(&stack_b, del);
    }
    file_clear(stack_a, &stack_b);
}
int trunc_fd()
{
    int fd;
    
    fd = open("./opps/operations.txt", O_RDONLY | O_TRUNC);
    if (fd == -1)
    {
        ft_printf("\e[1;31mopen file error...\e[0m\n");
        return (-1);
    }
    close(fd);
    return (0);
}
void clear_exit(t_list **stack_a, t_list **stack_b,int exit_code)
{
    ft_lstclear(stack_a, del);
    if (stack_b)
        ft_lstclear(stack_b, del);
    exit(exit_code);
}
void file_clear(t_list **stack_a, t_list **stack_b)
{
    int fd;
    char *str;
    char *str2;

    fd = open("./opps/operations.txt", O_RDWR | O_CREAT, 0777);
    if (fd == -1)
        return(ft_printf("\e[1;31mopen file error...\e[0m\n"), clear_exit(stack_a, stack_b, EXIT_FAILURE));
    str = get_next_line(fd);
    str2 = get_next_line(fd);
    if(str && !str2)
        ft_printf("%s", str);
    while (str && str2)
    {
        same_opps(str, str2);
        free(str);
        free(str2);
        str = get_next_line(fd);
        str2 = get_next_line(fd);
    }
    free(str);
    if(str2)
        free(str2);
    close(fd);
}
void same_opps(char *str1, char *str2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str1[i] == str2[i] && str1[i] && str2[i])
        i++;
    if (str1[i] == 'a' || str1[i] == 'b')
    {
        while(str1[j] != 'a' && str1[j] != 'b')
        {
            ft_printf("%c", str1[j]);
            j++;
        }
        ft_printf("%c\n", str1[j - 1]);
    }
    else
        ft_printf("%s%s", str1, str2);
}
