/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathmanip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:21:56 by svachere          #+#    #+#             */
/*   Updated: 2014/06/25 16:06:03 by apergens         ###   ########.fr       */
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

char	*joinlines(char **s1, char **s2, int pfree)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	if (*s1 && *s2 && (tmp2 = ft_strjoin(*s1, "\n")))
	{
		tmp = ft_strjoin(tmp2, *s2);
		free(tmp2);
		if (pfree == 1 || pfree == 3)
			ft_strdel(s1);
	}
	else
		tmp = *s1;
	if (*s2 && pfree == 2)
		ft_strdel(s2);
	return (tmp);
}

char	*joinwith(char *path, char *file, char *join)
{
	char	*slashedfile;

	if ((slashedfile = ft_strjoin(join, file)))
	{
		path = ft_strjoin(path, slashedfile);
		free(slashedfile);
	}
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
