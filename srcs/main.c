/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:45:23 by svachere          #+#    #+#             */
/*   Updated: 2014/06/24 17:58:03 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	browse(t_ast *ast)
{
	print_ast(ast);
	if (ast != NULL)
		exec_node(ast, STDIN_FILENO, STDOUT_FILENO);
}

void	void_this(int ac, char **av)
{
	(void)ac;
	(void)av;
}

void	sig_handler(int sig)
{
	(void)sig;
	ft_putchar('\n');
	ft_putstr("$> ");
}

int		main(int argc, char **argv, char **env)
{
	char	*line;
	int		ret;
	t_tok	*tokens;
	t_ast	*ast;

	if (env[0] == NULL)
	{
		ft_putendl("Can't launch with an empty environment");
		exit(1);
	}
	void_this(argc, argv);
	copyenv(env);
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
