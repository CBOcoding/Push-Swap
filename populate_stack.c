/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:36:16 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 13:19:40 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_arguments(t_data *data)
{
	int	i;

	i = 0;
	while (data->arguments[i])
		i++;
	return (i);
}

void	populate_stack_a(t_data *data)
{
	int		i;
	long	number;

	i = 0;
	data->stack_a = (int *)malloc(num_arguments(data) * sizeof(int));
	if (!data->stack_a)
		error_free_exit(data);
	data->size_a = 0;
	while (data->arguments[i])
	{
		number = ft_atoi(data->arguments[i], data);
		if (number > INT_MAX || number < INT_MIN)
			error_free_exit(data);
		data->stack_a[i] = (int)number;
		data->size_a++;
		i++;
	}
}

void	allocate_stack_b(t_data *data)
{
	data->stack_b = (int *)malloc(num_arguments(data) * sizeof(int));
	if (!data->stack_b)
		error_free_exit(data);
	data->size_b = 0;
}

void	allocate_move(t_data *data, t_move *move)
{
	move = (t_move *)malloc((data->size_a + data->size_b) * sizeof(t_move));
	if (!move)
		error_free_exit(data);
}
