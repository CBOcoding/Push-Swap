/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 06:18:59 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 11:05:37 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *stack, int size, char flag)
{
	int	temp;
	int	i;

	i = size - 1;
	temp = stack[size - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
	if (flag == 'a')
		write(1, "rra\n", 4);
	if (flag == 'b')
		write(1, "rrb\n", 4);
	if (flag == 'R')
		write(1, "rrr\n", 4);
}

void	reverse_rotate_both(t_data *data, t_move *move, int min_index)
{
	reverse_rotate(data->stack_a, data->size_a, ' ');
	reverse_rotate(data->stack_b, data->size_b, 'R');
	move[min_index].moves_a--;
	move[min_index].moves_b--;
}

void	reverse_rotate_a(t_data *data, t_move *move, int min_index)
{
	reverse_rotate(data->stack_a, data->size_a, 'a');
	move[min_index].moves_a--;
}

void	reverse_rotate_b(t_data *data, t_move *move, int min_index)
{
	reverse_rotate(data->stack_b, data->size_b, 'b');
	move[min_index].moves_b--;
}
