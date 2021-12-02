/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelissi <gmelissi@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:26:04 by gmelissi          #+#    #+#             */
/*   Updated: 2021/11/22 17:55:38 by gmelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		fd;
	char	*filename;
	char	*res;

	filename = "./example.txt";
	fd = open(filename, O_RDONLY);
	int i=0;
	while (i < 2)
	{
		res = get_next_line(fd);
			printf("%s", res);
			i++;
	}

/*
	while (1)
	{
		res = get_next_line(fd);
		if (res)
		{
			printf("%s", res);
			free(res);
		}
		if (!res)
			break;

//printf("After gnl:\n");
//printf("res: %p\n\n", res);
	}
//printf("Before free:\n");
//printf("res: %p\n\n", res);
*/
	close(fd);
//printf("After free:\n");
//printf("res: %p\n\n", res);
	return (0);
}
