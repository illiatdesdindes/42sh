/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:45:23 by svachere          #+#    #+#             */
/*   Updated: 2014/06/25 14:03:49 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	browse(t_ast *ast)
{
	t_pipe	pipes;

	print_ast(ast);
	if (ast != NULL)
	{
		pipes.in[0] = stdin_get();
		pipes.in[1] = -1;
		pipes.out[0] = -1;
		pipes.out[1] = stdout_get();
		exec_node(ast, pipes);
	}
}

void	sig_handler(int sig)
{
	(void)sig;
	ft_putchar('\n');
	ft_putstr("$> ");
}

void	init_shell(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	error_if(env[0] == NULL, "Can't launch with an empty environment");
	copyenv(env);
	stdio_init_dup();
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
		ft_putstr("$> ");
		signal(SIGINT, &sig_handler);
		error_if((ret = get_next_line(0, &line)) == -1, "stdin read failure\n");
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
