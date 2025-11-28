/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:03:01 by ssujaude          #+#    #+#             */
/*   Updated: 2025/06/27 14:03:01 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*buffer;

	buffer = dest;
	while (*src != '\0')
	{
		*buffer = *src;
		src++;
		buffer++;
	}
	*buffer = '\0';
	return (dest);
}
