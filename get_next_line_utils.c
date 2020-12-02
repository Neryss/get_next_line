/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:24 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/02 10:13:02 by ckurt            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*bdest;
	const char	*bsrc;

	bdest = dst;
	bsrc = src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*bdest++ = *bsrc++;
	return (dst);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*fstr;
	int				tlen;

	tlen = ft_strlen(s1) + ft_strlen(s2);
	if (!(fstr = ft_calloc(tlen + 1, sizeof(char))))
		return (NULL);
	fstr = ft_memcpy(fstr, s1, ft_strlen(s1));
	fstr = ft_strcat(fstr, (char *)s2);
	return (fstr);
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
