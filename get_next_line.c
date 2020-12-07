/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:22 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/07 15:59:53 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_strdup(const char *s1)
{
	int				len;
	int				i;
	char			*str;

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

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned long	temp;
	char			*substr;

	i = 0;
	temp = 0;
	if (!s || !(substr = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[i] && temp < len)
	{
		if (i >= start)
			substr[temp++] = s[i];
		i++;
	}
	substr[temp] = 0;
	return (substr);
}

int			get_ind(char *actual)
{
	int i;

	i = 0;
	while(actual[i])
	{
		if (actual[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int			get_line(char *actual, char **line, int i)
{
	int len;
	if (!(*line = malloc(sizeof(char) * (i + 1))))
		return (-1);
	*line = ft_substr(actual, 0, i);
	i++;
	len = ft_strlen(actual + i) + 1;
	ft_memmove(actual, actual + i, len);
	return (1);
}

// ssize_t	read_wrapper(int fd, char *buf, size_t len)
// {
// 	printf("read was called!\n");

// 	return read(fd, buf, len);
// }

int get_next_line(int fd, char **line)
{
	char			*buffer;
	static	char	*csave[10240];
	int				i;
	int				rbytes;

	if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	if (BUFFER_SIZE <= 0)
		return (-1);
	// if (!(*line = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
	// 	return (-1);
	buffer[0] = 0;
	csave[fd] = ft_strjoin(csave[fd], buffer);
	while ((i = get_ind(csave[fd])) != -1)
	{
		csave[fd] = ft_strjoin(csave[fd], buffer);
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes <= 0)
			return (rbytes);
		buffer[rbytes] = 0;
	}
	return(get_line(csave[fd], line, i));
}
