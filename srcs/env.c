/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 15:54:12 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 09:32:36 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

extern char		**g_environ;

static size_t	ft_strleneg(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

static char		*ft_streg(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	ret = ft_strnew(i + 1);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char			*ft_getenv(char *name)
{
	int	i;

	i = -1;
	while (g_environ[++i])
	{
		if (ft_strstr(ft_streg(g_environ[i]), name)
				&& (ft_strlen(name) == ft_strleneg(g_environ[i])))
			return (ft_strchr(g_environ[i], '=') + 1);
	}
	return (NULL);
}

int				ft_setenv(char *name, char *value, int overwrite)
{
	char	*find;
	int		i;

	if (!name || name == NULL || !value || value == NULL)
	{
		ft_putendl_fd("Syntax error. Example: setenv key value", STDERR_FILENO);
		return (1);
	}
	find = ft_getenv(name);
	if (find && !overwrite)
		return (0);
	if (find)
	{
		i = -1;
		while (g_environ[++i])
		{
			if (ft_strstr(g_environ[i], name))
			{
				return (strvput(g_environ + i, joinwith(name, value, "=")));
			}
		}
	}
	else
		return (strvadd(&g_environ, joinwith(name, value, "=")));
	return (0);
}

int				ft_unsetenv(char *name, int i, int find)
{
	if (!name || name == NULL)
	{
		ft_putendl_fd("Syntax error. Example: unsetenv key", STDERR_FILENO);
		return (1);
	}
	while (g_environ[++i])
	{
		if (find)
			g_environ[i - 1] = g_environ[i];
		else if (ft_strstr(ft_streg(g_environ[i]), name)
				&& (ft_strlen(name) == ft_strleneg(g_environ[i])))
		{
			find = 1;
			free(g_environ[i]);
			g_environ[i] = NULL;
		}
	}
	if (find == 1)
	{
		g_environ[i - 1] = NULL;
		free(g_environ[i - 1]);
	}
	return (0);
}
