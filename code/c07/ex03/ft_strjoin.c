/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:12:26 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/16 12:12:40 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*d_buffer;
	char	*s_buffer;

	d_buffer = dest;
	s_buffer = src;
	d_buffer += ft_strlen(dest);
	while (*s_buffer)
	{
		*d_buffer = *s_buffer;
		d_buffer++;
		s_buffer++;
	}
	*d_buffer = '\0';
	return (dest);
}

int	get_total_length(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (size == 0)
		return (1);
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
		len += ((size - 1) * ft_strlen(sep));
	len += 1;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;
	int		len;

	i = 0;
	len = get_total_length(size, strs, sep);
	result = malloc(len * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < (size - 1))
		{
			ft_strcat(result, sep);
		}
		i++;
	}
	return (result);
}

int main()
{
	char *str[] = {"Hi", "hello", "there"};
	char *res = ft_strjoin(3, str, "---");
	
	printf("\n%s",res);
	
	return 0;
}
