/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:22 by ckurt             #+#    #+#             */
/*   Updated: 2020/11/29 17:48:08 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	*buff;
	int		i;

	line = malloc(sizeof(char *) * BUFFER_SIZE);
	i = 0;
	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	if (check_errors(fd))
		return (-1);
	while (read(fd, &buff[i], 1) && i < BUFFER_SIZE)
	{
		printf("%c", buff[i]);
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}