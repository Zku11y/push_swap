/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:17:06 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/17 18:21:22 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// Function to create a sorted array from stack
void index_list(t_list **stack_a)
{
	int i;
	t_list *iter;

	i = 1;
	iter = *stack_a;
	while(iter)
	{
		iter->index = i;
		iter = iter->next;
		i++;
	}
}
void index_null(t_list **stack)
{
    t_list *current;

	current = *stack;
    while (current)
    {
        current->index = -1;
        current = current->next;
    }
}
int *index_arr(t_list **stack)
{
	t_list *tmp;
	int size;
	int *arr;
	int i;

	size = ft_lstsize(*stack);
	tmp = *stack;
	i = 0;
	arr = malloc(sizeof(int) * size);
	if(arr == NULL)
		return(NULL);
	while(i < size && tmp)
	{
		if(i == tmp->index && i < size)
		{
			arr[i] = tmp->number;
			tmp = *stack;
			i++;
		}
		else
			tmp = tmp->next;
	}
	return(arr);
}
void index_assign(t_list **stack)
{
    int size;
    int i;
    t_list *current;
    t_list *min;

    index_null(stack);
	size = ft_lstsize(*stack);
	current = *stack;
	i = 0;
	min = NULL;
    while (i < size)
    {
        min = NULL;
        current = *stack;
        while (current)
        {
            if (current->index == -1 && (!min || current->number < min->number))
                min = current;
            current = current->next;
        }
        if (min)
            min->index = i++;
    }
}

t_list *top_iter(t_list **stack, int *arr, int start, int finish)
{
	t_list *iter;
	int i;

	iter = *stack;
	while(iter->next)
	{
		i = start;
		while(i < finish)
		{
			// ft_printf("\e[1;33mTop : arr[%d] = %d, finish = %d, iter->nb = %d\e[0m\n", i, arr[i], finish, iter->number);
			if(arr[i] == iter->number && iter->index != -1)
				return(iter);
			i++;
		}
		iter = iter->next;
	}
	return(iter);
}
t_list *bottom_iter(t_list **stack, int *arr, int start, int finish)
{
	t_list *iter;
	int i;

	iter = *stack;
	while(iter->next)
		iter = iter->next;
	while(iter)
	{
		i = start;
		while(i < finish)
		{
			if(arr[i] == iter->number && iter->index != -1)
				return(iter);
			i++;
		}
		iter = iter->prev;
	}
	return(iter);
}
void rotate_and_push(t_list **stack_a, t_list **stack_b, t_list *current)
{
	if (!current) return;

	if (top_or_bottom(stack_a, current) == 1)
	{
		while (current != *stack_a)
			rotate(stack_a, NULL, "a");
		push(stack_a, stack_b, "b");
	}
	else
	{
		while (current != *stack_a)
			rev_rotate(stack_a, NULL, "a");
		push(stack_a, stack_b, "b");
	}
}

// void rotate_and_push(t_list **stack_a, t_list **stack_b, t_list *current)
// {
// 	if(top_or_bottom(stack_a, current) == 1)
// 	{
// 		while(current != *stack_a)
// 			rotate(stack_a, NULL, "a");
// 		push(stack_a, stack_b, "b");
// 	}
// 	else
// 	{
// 		while(current != *stack_a)
// 			rev_rotate(stack_a, NULL, "a");
// 		push(stack_a, stack_b, "b");
// 	}
// }

// t_list *find_in_chunk(t_list **stack_a, t_list **stack_b, int *arr, int start, int finish)
// {
// 	int i;
// 	t_list *top;
// 	t_list *bottom;


// }

