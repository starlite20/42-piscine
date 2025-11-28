/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:47:40 by ssujaude          #+#    #+#             */
/*   Updated: 2025/07/06 18:17:57 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	rush(int x, int y);

int	main(int argc, char *argv[])
{
	argc = 1;
	int w = atoi (argv[1]);
	int h = atoi (argv[2]);
	rush(w, h);
	//rush(5,10);
	return (0);
}
