/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:37:40 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 14:44:14 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	long_check(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	if (i > 11)
	{
		return (1);
	}
	return (0);
}

long	ft_atoi(const char *str, t_data *data)
{
	int		i;
	int		sign;
	long	number;
	long	result;

	i = 0;
	sign = 1;
	number = 0;
	if (1 == long_check(str))
		error_free_exit(data);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	result = (number * sign);
	return (result);
}
