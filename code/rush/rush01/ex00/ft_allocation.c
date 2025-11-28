/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:24:15 by khassan           #+#    #+#             */
/*   Updated: 2025/07/13 21:46:56 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_support.h"

int	**allocate_array(void)
{
	int	i;
	int	j;
	int	**arr;

	i = 0;
	arr = malloc(sizeof(int *) * MAX_VAL);
	while (i < MAX_VAL)
	{
		arr[i] = malloc(sizeof(int) * MAX_VAL);
		j = 0;
		while (j < MAX_VAL)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}

int	**split_input(char *str)
{
	int	**input_array;
	int	str_index;
	int	i;
	int	j;

	input_array = allocate_array();
	str_index = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			input_array[i][j] = str[str_index] - '0';
			str_index += 2;
			j++;
		}
		i++;
	}
	return (input_array);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
