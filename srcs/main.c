/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:45:23 by svachere          #+#    #+#             */
/*   Updated: 2014/05/21 17:08:54 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

extern char	**g_environ;

int		execcmd(char *file, char **av)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(file, av, g_environ);
		ft_printf("an error occured while launching %s\n", file);
		exit(-1);
	}
	if (pid > 0)
	{
		waitpid(pid, NULL, 0);
	}
	return (0);
}

int		testaccessandlaunch(char *file, char **av, char **path)
{
	if (access(file, F_OK) == 0)
	{
		if (access(file, X_OK) == 0)
		{
			execcmd(file, av);
			freefindcmd(path, file);
			return (0);
		}
		ft_printf("permission denied: %s\n", *av);
		return (-1);
	}
	return (1);
}

int		findcmd(char **av)
{
	int		i;
	char	**path;
	char	*file;
	int		ret;

	i = -1;
	ret = 2;
	if (contentpath(*av))
		ret = testaccessandlaunch(ft_strdup(*av), av, NULL);
	if (ret == 0 || ret == -1)
		return (ret);
	if (ret == 1 && ft_printf("no such file or directory: %s\n", *av))
		return (-1);
	path = get_path();
	while (path[++i])
	{
		file = joinwith(path[i], *av, "/");
		ret = testaccessandlaunch(file, av, path);
		if (ret == 0 || ret == -1)
			return (ret);
		free(file);
	}
	ft_printf("command not found: %s\n", *av);
	freestrv(path);
	return (-1);
}

int		main(int argc, char **argv, char **env)
{
	char	*line;
	int		ret;
	char	**av;

	(void)argc;
	(void)argv;
	copyenv(env);
	while (1)
	{
		ft_putstr("$> ");
		ret = get_next_line(0, &line);
		ft_strtrim(line);
		av = ft_strsplit(line, " \t");
		if (ret != -1 && av != NULL && *av != '\0')
		{
			if (!isbuiltin(av))
				findcmd(av);
		}
		free(line);
	}
	return (0);
}
