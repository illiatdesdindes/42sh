/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:45:23 by svachere          #+#    #+#             */
/*   Updated: 2014/06/24 18:52:50 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	browse(t_ast *ast)
{
	print_ast(ast);
	if (ast != NULL)
		exec_node(ast, stdin_get(), stdout_get());
}

void	init_shell(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	error_if(env[0] == NULL, "Can't launch with an empty environment");
	copyenv(env);
	stdio_init_dup();
	signal(SIGINT, &sig_handler);
}

char	*get_last(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	if (!str || str == NULL || str[0] == '\0')
		return ("/");
	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	j = i;
	while (str[i] && str[i] != '/')
		i--;
	tmp = (char *)malloc(sizeof(char) * (j - i + 1));
	j = 0;
	while (str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void	putprompt(void)
{
	char	*info;
	char	*pwd;

	info = (char *)malloc(sizeof(char) * ft_strlen(ft_getenv("USER")));
	info = ft_getenv("USER");
	ft_putstr("\x1B[32m");
	ft_putstr(info);
	ft_putstr("\x1B[31m");
	ft_putstr(" @ ");
	pwd = (char *)malloc(sizeof(char) * ft_strlen(ft_getenv("PWD")));
	pwd = ft_getenv("PWD");
	info = (char *)malloc(sizeof(char) * ft_strlen(pwd));
	ft_putstr("\x1B[33m");
	info = get_last(pwd);
	ft_putstr(info);
	ft_putstr("\033[0m >> ");
}

void	ret_check(int ret)
{
	if (ret == -1)
		ft_putstr("stdin read failure\n");
	else if (ret == 0)
	{
		ft_putstr("Bye!\n");
		exit(0);
	}
}

int		main(int argc, char **argv, char **env)
{
	char	*line;
	int		ret;
	t_tok	*tokens;
	t_ast	*ast;

	init_shell(argc, argv, env);
	while (1)
	{
		putprompt();
		ret_check(ret = get_next_line(0, &line));
		if (line != NULL && *line != '\0')
		{
			tokens = lexer(line);
			if (DEBUG == 1)
				print_tokens(tokens);
			ast = NULL;
			ast = parser(tokens, ast);
			browse(ast);
			free_token_ast(&tokens, &ast);
		}
		free(line);
	}
	return (0);
}
