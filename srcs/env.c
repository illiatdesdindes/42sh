/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 15:54:12 by svachere          #+#    #+#             */
/*   Updated: 2014/05/21 17:10:22 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

extern char	**g_environ;

int		copyenv(char **env)
{
	int		len;
	char	**newenv;

	len = 0;
	while (env[len])
		len++;
	if ((newenv = (char**)malloc(sizeof(char*) * len + 1)) == NULL)
		return (-1);
	newenv[len] = NULL;
	while (len--)
	{
		if ((newenv[len] = ft_strdup(env[len])) == NULL)
			return (-1);
	}
	g_environ = newenv;
	return (0);
}

char	*ft_getenv(char *name)
{
	int	i;

	i = -1;
	while (g_environ[++i])
	{
		if (ft_strstr(g_environ[i], name))
			return (ft_strchr(g_environ[i], '=') + 1);
	}
	return (NULL);
}

int		ft_setenv(char *name, char *value, int overwrite)
{
	char	*find;
	int		i;

	if (!name || name == NULL || !value || value == NULL)
	{
		ft_putendl("Syntax error. Example: setenv key value");
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
				return (strvput(g_environ + i, joinwith(name, value, "=")));
		}
	}
	else
		return (strvadd(&g_environ, joinwith(name, value, "=")));
	return (0);
}

void	ft_unsetenv(char *name)
{
	int	i;
	int	find;
	int	count;

	i = -1;
	find = 0;
	count = 0;
	while (g_environ[++i])
	{
		if (find)
			g_environ[i - 1] = g_environ[i];
		else if (ft_strstr(g_environ[i], name))
		{
			find = 1;
			free(g_environ[i]);
			g_environ[i] = NULL;
			count = 1;
		}
	}
	if (count == 1)
	{
		g_environ[i - 1] = NULL;
		free(g_environ[i - 1]);
	}
}
