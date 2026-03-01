/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cheapest_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:32:22 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 11:04:06 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_1_above_half_size(t_data *data, t_move *move, int min_index);
void	case_2_lower_half_size(t_data *data, t_move *move, int min_index);
void	case_3_a_above_b_lower(t_data *data, t_move *move, int min_index);
void	case_4_a_lower_b_above(t_data *data, t_move *move, int min_index);

void	execute_cheapest_move(t_data *data, t_move *move)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i < data->size_b)
	{
		if (move[i].cost < move[min_index].cost)
			min_index = i;
		i++;
	}
	case_1_above_half_size(data, move, min_index);
	case_2_lower_half_size(data, move, min_index);
	case_3_a_above_b_lower(data, move, min_index);
	case_4_a_lower_b_above(data, move, min_index);
	push_to_a(data);
}

void	case_1_above_half_size(t_data *data, t_move *move, int min_index)
{
	if (move[min_index].target_index >= (data->size_a / 2) && \
		move[min_index].index >= (data->size_b / 2))
	{
		if (move[min_index].moves_a > move[min_index].moves_b)
		{
			while (move[min_index].moves_b > 0)
				reverse_rotate_both(data, move, min_index);
			while (move[min_index].moves_a > 0)
				reverse_rotate_a(data, move, min_index);
		}
		else if (move[min_index].moves_a < move[min_index].moves_b)
		{
			while (move[min_index].moves_a > 0)
				reverse_rotate_both(data, move, min_index);
			while (move[min_index].moves_b > 0)
				reverse_rotate_b(data, move, min_index);
		}
		else if (move[min_index].moves_a == move[min_index].moves_b)
		{
			while (move[min_index].moves_a > 0 && move[min_index].moves_b > 0)
				reverse_rotate_both(data, move, min_index);
		}
	}
}

void	case_2_lower_half_size(t_data *data, t_move *move, int min_index)
{
	if ((move[min_index].target_index < (data->size_a / 2) && \
		move[min_index].index < (data->size_b / 2)))
	{
		if (move[min_index].moves_a > move[min_index].moves_b)
		{
			while (move[min_index].moves_b > 0)
				rotate_both(data, move, min_index);
			while (move[min_index].moves_a > 0)
				rotate_a(data, move, min_index);
		}
		else if (move[min_index].moves_a < move[min_index].moves_b)
		{
			while (move[min_index].moves_a > 0)
				rotate_both(data, move, min_index);
			while (move[min_index].moves_b > 0)
				rotate_b(data, move, min_index);
		}
		else if (move[min_index].moves_a == move[min_index].moves_b)
		{
			while (move[min_index].moves_a > 0 && move[min_index].moves_b > 0)
				rotate_both(data, move, min_index);
		}
	}
}

void	case_3_a_above_b_lower(t_data *data, t_move *move, int min_index)
{
	if ((move[min_index].target_index >= (data->size_a / 2) && \
		move[min_index].index < (data->size_b / 2)))
	{
		while (move[min_index].moves_a > 0)
		{
			reverse_rotate(data->stack_a, data->size_a, 'a');
			move[min_index].moves_a--;
		}
		while (move[min_index].moves_b > 0)
		{
			rotate(data->stack_b, data->size_b, 'b');
			move[min_index].moves_b--;
		}
	}
}

void	case_4_a_lower_b_above(t_data *data, t_move *move, int min_index)
{
	if ((move[min_index].target_index < (data->size_a / 2) && \
		move[min_index].index >= (data->size_b / 2)))
	{
		while (move[min_index].moves_a > 0)
		{
			rotate(data->stack_a, data->size_a, 'a');
			move[min_index].moves_a--;
		}
		while (move[min_index].moves_b > 0)
		{
			reverse_rotate(data->stack_b, data->size_b, 'b');
			move[min_index].moves_b--;
		}
	}
}
