/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:02:55 by cborrome          #+#    #+#             */
/*   Updated: 2025/02/17 15:03:04 by cborrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_data
{
	char	**arguments;
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
}	t_data;

typedef struct s_move
{
	int	index;
	int	cost;
	int	target_index;
	int	moves_a;
	int	moves_b;
}	t_move;

void	input_validation(int argc, char **argv, t_data *data);
void	data_validation(t_data *data);
long	ft_atoi(const char *str, t_data *data);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
void	populate_stack_a(t_data *data);
void	allocate_stack_b(t_data *data);
void	error_free_exit(t_data *data);
void	success_free_exit(t_data *data);
int		initialize_sorting(t_data *data);
int		swap(int *x, int *y, char flag);
void	rotate(int *stack, int size, char flag);
void	reverse_rotate(int *stack, int size, char flag);
void	push_to_a(t_data *data);
void	push_to_b(t_data *data);
int		find_smallest_index(int *stack, int size);
void	sort_5(t_data *data);
void	sort_3(t_data *data, char exit_flag);
void	sort_big(t_data *data);
void	execute_cheapest_move(t_data *data, t_move *move);
void	reverse_rotate_both(t_data *data, t_move *move, int min_index);
void	reverse_rotate_a(t_data *data, t_move *move, int min_index);
void	reverse_rotate_b(t_data *data, t_move *move, int min_index);
void	rotate_both(t_data *data, t_move *move, int min_index);
void	rotate_a(t_data *data, t_move *move, int min_index);
void	rotate_b(t_data *data, t_move *move, int min_index);

#endif
