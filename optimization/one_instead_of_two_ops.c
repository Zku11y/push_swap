/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_instead_of_two_ops.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:23:27 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/07 17:42:48 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

// int can_combine(char *op1, char *op2)
// {
//     if (op1[0] == 'r' && op2[0] == 'r' && 
//         ((op1[1] == 'a' && op2[1] == 'b') || (op1[1] == 'b' && op2[1] == 'a')) && 
//         op1[2] == '\n' && op2[2] == '\n')
//         return 1;       
//     if (op1[0] == 'r' && op1[1] == 'r' && op2[0] == 'r' && op2[1] == 'r' &&
//         ((op1[2] == 'a' && op2[2] == 'b') || (op1[2] == 'b' && op2[2] == 'a')) &&
//         op1[3] == '\n' && op2[3] == '\n')
//         return 2;
        
//     return 0;
// }

// void handle_ops(int result, char **op1, char **op2, int fd)
// {
//     if (result == 1)
//     {
//         ft_printf("rr\n");
//         free(*op1);
//         free(*op2);
//         *op1 = get_next_line(fd);
//     }
//     else if (result == 2)
//     {
//         ft_printf("rrr\n");
//         free(*op1);
//         free(*op2);
//         *op1 = get_next_line(fd);
//     }
//     else
//     {
//         ft_printf("%s", *op1);
//         free(*op1);
//         *op1 = *op2;
//     }
// }

// void process_ops_file(int fd)
// {
//     char *op1 = NULL;
//     char *op2 = NULL;
//     int result;
    
//     op1 = get_next_line(fd);
//     while (op1)
//     {
//         op2 = get_next_line(fd);
//         if (!op2)
//         {
//             ft_printf("%s", op1);
//             free(op1);
//             break;
//         }
        
//         result = can_combine(op1, op2);
//         handle_ops(result, &op1, &op2, fd);
//     }
// }
t_numbers check_print_2(char **arr, int i)
{
    t_numbers nums;

    nums.rra = 0;
    nums.rrb = 0;
    nums.ra = 0;
    nums.rb = 0;
    while(arr[i] && ft_strnstr(arr[i], "r", 1) != NULL)
    {
        if(arr[i][1] == 'a')
            nums.ra++;
        else if(arr[i][1] == 'b')
            nums.rb++;
        else if(arr[i][2] == 'a')
            nums.rra++;
        else if(arr[i][2] == 'b')
            nums.rrb++;
        i++;
    }
    return (nums);
}

void print_rr(t_numbers nums)
{
    int tmp;

    if(nums.rra > nums.rrb)
    {
        tmp = nums.rrb;
        while(tmp--)
            ft_printf("rrr\n");
        tmp = nums.rra - nums.rrb;
        while(tmp--)
            ft_printf("rra\n");
    }
    else if(nums.rra <= nums.rrb)
    {
        tmp = nums.rra;
        while(tmp--)
            ft_printf("rrr\n");
        tmp = nums.rrb - nums.rra;
        while(tmp--)
            ft_printf("rrb\n");
    }
}
int print_r(t_numbers nums)
{
    int tmp;

    if(nums.ra > nums.rb)
    {
        tmp = nums.rb;
        while(tmp--)
            ft_printf("rr\n");
        tmp = nums.ra - nums.rb;
        while(tmp--)
            ft_printf("ra\n");
    }
    else if(nums.ra <= nums.rb)
    {
        tmp = nums.ra;
        while(tmp--)
            ft_printf("rr\n");
        tmp = nums.rb - nums.ra;
        while(tmp--)
            ft_printf("rb\n");
    }
    print_rr(nums);
    tmp = nums.rra + nums.rrb + nums.ra + nums.rb;
    return(tmp);
}

void check_and_print(char **arr)
{
    int i;
    char *str;
    i = 0;

    while(arr[i])
    {
        str = ft_strnstr(arr[i], "r", 1);
        if(str == NULL)
        {
            ft_printf("%s", arr[i]);
            i++;
        }
        else
            i = i + print_r(check_print_2(arr, i));
    }
}

void arr_fill(t_list **stack_a, t_list **stack_b ,int fd, int size)
{
    char *str;
    char **arr;
    int i;

    i = 0;
    arr = malloc(sizeof(char *) * size);
    if (!arr)
        clear_exit(stack_a, stack_b, EXIT_FAILURE);
    str = get_next_line(fd);
    while(str)
    {
        arr[i] = ft_strdup(str);
        str = get_next_line(fd);
        i++;
    }
    arr[i] = NULL;
    check_and_print(arr);
}

void file_clear(t_list **stack_a, t_list **stack_b)
{
    int fd;
    int size;
    char *str;
    
    size = 0;
    fd = open("./opps/operations.txt", O_RDONLY);
    if (fd == -1)
        return (clear_exit(stack_a, stack_b, EXIT_FAILURE));
    str = get_next_line(fd);
    while(str)
    {
        size++;
        str = get_next_line(fd);
    }    
    close(fd);
    fd = open("./opps/operations.txt", O_RDONLY);
    if (fd == -1)
        return (clear_exit(stack_a, stack_b, EXIT_FAILURE));
    arr_fill(stack_a, stack_b, fd, size);
    // process_ops_file(fd);
    close(fd);
}
