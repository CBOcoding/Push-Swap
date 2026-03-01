/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:58:45 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 13:38:13 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_data(t_data *data)
{
	data->arguments = NULL;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	initialize_data(&data);
	input_validation(argc, argv, &data);
	data_validation(&data);
	initialize_sorting(&data);
	success_free_exit(&data);
}