void chunk_manager(t_list **stack_a, t_list **stack_b, int *arr, int chunks, int chunk_size)
{
	int i;
	int j;
	t_list *top;
	t_list *bottom;
	int lst_size;

	lst_size = ft_lstsize(*stack_a);
	i = 0;
	while(i < chunks)
	{
		j = chunk_size * i;
		while(j < (chunk_size * i + chunk_size))
		{
			top = top_iter(stack_a, arr, chunk_size * i, chunk_size * i + chunk_size);
			bottom = bottom_iter(stack_a, arr, chunk_size * i, chunk_size * i + chunk_size);
			if(top->index > bottom->index)
			{
				rotate_and_push(stack_a, stack_b, top);
				top->index = -1;
			}
			else
			{
				rotate_and_push(stack_a, stack_b, bottom);
				bottom->index = -1;
			}
			j++;
		}
		i++;
	}
	if((lst_size - (chunks * chunk_size)) > 0)
	{
		j = chunk_size * i;
		while(j < lst_size)
		{
			top = top_iter(stack_a, arr, chunk_size * i, lst_size);
			bottom = bottom_iter(stack_a, arr, chunk_size * i, lst_size);
			if(top->index > bottom->index)
			{
				rotate_and_push(stack_a, stack_b, top);
				top->index = -1;
			}
			else
			{
				rotate_and_push(stack_a, stack_b, bottom);
				bottom->index = -1;
			}
			j++;
		}
	}
}


	// lst_size = ft_lstsize(*stack_a);
	// i = 0;
	// while(i < chunks)
	// {
	// 	j = 0;
	// 	while (j < chunk_size)
	// 	{
	// 		top = top_iter(stack_a, arr, i * chunk_size, chunk_size, lst_size);
	// 		bottom = bottom_iter(stack_a, arr, i * chunk_size, chunk_size, lst_size);

	// 		if (!top)
	// 		{
	// 			if (bottom)
	// 				rotate_and_push(stack_a, stack_b, bottom);
	// 			else
	// 				break;
	// 		}
	// 		else if (!bottom)
	// 		{
	// 			if (top)
	// 				rotate_and_push(stack_a, stack_b, top);
	// 			else
	// 				break;
	// 		}
	// 		else if (top->index < (lst_size - bottom->index))
	// 		{
	// 			rotate_and_push(stack_a, stack_b, top);
	// 		}
	// 		else
	// 		{
	// 			rotate_and_push(stack_a, stack_b, bottom);
	// 		}

	// 		index_list(stack_a);
	// 		index_list(stack_b);
	// 		j++;
	// 	}
	// 	i++;
	// 	// while(j < chunk_size)
	// 	// {
	// 	// 	top = top_iter(stack_a, arr, i * chunk_size, chunk_size, lst_size);
	// 	// 	bottom = bottom_iter(stack_a, arr, i * chunk_size, chunk_size, lst_size);
	// 	// 	if(top->index < (lst_size - bottom->index))
	// 	// 		rotate_and_push(stack_a, stack_b, top);
	// 	// 	else
	// 	// 		rotate_and_push(stack_a, stack_b, bottom);
	// 	// 	index_list(stack_a);
	// 	// 	index_list(stack_b);
	// 	// 	j++;
	// 	// }
	// }

void	rot_stack_2(t_list **stack, t_list *n, char name)
{
	t_list	*current;
	int		pos;
	int		size;

	current = *stack;
	size = ft_lstsize(*stack);
	pos = 1;
	while (current && current != n)
	{
		pos++;
		current = current->next;
	}
	rot_and_rev(pos, size, stack, name);
}
void final_push(t_list **stack_a, t_list **stack_b)
{
	int i;
	int size;
	t_list *biggest;
	t_list *equiv;

	i = 0;
	size = ft_lstsize(*stack_b);
	while(i < size)
	{
		biggest = find_biggest_nb(stack_b);
		equiv = a_position(stack_a, biggest);
		rot_stack_2(stack_b, biggest, 'b');
		rot_stack_2(stack_a, equiv, 'a');
		push(stack_b, stack_a, "a");
		i++;
	}
	rot_stack(stack_a, false, 'a');
}

