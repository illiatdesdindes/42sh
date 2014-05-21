/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 12:01:52 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 17:20:38 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	save_buffer(char **save, char **savemalloc, char *buffer)
{
	char	*nxt_save;

	nxt_save = ft_strjoin(*save, buffer);
	free(*savemalloc);
	*save = nxt_save;
	*savemalloc = nxt_save;
	return (1);
}

static int	save_buff_get_line(char **save, char **savemalloc, char *buffer,
								char **line)
{
	char	*nextline;

	nextline = ft_strchr(buffer, '\n');
	if (nextline == NULL)
	{
		save_buffer(save, savemalloc, buffer);
		return (0);
	}
	else
	{
		*nextline = '\0';
		*line = ft_strjoin(*save, buffer);
		**save = '\0';
		save_buffer(save, savemalloc, nextline + 1);
		return (1);
	}
}

static int	save_get_line(char **save, char **line, int endoffile)
{
	char	*nextline;

	if (endoffile)
	{
		*line = ft_strdup(*save);
		**save = '\0';
		return (1);
	}
	nextline = ft_strchr(*save, '\n');
	if (nextline == NULL)
		return (0);
	else
	{
		*nextline = '\0';
		*line = ft_strdup(*save);
		*save = nextline + 1;
		return (1);
	}
}

static int	init_save(char **save, char **savemalloc, char **buffer)
{
	if (*save == NULL)
	{
		*save = (char*)malloc(sizeof(char));
		*savemalloc = *save;
		**save = '\0';
	}
	if (*buffer == NULL)
		*buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*buffer = NULL;
	static char	*save = NULL;
	static char	*savemalloc = NULL;

	if (fd <= -1 || line == NULL)
		return (-1);
	init_save(&save, &savemalloc, &buffer);
	if (save_get_line(&save, line, 0))
		return (1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (save_buff_get_line(&save, &savemalloc, buffer, line))
			return (1);
	}
	if (ret == -1)
		return (-1);
	save_get_line(&save, line, 1);
	if (**line != '\0')
		return (1);
	free(savemalloc);
	save = NULL;
	return (0);
}
