/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:54:28 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/04 16:05:48 by ckurt            ###   ########lyon.fr   */
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
	while((r = get_next_line(fd, &line)) > 0)
	{
		printf("\n%d", r);
		printf("%s", line);
		free(line);
	}
	printf("%d\n", r);
	printf("%s", line);
	return (0);
}
