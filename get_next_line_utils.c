/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:41:55 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/24 20:33:15 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*r;

	if (!s)
		return (0);
	r = s;
	while (*r)
		r++;
	return (r - s);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (!*s)
			return (NULL);
		s++;
	}
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	res = (char *)malloc(++len);
	if (!res)
		return (NULL);
	i = 0;
	if (start <= ft_strlen(s))
	{
		s += start;
		while (--len > 0)
			*(res + i++) = *s++;
	}
	*(res + i) = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (dstsize)
	{	
		while (*s && dstsize-- > 1)
			*d++ = *s++;
		*d = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len;
	int		n;

	if (!s1 && !s2)
		return (NULL);
	len = 1;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	res = (char *)malloc(len);
	if (!res)
		return (NULL);
	n = 0;
	if (s1)
		n = ft_strlcpy(res, s1, len);
	if (s2)
		(void)ft_strlcpy(res + n, s2, len - n);
	if (s1)
		free(s1);
	s1 = NULL;
	return (res);
}
