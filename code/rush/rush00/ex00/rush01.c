/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:53:58 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/06 17:08:22 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	select_character(int i, int j, int x, int y)
{
	if ((i == 0) && (j == 0))
		ft_putchar('/');
	else if (((i == 0) && (j == (x - 1))) && (x != 1))
		ft_putchar('\\');
	else if (((i == (y - 1)) && (j == 0)) && (y != 1))
		ft_putchar('\\');
	else if ((i == (y - 1)) && (j == (x - 1)))
		ft_putchar('/');
	else if (((i == 0) || (i == y - 1)) || ((j == 0) || (j == x - 1)))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			select_character(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
