/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:01 by ssujaude          #+#    #+#             */
/*   Updated: 2025/06/29 22:20:21 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*buffer;
	int		switch_case;

	switch_case = 1;
	buffer = str;
	while (*buffer != '\0')
	{
		if ((*buffer >= 'A' && *buffer <= 'Z')
			|| (*buffer >= 'a' && *buffer <= 'z')
			|| (*buffer >= '0' && *buffer <= '9'))
		{
			if ((*buffer >= 'a' && *buffer <= 'z') && switch_case)
				*buffer -= 32;
			else if ((*buffer >= 'A' && *buffer <= 'Z') && !switch_case)
				*buffer += 32;
			switch_case = 0;
		}
		else
			switch_case = 1;
		buffer++;
	}
	return (str);
}
