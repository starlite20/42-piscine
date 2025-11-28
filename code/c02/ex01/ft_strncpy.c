/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 09:27:01 by ssujaude          #+#    #+#             */
/*   Updated: 2025/06/29 21:45:28 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*buffer;
	unsigned int	i;

	i = 0;
	buffer = dest;
	while (i < n)
	{
		if (*src == '\0')
		{
			*buffer = '\0';
		}
		else
		{
			*buffer = *src;
			src++;
		}
		buffer++;
		i++;
	}
	return (dest);
}
