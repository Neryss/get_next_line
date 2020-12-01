/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:22 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/01 17:52:15 by ckurt            ###   ########lyon.fr   */
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

void	free_tab(char **line)
{
	free(*line);
	free(line);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	if (!(str = malloc((sizeof(char) * (len + 1)))))
		return (0);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long	i;
	char			*array;

	i = 0;
	if (!(array = (malloc(count * size))))
		return (NULL);
	ft_bzero(array, size * count);
	return (array);
}

int	get_next_line(int fd, char **line)
{
	char	*buffer;
	int		i;

	i = 0;
	if (!(buffer = ft_calloc(sizeof(char), BUFFER_SIZE)))
		return (-1);
	if (!(*line = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		*line = ft_strjoin(*line, buffer);
		if (ft_memchr(buffer, '\n', BUFFER_SIZE))
			return (1);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	return (0);
}
