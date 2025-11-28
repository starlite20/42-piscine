/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 09:28:01 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/16 11:24:56 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tab[i] += tab[j];
				tab[j] = tab[i] - tab[j];
				tab[i] -= tab[j];
			}
			j++;
		}
		i++;
	}
}

int main()
{
	int arr[] = {10, 1, 5, 20};
	int size = 4;
	int i;

	ft_sort_int_tab(arr, size);

	i = 0;
	while(i<size)
	{
		printf("%d   ", arr[i]);
		i++;
	}
	
	return 0;
}