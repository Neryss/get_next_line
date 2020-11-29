/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:54:28 by ckurt             #+#    #+#             */
/*   Updated: 2020/11/29 19:55:50 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	c;
	char	**line;

	line = malloc(sizeof(char *) * BUFFER_SIZE);
	c = 'b';
	fd = open("random.txt", O_RDONLY);
	printf("fd is %d\n", fd);
	while (get_next_line(0, line))
	{
		/*
		//print each line saved during the call
		//mallox by buffer size and realloc for the added room needed
		*/
	}
	return (0);
}
