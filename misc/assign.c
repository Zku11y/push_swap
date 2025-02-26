/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:30:21 by mdakni            #+#    #+#             */
/*   Updated: 2025/02/26 15:31:51 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void del(void *content)
{
    content = NULL;
}

int assign_manager(char *str, t_list **stack_a, t_list **stack_b)
{
    int i;
    int num;
    t_list *tmp;

    i = 0;
    *stack_b = NULL;
    while (str[i])
    {
        i = skip_space(i, str);
		if (!str[i])
			break;
		num = ft_atoi_mod(str + i);
		tmp = ft_lstnew_mod(num);
        if(tmp == NULL)
        {
            ft_lstclear(stack_a, del);
            exit(EXIT_FAILURE);
        }
        ft_lstadd_back(stack_a, tmp);
        i = skip_numbers(i, str);
    }
    return 0;
}

int	ft_atoi_mod(const char *str)
{
	int			i;
	long long	answer;
	int			sign;

	i = 0;
	answer = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
		answer = (answer * 10) + (str[i++] - '0');
	if (answer > INT_MAX || (answer * sign) < INT_MIN)
        exit(EXIT_FAILURE);
    return ((int)(answer * sign));
}
t_list	*ft_lstnew_mod(int number)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->number = number;
	ptr->next = NULL;
	return (ptr);
}