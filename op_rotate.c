/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 06:18:56 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/16 19:32:52 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *stack, int size, char flag)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
	if (flag == 'a')
		write(1, "ra\n", 3);
	if (flag == 'b')
		write(1, "rb\n", 3);
	if (flag == 'r')
		write(1, "rr\n", 3);
}

void	rotate_both(t_data *data, t_move *move, int min_index)
{
	rotate(data->stack_a, data->size_a, ' ');
	rotate(data->stack_b, data->size_b, 'r');
	move[min_index].moves_a--;
	move[min_index].moves_b--;
}

void	rotate_a(t_data *data, t_move *move, int min_index)
{
	rotate(data->stack_a, data->size_a, 'a');
	move[min_index].moves_a--;
}

void	rotate_b(t_data *data, t_move *move, int min_index)
{
	rotate(data->stack_b, data->size_b, 'b');
	move[min_index].moves_b--;
}
