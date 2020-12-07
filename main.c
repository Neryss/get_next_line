/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:54:28 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/07 13:48:56 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd;
	// int		r;
	char	c;
	char *line;
	line = NULL;
	c = 'b';
	line = "42";
	fd = open("random.txt", O_RDONLY);
	// while((r = get_next_line(fd, &line)) > 0)
	// {
	// 	printf("%d", r);
	// 	printf("%s", line);
	// 	free(line);
	// }
	printf("return : %d\n line = %s", get_next_line(fd, &line), line);
	// printf("%d", r);
	// printf("%s", line);
	return (0);
}
