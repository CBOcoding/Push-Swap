/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sorting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:39:21 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 10:56:26 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_data *data);
void	sort_3(t_data *data, char exit_flag);
void	order_check(t_data *data);

int	initialize_sorting(t_data *data)
{
	char	exit_flag;

	exit_flag = 'y';
	if (data->size_a == 1)
		success_free_exit(data);
	else if (data->size_a == 2)
		sort_2(data);
	else if (data->size_a == 3)
		sort_3(data, exit_flag);
	else if (data->size_a <= 5)
	{
		order_check(data);
		sort_5(data);
	}
	else
	{
		order_check (data);
		sort_big(data);
	}
	return (EXIT_SUCCESS);
}

void	sort_2(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[1])
	{
		swap(&data->stack_a[0], &data->stack_a[1], 'a');
		success_free_exit(data);
	}
	else
		success_free_exit(data);
}

void	sort_3(t_data *data, char exit_flag)
{
	if (data->stack_a[0] > data->stack_a[1] && \
		data->stack_a[0] > data->stack_a[2])
	{
		rotate(data->stack_a, data->size_a, 'a');
	}
	if (data->stack_a[1] > data->stack_a[0] && \
		data->stack_a[1] > data->stack_a[2])
	{
		reverse_rotate(data->stack_a, data->size_a, 'a');
	}
	if (data->stack_a[0] > data->stack_a[1])
	{
		swap(&data->stack_a[0], &data->stack_a[1], 'a');
	}
	if (exit_flag == 'y')
		success_free_exit(data);
}

void	order_check(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			return ;
		i++;
	}
	success_free_exit(data);
}
