/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:06:19 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/13 14:27:15 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	value_in_basevals(char c, char *base)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (c == base[index])
			return (index);
		index++;
	}
	return (-1);
}

int	get_actual_value(char *numstr, char *base, int baselen)
{
	int	i;
	int	valueretrieved;
	int	digit_val;

	i = 0;
	valueretrieved = 0;
	while (numstr[i])
	{
		digit_val = value_in_basevals(numstr[i], base);
		if (digit_val == -1)
			break ;
		valueretrieved = valueretrieved * baselen + digit_val;
		i++;
	}
	return (valueretrieved);
}

int	ft_atoi(char *str, char *base, int baselen)
{
	int		i;
	int		j;
	int		sign;
	char	num_str[100];

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i + j] && value_in_basevals(str[i + j], base) != -1)
	{
		num_str[j] = str[i + j];
		j++;
	}
	num_str[j] = '\0';
	return (sign * get_actual_value(num_str, base, baselen));
}

int	check_valid_base(char *str, int len)
{
	int	i;
	int	j;

	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if ((str[i] == '+' || str[i] == '-' || str[i] == ' '
				|| str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\r' ))
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

int	ft_atoi_base(char *str, char *base)
{
	int	baselen;

	baselen = 0;
	while (base[baselen])
		baselen++;
	if (!check_valid_base(base, baselen))
		return (0);
	return (ft_atoi(str, base, baselen));
}
