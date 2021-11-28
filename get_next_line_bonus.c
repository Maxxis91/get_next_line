/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:41:27 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/28 16:23:10 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*set_res(int fd, char **res)
{
	char	*tmp;
	int		nbytes;

	nbytes = 1;
	while (nbytes && !ft_strchr(*res, 10))
	{
		tmp = (char *)malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		nbytes = read(fd, tmp, BUFFER_SIZE);
		if (nbytes > 0)
		{
			*(tmp + nbytes) = '\0';
			*res = ft_strjoin(*res, tmp);
		}
		free(tmp);
		if (nbytes == -1)
			return (NULL);
	}
	return (NULL);
}

static char	*get_ret(char **res)
{
	char	*ret;
	char	*tmp;
	size_t	len;

	ret = NULL;
	if (ft_strchr(*res, 10))
	{
		len = ft_strchr(*res, 10) - *res + 1;
		tmp = *res;
		ret = ft_substr(*res, 0, len);
		*res = ft_substr(*res, len, ft_strlen(*res) - len);
		free(tmp);
	}
	else
	{
		if (*res && **res)
			ret = ft_substr(*res, 0, ft_strlen(*res));
		free(*res);
		*res = NULL;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*res = NULL;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	(void)set_res(fd, &res);
	ret = get_ret(&res);
	return (ret);
}
