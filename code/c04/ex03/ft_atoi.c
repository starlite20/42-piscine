/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:35:17 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/13 23:21:00 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if ((c == ' ' || c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' ))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	number;
	int	i;
	int	sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((ft_isspace(str[i]) && (str[i] != '\0')))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number *= 10;
			number += (str[i] - 48);
		}
		else
			break ;
		i++;
	}
	return (number * sign);
}
