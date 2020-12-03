/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurt <ckurt@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:06:24 by ckurt             #+#    #+#             */
/*   Updated: 2020/12/03 14:33:55 by ckurt            ###   ########lyon.fr   */
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
	int				i;

	i = 0;
	if (!s1)
		return(ft_strdup(s2));
	tlen = ft_strlen(s1) + ft_strlen(s2);
	if (!(fstr = malloc(sizeof(char) * (tlen + 1))))
		return (NULL);
	while (i < tlen)
		fstr[i++] = 0;
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

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		*bdst;
	const char	*bsrc;

	i = 0;
	bsrc = src;
	bdst = dst;
	if (!src && !dst)
		return (NULL);
	if (src > dst)
	{
		while ((unsigned long)i < len)
		{
			bdst[i] = bsrc[i];
			i++;
		}
	}
	else
		while (len--)
			bdst[len] = bsrc[len];
	return (dst);
}
