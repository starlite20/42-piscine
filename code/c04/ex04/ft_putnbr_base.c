/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:47:33 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/05 14:36:55 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	check_valid_base(char *str)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	convert_to_base(unsigned int num, char *base, int baselen)
{
	if (num >= (unsigned int)baselen)
		convert_to_base(num / baselen, base, baselen);
	ft_putchar(base[num % baselen]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				baselen;
	unsigned int	num;

	if (!check_valid_base(base))
		return ;
	baselen = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		num = (unsigned int)(-(long)nbr);
	}
	else
	{
		num = (unsigned int)nbr;
	}
	convert_to_base(num, base, baselen);
}
