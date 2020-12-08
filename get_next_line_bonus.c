/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:22 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/07 20:33:36 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fetch_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != 10)
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != 10)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*fetch_save(char *save)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != 10)
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	if (!(res = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (NULL);
	i++;
	while (save[i])
		res[j++] = save[i++];
	res[j] = 0;
	free(save);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*save[10240];
	int			readvalue;

	readvalue = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
		!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (readvalue != 0 && !ft_strchr(save[fd], 10))
	{
		if ((readvalue = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[readvalue] = 0;
		save[fd] = ft_strjoin(save[fd], buffer);
	}
	free(buffer);
	*line = fetch_line(save[fd]);
	save[fd] = fetch_save(save[fd]);
	if (readvalue == 0)
		return (0);
	return (1);
}
