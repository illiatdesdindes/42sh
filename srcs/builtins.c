/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 13:21:08 by svachere          #+#    #+#             */
/*   Updated: 2014/05/21 17:09:52 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

extern char	**g_environ;
char		*g_builtins[] = {"test", "env", "cd", "exit", "setenv", "unsetenv",
	NULL};
void		(*g_func[])(char**) = {bi_test, bi_printenv, bi_cd, bi_exit,
	bi_setenv, bi_unsetenv};

void	bi_printenv(char **av)
{
	(void)av;
	putstrv(g_environ);
}

void	bi_cd(char **av)
{
	char	buf[1024];

	(void)av;
	chdir(av[1]);
	ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
	getcwd(buf, 1024);
	ft_setenv("PWD", buf, 1);
}

void	bi_exit(char **av)
{
	(void)av;
	exit(0);
}

void	bi_test(char **av)
{
	(void)av;
	ft_setenv("TRUC", "machin", 1);
	ft_setenv("TRUC2", "machin2", 0);
	ft_setenv("TRUC", "ne remplace pas", 0);
	ft_setenv("TRUC", "remplace", 1);
}

int		isbuiltin(char **av)
{
	int		i;

	i = -1;
	while (g_builtins[++i])
	{
		if (ft_strequ(g_builtins[i], *av))
		{
			g_func[i](av);
			return (1);
		}
	}
	return (0);
}
