/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:34:25 by ssujaude          #+#    #+#             */
/*   Updated: 2025/06/30 15:56:29 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*buffer;

	buffer = dest;
	i = 0;
	while (*buffer)
		buffer++;
	while ((i < nb) && *src)
	{
		*buffer++ = *src++;
		i++;
	}
	*buffer = '\0';
	return (dest);
}
