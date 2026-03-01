/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 06:18:53 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 11:06:47 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(int *x, int *y, char flag)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
	if (flag == 'a')
		write(1, "sa\n", 3);
	return (0);
}
