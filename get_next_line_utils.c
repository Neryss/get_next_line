/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:24 by ckurt             #+#    #+#             */
/*   Updated: 2020/11/30 17:26:50 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_errors(int fd)
{
	if (fd == -1)
		return (-1);
	return (0);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (nb != 0)
	{
		while (dest[i] != 0)
			i++;
		while (src[j] && j < nb)
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	return (dest);
}

char	*str_realloc(char *str, size_t size)
{
	char	*buffer;

	if (!(buffer = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	buffer[0] = 0;
	ft_strncat(buffer, str, ft_strlen(str));
	free(str);
	return (buffer);
}

int		ft_strlen(const char *s)
{
	int n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	unsigned long	i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = '\0';
}
