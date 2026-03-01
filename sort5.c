/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:08:59 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 13:33:42 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_smallest_index(int *stack, int size);

void	sort_5(t_data *data)
{
	char	exit_flag;
	int		smallest_index;

	allocate_stack_b(data);
	exit_flag = 'n';
	while (data->size_a > 3)
	{
		smallest_index = find_smallest_index(data->stack_a, data->size_a);
		if (smallest_index < data->size_a / 2)
			while (smallest_index-- > 0)
				rotate(data->stack_a, data->size_a, 'a');
		else
			while (smallest_index++ < data->size_a)
				reverse_rotate(data->stack_a, data->size_a, 'a');
		push_to_b(data);
	}
	sort_3(data, exit_flag);
	while (data->size_b > 0)
		push_to_a(data);
	success_free_exit(data);
}

int	find_smallest_index(int *stack, int size)
{
	int	i;
	int	smallest;
	int	index;

	i = 1;
	smallest = stack[0];
	index = 0;
	while (i < size)
	{
		if (stack[i] < smallest)
		{
			smallest = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}
