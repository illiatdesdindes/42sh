/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:45:23 by svachere          #+#    #+#             */
/*   Updated: 2014/06/27 09:16:50 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	browse(t_ast *ast)
{
	t_pipe	pipes;

	print_ast(ast);
	if (ast != NULL)
	{
		pipes.in[0] = STDIN_FILENO;
		pipes.in[1] = -1;
		pipes.out[0] = -1;
		pipes.out[1] = STDOUT_FILENO;
		exec_node(ast, pipes);
	}
}

void	init_shell(int ac, char **av, char **env)
{
	int		i;
	char	*cmd;
	char	*str;

	error_if(env[0] == NULL, "Can't launch with an empty environment");
	copyenv(env);
	stdio_init_dup();
	signal(SIGINT, &sig_handler);
	signal(SIGSEGV, &sig_handler);
	returncurr(ft_getenv("PWD"), av[0]);
	returnflare(ft_getenv("PWD"));
	if (ac > 1 && (i = 1))
	{
		str = NULL;
		cmd = ft_strdup(av[i]);
		while (av[++i] && (str = joinwith(cmd, av[i], " ")))
		{
			ft_strdel(&cmd);
			cmd = str;
		}
		if (i > 1)
			i = send_commandline(&cmd);
		exit(!((i > 1 || !i) && cmd));
	}
}

void	ret_check(int ret)
{
	if (ret == -1)
		ft_putstr_fd("stdin read failure\n", STDERR_FILENO);
	else if (ret == 0)
	{
		ft_putstr_fd("Bye!\n", STDERR_FILENO);
		exit(0);
	}
}

int		main(int argc, char **argv, char **env)
{
	char	*line;
	int		ret;

	init_shell(argc, argv, env);
	while (42)
	{
		putprompt();
		ret_check(ret = get_next_line(0, &line));
		send_commandline(&line);
	}
	return (0);
}
