/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 19:54:28 by ckurt             #+#    #+#             */
/*   Updated: 2020/11/30 17:15:25 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	c;
	char *line;
	c = 'b';
	fd = open("random.txt", O_RDONLY);
	// printf("fd is %d\n", fd);
	while(get_next_line(0, &line))
	{
		
	}
	return (0);
}
