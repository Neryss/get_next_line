/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:22 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/02 16:40:47 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				*ft_memchr(const void *s, int c, size_t n)
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

void				ft_lstadd_back(t_save **lst, t_save *new)
{
	t_save			*fsave;

	fsave = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (fsave->next)
			fsave = fsave->next;
		fsave->next = new;
		new->next = NULL;
	}
}

t_save				*ft_lstnew_for_fd(void *content, int fd)
{
	t_save			*save;
	
	if (!(save = malloc(sizeof(t_save))))
		return (NULL);
	save->content = content;
	save->fd = fd;
	save->next = NULL;
	return (save);
}

void				*ft_calloc(size_t count, size_t size)
{
	unsigned long	i;
	char			*array;

	i = 0;
	if (!(array = (malloc(count * size))))
		return (NULL);
	ft_bzero(array, size * count);
	return (array);
}

int					get_next_line(int fd, char **line)
{
	char			*buffer;
	static t_save	*save;

	if (!(buffer = ft_calloc(sizeof(char), BUFFER_SIZE)))
		return (-1);
	if (!(*line = ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (-1);
	save = ft_lstnew_for_fd(*line, fd);
	if (save->fd != fd)
		ft_lstadd_back(&save, ft_lstnew_for_fd(*line, fd));
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		// printf("yo\n");
		*line = ft_strjoin(*line, buffer);
		if (ft_memchr(buffer, '\n', BUFFER_SIZE))
		{
			save->content = ft_strjoin(save->content, *line);
			return (1);
		}
		ft_bzero(buffer, BUFFER_SIZE);
	}
	*line = ft_strjoin(*line, save->content);
	return (0);
}
