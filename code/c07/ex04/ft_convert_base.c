/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:08:59 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/13 11:53:49 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(char *str);
int				is_base_valid(char *basestr);
int				ft_isspace(char c);
char			*clean_number(char *nbr, int *sign);
unsigned int	to_pow(int n, int pow);

int	find_index_of_char(char *src, char findchar)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == findchar)
			return (i);
		i++;
	}
	return (-1);
}

int	base_to_num(char *nbr, char *base_from)
{
	unsigned int	num;
	int				i;
	int				baselen;
	int				numlen;

	num = 0;
	baselen = ft_strlen(base_from);
	numlen = ft_strlen(nbr) - 1;
	i = 0;
	while (nbr[i])
	{
		num += (to_pow(baselen, (numlen - i))
				* find_index_of_char(base_from, nbr[i]));
		i++;
	}
	return (num);
}

int	get_digits_len(long int num, int div)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= div;
		len++;
	}
	return (len);
}

char	*num_to_base(char *result, long int num, char *base_to)
{
	int		i;
	int		baselen;
	char	*temp;

	baselen = ft_strlen(base_to);
	temp = malloc((sizeof(char) * 100));
	if (temp == NULL)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		temp[0] = '-';
		num *= -1;
		i = get_digits_len(num, baselen) + 1;
	}
	else
		i = get_digits_len(num, baselen);
	temp[i--] = '\0';
	while (num > 0)
	{
		temp[i--] = base_to[(num % baselen)];
		num /= baselen;
	}
	result = temp;
	return (result);
}

char	*ft_convert_base(char *inp_number, char *base_from, char *base_to)
{
	int		number;
	int		sign;
	char	*result;
	char	*nbr;

	result = NULL;
	sign = 1;
	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (0);
	nbr = clean_number(inp_number, &sign);
	number = (base_to_num(nbr, base_from)) * sign;
	result = num_to_base(result, number, base_to);
	return (result);
}
