/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_instead_of_two_ops.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:23:27 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/06 14:25:17 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

int can_combine(char *op1, char *op2)
{
    if (op1[0] == 'r' && op2[0] == 'r' && 
        ((op1[1] == 'a' && op2[1] == 'b') || (op1[1] == 'b' && op2[1] == 'a')) && 
        op1[2] == '\n' && op2[2] == '\n')
        return 1;       
    if (op1[0] == 'r' && op1[1] == 'r' && op2[0] == 'r' && op2[1] == 'r' &&
        ((op1[2] == 'a' && op2[2] == 'b') || (op1[2] == 'b' && op2[2] == 'a')) &&
        op1[3] == '\n' && op2[3] == '\n')
        return 2;
        
    return 0;
}

void handle_ops(int result, char **op1, char **op2, int fd)
{
    if (result == 1)
    {
        ft_printf("rr\n");
        free(*op1);
        free(*op2);
        *op1 = get_next_line(fd);
    }
    else if (result == 2)
    {
        ft_printf("rrr\n");
        free(*op1);
        free(*op2);
        *op1 = get_next_line(fd);
    }
    else
    {
        ft_printf("%s", *op1);
        free(*op1);
        *op1 = *op2;
    }
}

void process_ops_file(int fd)
{
    char *op1 = NULL;
    char *op2 = NULL;
    int result;
    
    op1 = get_next_line(fd);
    while (op1)
    {
        op2 = get_next_line(fd);
        if (!op2)
        {
            ft_printf("%s", op1);
            free(op1);
            break;
        }
        
        result = can_combine(op1, op2);
        handle_ops(result, &op1, &op2, fd);
    }
}

void file_clear(t_list **stack_a, t_list **stack_b)
{
    int fd;
    
    fd = open("./opps/operations.txt", O_RDONLY);
    if (fd == -1)
        return (clear_exit(stack_a, stack_b, EXIT_FAILURE));
    
    process_ops_file(fd);
    close(fd);
}
