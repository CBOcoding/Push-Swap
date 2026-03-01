/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:18:11 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 15:03:38 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free_exit(t_data *data)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	if (data->arguments)
	{
		while (data->arguments[i])
		{
			free(data->arguments[i]);
			i++;
		}
		free(data->arguments);
	}
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
	exit (EXIT_FAILURE);
}

void	success_free_exit(t_data *data)
{
	int	i;

	i = 0;
	if (data->arguments)
	{
		while (data->arguments[i])
		{
			free(data->arguments[i]);
			i++;
		}
		free(data->arguments);
	}
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
	exit (EXIT_SUCCESS);
}
