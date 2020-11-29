/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:24 by ckurt             #+#    #+#             */
/*   Updated: 2020/11/29 19:54:17 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_errors(int fd)
{
	if (fd == -1)
		return (-1);
	return (0);
}

int	read_stdin(void)
{
	char	*buffer;
	int		i;

	i = 0;
	if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	while (read(0, &buffer[i], BUFFER_SIZE) && i < BUFFER_SIZE)
	{
		printf("%c", buffer[i]);
		if (buffer[i] == '\n')
			return (1);
	}
	return (0);
}
