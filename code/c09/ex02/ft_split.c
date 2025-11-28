/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:22:02 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/16 19:23:41 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	is_this_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_wordcount(char *str, char *sep)
{
	int	wordcount;
	int	i;
	int	inword;

	wordcount = 0;
	i = 0;
	inword = 0;
	while (str[i])
	{
		if (!is_this_separator(str[i], sep))
		{
			if (inword == 0)
			{
				inword = 1;
				wordcount++;
			}
		}
		else if (is_this_separator(str[i], sep) && inword)
			inword = 0;
		i++;
	}
	return (wordcount);
}

int	get_words(char **result, char *str, char *charset)
{
	int	i;
	int	j;
	int	start_pt;
	int	str_index;

	i = 0;
	str_index = 0;
	while (i < get_wordcount(str, charset))
	{
		while (str[str_index] && is_this_separator(str[str_index], charset))
			str_index++;
		start_pt = str_index;
		while (str[str_index] && !(is_this_separator(str[str_index], charset)))
			str_index++;
		j = str_index - start_pt;
		result[i] = malloc((sizeof(char)) * (j + 1));
		if (result[i] == NULL)
			return (0);
		ft_strncpy(result[i], &str[start_pt], j);
		result[i++][j] = '\0';
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;

	result = malloc((sizeof(char *) * (get_wordcount(str, charset) + 1)));
	if (result == NULL)
		return (NULL);
	if (!get_words(result, str, charset))
		return (NULL);
	return (result);
}
