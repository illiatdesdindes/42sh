/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathmanip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:21:56 by svachere          #+#    #+#             */
/*   Updated: 2014/05/21 17:10:38 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

extern char	**g_environ;

void	chpwdenv(char *newdir)
{
	(void)newdir;
}

char	**get_path(void)
{
	int	i;

	i = -1;
	while (g_environ[++i])
	{
		if (ft_strnequ(g_environ[i], "PATH=", 5))
		{
			return (ft_strsplit(ft_strchr(g_environ[i], '=') + 1, ":"));
		}
	}
	return (NULL);
}

char	*joinwith(char *path, char *file, char *join)
{
	char	*slashedfile;

	slashedfile = ft_strjoin(join, file);
	path = ft_strjoin(path, slashedfile);
	free(slashedfile);
	return (path);
}

int		contentpath(char *file)
{
	while (*file)
	{
		if (*file == '/')
			return (1);
		file++;
	}
	return (0);
}
