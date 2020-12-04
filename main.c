/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:54:28 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/04 09:44:34 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd;
	int		r;
	char	c;
	char *line;
	line = NULL;
	c = 'b';
	fd = open("random.txt", O_RDONLY);
	// printf("fd is %d\n", fd);
	while((r = get_next_line(fd, &line)) > 0)
	{
		
		printf("adfasdfasdf =", );
		printf("return = %d\n", r);
		printf("line = %s", line);
		// free(&line);
	}
	
		// printf("return = %d\n", r);
		// printf("line = %s", line);
	// ßget_next_line(fd, &line);
	return (0);
}
