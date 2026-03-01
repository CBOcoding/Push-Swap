/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:15:19 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 12:36:26 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_target_position(int *stack_a, int size_a, int number);
void	calculate_cost(t_data *data, t_move *move);
void	execute_cheapest_move(t_data *data, t_move *moves);

void	sort_big(t_data *data)
{
	t_move	*move;
	int		smallest_index;

	allocate_stack_b(data);
	move = (t_move *)malloc((data->size_a + data->size_b) * sizeof(t_move));
	if (!move)
		error_free_exit(data);
	while (data->size_a > 3)
		push_to_b(data);
	sort_3(data, 'n');
	while (data->size_b > 0)
	{
		calculate_cost(data, move);
		execute_cheapest_move(data, move);
	}
	smallest_index = find_smallest_index(data->stack_a, data->size_a);
	if (smallest_index < data->size_a / 2)
		while (smallest_index-- > 0)
			rotate(data->stack_a, data->size_a, 'a');
	else
		while (smallest_index++ < data->size_a)
			reverse_rotate(data->stack_a, data->size_a, 'a');
	free(move);
	success_free_exit(data);
}

void	calculate_cost(t_data *data, t_move *move)
{
	int	i;

	i = 0;
	while (i < data->size_b)
	{
		if (i >= data->size_b)
			break ;
		move[i].index = i;
		move[i].target_index = find_target_position(data->stack_a, \
			data->size_a, data->stack_b[i]);
		if (move[i].target_index < data->size_a / 2)
			move[i].moves_a = move[i].target_index;
		else
			move[i].moves_a = data->size_a - move[i].target_index;
		if (data->size_b == 1)
			move[i].moves_b = 0;
		else if (i < data->size_b / 2)
			move[i].moves_b = i;
		else
			move[i].moves_b = data->size_b - i;
		move[i].cost = move[i].moves_a + move[i].moves_b + 1;
		i++;
	}
}

int	find_small_index(int *stack_a, int size_a)
{
	int	i;
	int	smallest_index;

	smallest_index = 0;
	i = 1;
	while (i < size_a)
	{
		if (stack_a[i] < stack_a[smallest_index])
			smallest_index = i;
		i++;
	}
	return (smallest_index);
}

int	find_large_index(int *stack_a, int size_a)
{
	int	i;
	int	largest_index;

	largest_index = 0;
	i = 1;
	while (i < size_a)
	{
		if (stack_a[i] > stack_a[largest_index])
			largest_index = i;
		i++;
	}
	return (largest_index);
}

int	find_target_position(int *stack_a, int size_a, int number)
{
	int	i;
	int	target_index;
	int	smallest_index;
	int	largest_index;

	target_index = 0;
	smallest_index = 0;
	i = 1;
	smallest_index = find_small_index(stack_a, size_a);
	if (number < stack_a[smallest_index])
		return (smallest_index);
	largest_index = find_large_index(stack_a, size_a);
	if (number > stack_a[largest_index])
		return ((largest_index + 1) % size_a);
	i = 1;
	while (i < size_a)
	{
		if (stack_a[i] > number && stack_a[i - 1] < number)
		{
			target_index = i;
			break ;
		}
		i++;
	}
	return (target_index);
}
