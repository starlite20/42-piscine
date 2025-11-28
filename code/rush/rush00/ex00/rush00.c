/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:53:41 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/08 15:01:54 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	select_character(int i, int j, int x, int y)
{
	if ((     (i == 0)        &&      ((j == 0) || (j == (x - 1)))    )
		|| ((i == (y - 1))    &&      ((j == 0) || (j == (x - 1)))))
		ft_putchar('o');
	else if ((i == 0) || (i == y - 1))
		ft_putchar('-');
	else if ((j == 0) || (j == x - 1))
		ft_putchar('|');
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
