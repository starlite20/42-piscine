/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:24:01 by ssujaude          #+#    #+#             */
/*   Updated: 2025/06/29 22:53:19 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <string.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putstr(char *str, int size)
{
	int i=0;

	while(str[i] != '\0')
		write(1, str++, 1);
}


void print_content ( char *addr, int startpt, unsigned int size)
{
	int i;

	//printf(" = \t\t pc_strtpt=%d pc_end=%d", startpt, size);

	i = startpt;
	while(i < size)
	{
		printf("%c", (addr[i++]));
	}
}


void print_data_address ( char *addr, int startpt, unsigned int size)
{
	int i;

	i = startpt;
	while(i<size)
	{
		printf("'%c", (addr[i++]));
	}

	
	printf("\t\t pdaI = %d ", i);

	
}


void *ft_print_memory(void *addr, unsigned int size)
{
	char *str_of_addr = (char*)(addr);
	int i ;
	int print_size;

	int iterations = size / 16;

	printf( " iteration : %d   || size %d  || \n", iterations, size);
	i = 0 ;
	//looping through each character of the string gets the column based data
	while( i <= iterations )
	{
		if(size > 16)
		{
			print_size = 16;
			size -= 16;
		}
		else
		{
			print_size = size;
			size = 0;
		}

		//printf("\n size %d    printsize:%d  \n", size, print_size);

		printf("%p: ", (str_of_addr + (i*16)));

		print_data_address(str_of_addr, (i*16), (i*16) + print_size);
		print_content(str_of_addr, (i*16), (i*16) + print_size);

		//printf("\n");
		ft_putchar("\n");
		write(1, "\n", 2);

		i++;
	}

	return (addr);
}

int main()
{
	char *str = "Bonjour les aminches...c. est fou.tout.ce qu onpeut faire avec...print_memory....lol.lol. ";
	void *addr;

	addr = (void *)(&str[0]);
	ft_print_memory(str, strlen(str));
	return 0;
}

