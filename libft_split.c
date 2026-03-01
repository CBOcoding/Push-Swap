/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:39:02 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 10:56:49 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	*copy_word(const char *str, int len)
{
	int		x;
	char	*word_copy;

	x = 0;
	word_copy = (char *)malloc((len + 1) * sizeof(char));
	if (word_copy == NULL)
		return (NULL);
	while (x < len)
	{
		word_copy[x] = str[x];
		x++;
	}
	word_copy[len] = '\0';
	return (word_copy);
}

static	int	count_words(char const *str, char c)
{
	int	word_count;

	word_count = 0;
	while (*str != '\0')
	{
		while (*str == c && *str != '\0')
		{
			str++;
		}
		if (*str != '\0')
		{
			word_count++;
			while (*str != c && *str != '\0')
			{
				str++;
			}
		}
	}
	return (word_count);
}

static	char	**free_pointers(char **returning_array, int x)
{
	while (x > 0)
		free(returning_array[--x]);
	free(returning_array);
	return (NULL);
}

static	char	**filling(char **returning_array, char const *str, char c)
{
	int	len;
	int	x;

	x = 0;
	while (*str != '\0')
	{
		while (*str == c && *str != '\0')
			str++;
		if (*str != '\0')
		{
			len = 0;
			while (*str != c && *str != '\0')
			{
				str++;
				len++;
			}
			returning_array[x] = copy_word(str - len, len);
			if (returning_array[x] == NULL)
				return (free_pointers(returning_array, x));
			x++;
		}
	}
	returning_array[x] = NULL;
	return (returning_array);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**returning_array;

	word_count = count_words(s, c);
	returning_array = (char **)malloc((word_count + 1) * sizeof(char *));
	if (returning_array == NULL)
		return (NULL);
	if (filling(returning_array, s, c) == NULL)
		return (NULL);
	return (returning_array);
}
