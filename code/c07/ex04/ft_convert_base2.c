/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:21:46 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/13 11:54:21 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_base_valid(char *basestr)
{
	int	i;
	int	j;
	int	baselen;

	baselen = ft_strlen(basestr);
	if (baselen < 2)
		return (0);
	i = 0;
	while (i < baselen)
	{
		j = i + 1;
		while (j < baselen)
		{
			if (basestr[i] == basestr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	if ((c == '+' || c == '-' || c == ' '
			|| c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' ))
		return (1);
	return (0);
}

char	*clean_number(char *number, int *sign)
{
	int		i;
	int		cn_i;
	char	*clean_number;

	clean_number = (char *)malloc(sizeof(char) * ft_strlen(number));
	if (clean_number == NULL)
		return (NULL);
	i = 0;
	while ((ft_isspace(number[i]) && (number[i] != '\0')))
	{
		if (number[i++] == '-')
			*sign *= -1;
	}
	cn_i = 0;
	while (number[i] != '\0')
	{
		clean_number[cn_i++] = number[i];
		i++;
	}
	clean_number[i] = '\0';
	return (clean_number);
}

unsigned int	to_pow(int n, int pow)
{
	unsigned int	num;

	num = 1;
	while ((pow--) > 0)
		num *= n;
	return (num);
}
