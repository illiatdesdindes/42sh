/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 13:21:08 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 13:51:41 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

extern char	**g_environ;
char		*g_builtins[] = {"echo", "env", "cd", "exit", "setenv", "unsetenv",
	NULL};
void		(*g_func[])(char**) = {bi_echo, bi_printenv, bi_cd, bi_exit,
	bi_setenv, bi_unsetenv};

void	bi_printenv(char **av)
{
	(void)av;
	putstrv(g_environ);
}

void	bi_exit(char **av)
{
	(void)av;
	if (av[1]) {
		if (!ft_isalpha(av[1][0])
				|| av[1][0] == '-' || av[1][0] == '+')
		{
			ft_printf("bad math expression: %s\n", av[1]);
			exit(0);
		}
		exit(ft_atoi(av[1]));
	}
	exit(0);
}

void	bi_echo(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (i > 1)
			ft_putchar(' ');
		while (av[i][j])
		{
			if (av[i][j] == '\\' && av[i][j + 1] == 'n')
			{
				ft_putchar('\n');
				j++;
			}
			else
				ft_putchar(av[i][j]);
			j++;
		}
		i++;
	}
	ft_putchar('\n');
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