void better_algo(t_list **stack_a, t_list **stack_b)
{
	int *arr;
	t_list *tmp;
	int chunk_size;
	int chunks;

	chunks = 11;
	chunk_size = ft_lstsize(*stack_a) / chunks;
	index_assign(stack_a);
	tmp = *stack_a;
	arr = index_arr(stack_a);
	index_list(stack_a);
	chunk_manager(stack_a, stack_b, arr, chunks, chunk_size);
	// final_push(stack_a, stack_b);
	best_move(stack_a, stack_b, chunks, chunk_size);
	// algo_manager(stack_a, stack_b);
}

void best_move(t_list **stack_a, t_list **stack_b, int chunks, int chunk_size)
{
	int i;
	int j;
	int size;
	t_list *cheapest_a;
	t_list *cheapest_b;

	i = 0;
	size = ft_lstsize(*stack_b);
	push(stack_b, stack_a, "a");
	push(stack_b, stack_a, "a");
	if ((*stack_a)->number > (*stack_a)->next->number)
		rotate(stack_a, stack_b, "a");
	while(i < chunks)
	{
		j = 0;
		while(j < chunk_size)
		{
			cheapest_b = cheapest_manager_2(stack_a, stack_b);
			cheapest_a = b_position(stack_a, cheapest_b->number);
			apply_moves(stack_b, stack_a, cheapest_b, "b");
			apply_moves(stack_a, stack_b, cheapest_a, "a");
			push(stack_b, stack_a, "a");
			j++;
		}
		rot_stack(stack_a, false, 'a'); // might need to change rot stack to take string instead of char
		i++;
	}
	i = ft_lstsize(*stack_b);
	if((chunks * i - i) > 0)
	{
		j = 0;
		while(j < (chunks * i - i))
		{
			cheapest_b = cheapest_manager_2(stack_a, stack_b);
			cheapest_a = b_position(stack_a, cheapest_b->number);
			apply_moves(stack_b, stack_a, cheapest_b, "b");
			apply_moves(stack_a, stack_b, cheapest_a, "a");
			push(stack_b, stack_a, "a");
			j++;
		}
		rot_stack(stack_a, false, 'a'); // might need to change rot stack to take string instead of char
	} 
}
// void	algo_manager(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*cheapest_a;
// 	t_list	*cheapest_b;
// 	int size;
// 	int chunk_size;

// 	size = ft_lstsize(*stack_b);
// 	// index_list(stack_a);
// 	// lst_print(*stack_a);
// 	// push(stack_b, stack_a, "a");
// 	// push(stack_b, stack_a, "a");
// 	// if ((*stack_a)->number > (*stack_a)->next->number)
// 	// 	rotate(stack_a, stack_b, "a");
// 	// while ((*stack_b))
// 	// {
		// cheapest_b = cheapest_manager(stack_b, stack_a);
// 	// 	cheapest_a = b_position(stack_a, cheapest_b->number);
// 	// 	apply_moves(stack_b, stack_a, cheapest_b, "b");
// 	// 	apply_moves(stack_a, stack_b, cheapest_a, "a");
// 	// 	push(stack_b, stack_a, "a");
// 	// }
// 	// while ((*stack_b))
// 	// 	push(stack_b, stack_a, "a");
// 	// rot_stack(stack_a, true, 'a');
// }
// void	algo_manager(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*cheapest_a;
// 	t_list	*cheapest_b;

// 	index_list(stack_a);
// 	// lst_print(*stack_a);
// 	push(stack_a, stack_b, "b");
// 	push(stack_a, stack_b, "b");
// 	if ((*stack_b)->number < (*stack_b)->next->number)
// 		rotate(stack_b, stack_a, "b");
// 	while ((*stack_a))
// 	{
// 		cheapest_a = cheapest_manager(stack_a, stack_b);
// 		cheapest_b = b_position(stack_b, cheapest_a->number);
// 		apply_moves(stack_a, stack_b, cheapest_a, "a");
// 		apply_moves(stack_b, stack_a, cheapest_b, "b");
// 		push(stack_a, stack_b, "b");
// 	}
// 	while ((*stack_b))
// 		push(stack_b, stack_a, "a");
// 	rot_stack(stack_a, true, 'a');
// }
