/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 19:28:12 by khassan           #+#    #+#             */
/*   Updated: 2025/07/13 21:47:25 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_support.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int num)
{
	char	num_to_print;

	num_to_print = num + '0';
	ft_putchar(num_to_print);
}

void	print_result_array(int **result_arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAX_VAL)
	{
		j = 0;
		while (j < MAX_VAL)
		{
			ft_putnbr(result_arr[i][j]);
			if (j != MAX_VAL - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	check_input_validity(char *input_str)
{
	int	len;
	int	i;

	len = ft_strlen(input_str);
	if (len != (MAX_VAL * 4 * 2 - 1))
		return (0);
	i = 0;
	while (i < len)
	{
		if (i % 2 == 0 && !((input_str[i] >= '1'
					&& input_str[i] <= (MAX_VAL + '0'))))
			return (0);
		if (i % 2 == 1 && input_str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
