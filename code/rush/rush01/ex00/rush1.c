/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:19:58 by khassan           #+#    #+#             */
/*   Updated: 2025/07/13 21:47:47 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_support.h"

int	can_place_digit(int **res_array, int row, int col, int digit_to_place)
{
	int	i;

	i = 0;
	while (i < MAX_VAL)
	{
		if (res_array[row][i] == digit_to_place
			|| res_array[i][col] == digit_to_place)
			return (0);
		i++;
	}
	return (1);
}

int	solve_grid(int **res_array, int **input_array, int row, int col)
{
	int	value;
	int	next_row;
	int	next_col;

	if (row == MAX_VAL)
		return (check_all_input_vals(res_array, input_array));
	value = 1;
	while (value <= MAX_VAL)
	{
		if (can_place_digit(res_array, row, col, value))
		{
			res_array[row][col] = value;
			if (col + 1 == MAX_VAL)
				next_row = row + 1;
			else
				next_row = row;
			next_col = (col + 1) % MAX_VAL;
			if (solve_grid(res_array, input_array, next_row, next_col))
				return (1);
			res_array[row][col] = 0;
		}
		value++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	**input_str_array;
	int	**resultant_array;
	int	i;

	if (argc != 2 || !check_input_validity(argv[1]))
	{
		ft_putstr("Error\n");
		return (1);
	}
	input_str_array = split_input(argv[1]);
	resultant_array = allocate_array();
	if (solve_grid(resultant_array, input_str_array, 0, 0))
		print_result_array(resultant_array);
	else
		ft_putstr("Error : No Solution Found\n");
	i = 0;
	while (i < MAX_VAL)
	{
		free(input_str_array[i]);
		free(resultant_array[i]);
		i++;
	}
	free(input_str_array);
	free(resultant_array);
	return (0);
}
