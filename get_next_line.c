/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:22 by ckurt             #+#    #+#             */
/*   Updated: 2020/11/30 17:38:39 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;
	unsigned long	i;

	str = (unsigned char *)s;
	uc = c;
	i = 0;
	while ((i < n) && str[i])
	{
		if (str[i] == uc)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	get_next_line(int fd, char **line)
{
	char	*buffer;
	int		i;

	i = 0;
	if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	ft_bzero(buffer, BUFFER_SIZE);
	// if (!(line = malloc(sizeof(char *))))
	// 	return (-1);
	if (!(*line = malloc(sizeof(char) * (ft_strlen(buffer) + 1))))
		return (-1);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		*line = ft_strncat(*line, buffer, ft_strlen(buffer));
		if (ft_memchr(buffer, '\n', BUFFER_SIZE))
		{
			ft_putstr_fd(*line, fd);
			return (1);
		}
	}
	return (0);
}
