/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:20:28 by ssujaude          #+#    #+#             */
/*   Updated: 2025/06/30 15:32:44 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char			*buffer;

	buffer = dest;
	while (*buffer != '\0')
		buffer++;
	while (*src != '\0')
		*buffer++ = *src++;
	*buffer = '\0';
	return (dest);
}
