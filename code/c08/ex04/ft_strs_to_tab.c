/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:51:13 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/15 15:26:57 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;


int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup_withlen(char *str, int len)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			i;

	result = (t_stock_str *)malloc((sizeof(t_stock_str)) * (ac + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < ac && av[i])
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_strdup_withlen(av[i], result[i].size);
		i++;
	}
	result[i].size = 0;
	result[i].str = 0;
	result[i].copy = 0;
	return (result);
}

void print_stock_str(t_stock_str *arr)
{
	int i = 0;
	while (arr[i].str != NULL)
	{
		printf("Original: %s\n", arr[i].str);
		printf("Copy: %s\n", arr[i].copy);
		printf("Length: %d\n", arr[i].size);
		i++;
	}
}


int main(void)
{
	char *inputs[] = {"Hello", NULL, "42", "School"};
	int count = sizeof(inputs) / sizeof(inputs[0]);

	t_stock_str *result = ft_strs_to_tab(count, inputs);
	if (result == NULL)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	print_stock_str(result);

	// Free allocated memory
	for (int i = 0; i < count; i++)
		free(result[i].copy);
	free(result);

	return 0;
}