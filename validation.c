/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:47:45 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/18 10:09:21 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_data_arguments(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	data->arguments = (char **)malloc(sizeof(char *) * (argc));
	if (!data->arguments)
		error_free_exit(data);
	while (i < argc - 1)
	{
		data->arguments[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	data->arguments[i] = NULL;
}

void	input_validation(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		exit (EXIT_FAILURE);
	if (argc == 2)
	{
		if (!argv [1][0])
			exit (EXIT_FAILURE);
		else
		{
			data->arguments = ft_split(argv[1], ' ');
			if (!data->arguments)
				error_free_exit(data);
			if (!data->arguments[0])
				success_free_exit(data);
		}
	}
	else
	{
		fill_data_arguments(data, argc, argv);
	}
}

void	character_sign_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->arguments[i])
	{
		j = 0;
		while (data->arguments[i][j])
		{
			if (!(data->arguments[i][j] == '-' || data->arguments[i][j] == '+'
			|| (data->arguments[i][j] >= '0' && data->arguments[i][j] <= '9')))
			{
				error_free_exit(data);
			}
			if ((data->arguments[i][j] == '-' || data->arguments[i][j] == '+')
				&& j != 0)
				error_free_exit(data);
			if ((data->arguments[i][j] == '-' || data->arguments[i][j] == '+')
				&& !(data->arguments[i][j + 1] >= '0'
				&& data->arguments[i][j + 1] <= '9'))
				error_free_exit(data);
			j++;
		}
		i++;
	}
}

int	duplicate_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size_a)
	{
		j = i + 1;
		while (j < data->size_a)
		{
			if (data->stack_a[i] == data->stack_a[j])
				error_free_exit(data);
			j++;
		}
		i++;
	}
	return (0);
}

void	data_validation(t_data *data)
{
	character_sign_check(data);
	populate_stack_a(data);
	duplicate_check(data);
}
