/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_instead_of_two_ops.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:23:27 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/07 19:57:00 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

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
    i = 0;
    while(arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void arr_fill(t_list **stack_a, t_list **stack_b ,int fd, int size)
{
    char *str;
    char **arr;
    int i;

    i = 0;
    arr = malloc(sizeof(char *) * (size + 1));
    if (!arr)
        clear_exit(stack_a, stack_b, EXIT_FAILURE);
    str = get_next_line(fd);
    while(str)
    {
        arr[i] = ft_strdup(str);
        free(str);
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
        free(str);
        str = get_next_line(fd);
    }    
    close(fd);
    fd = open("./opps/operations.txt", O_RDONLY);
    if (fd == -1)
        return (clear_exit(stack_a, stack_b, EXIT_FAILURE));
    arr_fill(stack_a, stack_b, fd, size);
    close(fd);
}
