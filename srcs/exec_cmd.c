/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:54:19 by svachere          #+#    #+#             */
/*   Updated: 2014/06/27 11:08:25 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

extern char	**g_environ;

int		execcmd_deleg(pid_t pid, t_pipe pipes)
{
	int		state;

	returnrun(1, 1);
	waitpid(pid, &state, 0);
	returncmd(WEXITSTATUS(state), 1);
	if (pipes.in[0] != STDIN_FILENO)
		close(pipes.in[0]);
	if (pipes.out[1] != STDOUT_FILENO)
		close(pipes.out[1]);
	return (0);
}

int		execcmd(char *file, char **av, t_pipe pipes)
{
	pid_t	pid;

	if ((pid = fork()) == 0)
	{
		close(pipes.in[1]);
		close(pipes.out[0]);
		if (pipes.in[0] != STDIN_FILENO)
			dup2(pipes.in[0], STDIN_FILENO);
		if (pipes.out[1] != STDOUT_FILENO)
			dup2(pipes.out[1], STDOUT_FILENO);
		execve(file, av, g_environ);
		ft_printf("an error occured while launching %s\n", file);
		exit(-1);
	}
	if (pid > 0)
		execcmd_deleg(pid, pipes);
	return (0);
}

int		testaccessandlaunch(char *file, char **av, char **path, t_pipe pipes)
{
	if (access(file, F_OK) == 0)
	{
		if (pipes.out[1] < 0)
		{
			ft_printf("permission denied\n", *av);
			return (-1);
		}
		else if (access(file, X_OK) == 0)
		{
			execcmd(file, av, pipes);
			freefindcmd(path, file);
			return (0);
		}
		ft_printf("permission denied: %s\n", *av);
		return (-1);
	}
	return (1);
}

int		findcmd(char **av, t_pipe pipes)
{
	int		i;
	char	**path;
	char	*file;
	int		ret;

	i = -1;
	ret = 2;
	if (av && *av && contentpath(*av))
		ret = testaccessandlaunch(ft_strdup(*av), av, NULL, pipes);
	if (ret == 0 || ret == -1)
		return (ret);
	if (ret == 1 && ft_printf("no such file or directory: %s\n", *av))
		return (-1);
	path = get_path();
	while (path[++i] && av && *av)
	{
		file = joinwith(path[i], *av, "/");
		ret = testaccessandlaunch(file, av, path, pipes);
		if (ret == 0 || ret == -1)
			return (ret);
		ft_strdel(&file);
	}
	ft_printf("command not found: %s\n", *av);
	ft_strvdel(&path);
	return (-1);
}

int		send_commandline(char **cmd)
{
	int		ret;
	t_ast	*ast;
	t_tok	*tokens;

	ret = 1;
	if (*cmd != NULL && **cmd != '\0' && (tokens = lexer(*cmd)))
	{
		if (DEBUG == 1)
			print_tokens(tokens);
		if (syntax(tokens) == 1 && !(ast = NULL))
		{
			ast = parser(tokens, ast);
			browse(ast);
			ret = 0;
		}
		free_token_ast(&tokens, &ast);
	}
	//ft_strdel(cmd);
	return (ret);
}
