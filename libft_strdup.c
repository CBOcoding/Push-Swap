/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:54:45 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 15:08:00 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *source)
{
	int		x;
	char	*str;

	x = 0;
	str = (char *)source;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*ft_strdup(const char *s)
{
	char	*source;
	char	*source_copy;
	int		x;

	source = (char *)s;
	source_copy = (char *) malloc((ft_strlen(source) + 1) * sizeof(char));
	if (source_copy == NULL)
		return (NULL);
	x = 0;
	while (source[x] != '\0')
	{
		source_copy[x] = source[x];
		x++;
	}
	source_copy[x] = '\0';
	return (source_copy);
}
