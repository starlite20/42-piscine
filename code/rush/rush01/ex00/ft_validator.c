/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:24:04 by khassan           #+#    #+#             */
/*   Updated: 2025/07/13 21:42:13 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_support.h"

int	is_row_left_good(int **res_array, int **input, int row)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < MAX_VAL)
	{
		if (res_array[row][i] > max)
		{
			max = res_array[row][i];
			count++;
		}
		i++;
	}
	return (input[2][row] == count);
}

int	is_row_right_good(int **res_array, int **input, int row)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = MAX_VAL - 1;
	while (i >= 0)
	{
		if (res_array[row][i] > max)
		{
			max = res_array[row][i];
			count++;
		}
		i--;
	}
	return (input[3][row] == count);
}

int	is_col_up_good(int **res_array, int **input, int col)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < MAX_VAL)
	{
		if (res_array[i][col] > max)
		{
			max = res_array[i][col];
			count++;
		}
		i++;
	}
	return (input[0][col] == count);
}

int	is_col_down_good(int **res_array, int **input, int col)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = MAX_VAL - 1;
	while (i >= 0)
	{
		if (res_array[i][col] > max)
		{
			max = res_array[i][col];
			count++;
		}
		i--;
	}
	return (input[1][col] == count);
}

int	check_all_input_vals(int **res_array, int **input)
{
	int	i;

	i = 0;
	while (i < MAX_VAL)
	{
		if (!is_row_left_good(res_array, input, i)
			|| !is_row_right_good(res_array, input, i)
			|| !is_col_up_good(res_array, input, i)
			|| !is_col_down_good(res_array, input, i))
			return (0);
		i++;
	}
	return (1);
}
