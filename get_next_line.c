/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:22 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/03 14:46:24 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



void ft_lstadd_back(t_save **lst, t_save *new)
{
	t_save *fsave;

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

t_save *ft_lstnew_for_fd(void *content, int fd)
{
	t_save *save;

	if (!(save = malloc(sizeof(t_save))))
		return (NULL);
	save->content = content;
	save->fd = fd;
	save->next = NULL;
	return (save);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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


// void				*ft_calloc(size_t count, size_t size)
// {
// 	unsigned long	i;
// 	char			*array;

// 	i = 0;
// 	if (!(array = (malloc(count * size))))
// 		return (NULL);
// 	ft_bzero(array, size * count);
// 	return (array);
// }

int			get_ind(char *actual)
{
	int i;

	i = 0;
	while(actual[i])
	{
		if (actual[i] == '\n')
		{
			// printf("i is %d", i);
			return (i);
		}
		i++;
	}
	return (0);
}

int			get_line(char *actual, char **line, int i)
{
	int len;
	if (!(*line = malloc(sizeof(char) * (i + 1))))
		return (0);
	i++;
	*line = ft_substr(actual, 0, i);
	len = ft_strlen(actual + i) + 1;
	ft_memmove(actual, actual + i, len);
	return (1);
}

int get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*save[10240];
	int				i;
	int				rbytes;

	if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	if (!(*line = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (save[fd] && ((i = get_ind(save[fd]) != 0)))
		return (get_line(save[fd], line, i));
	while ((rbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rbytes] = 0;
		save[fd] = ft_strjoin(save[fd], buffer);
		if ((i = get_ind(save[fd])) != 0)
			return(get_line(save[fd], line, i));
	}
	if (save[fd] && (*line = ft_strdup(save[fd])))
	{
		// free(buffer);
		// free(save[fd]);
	}
	return (rbytes);
	// *line = ft_strdup("");
}
