/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:45:23 by svachere          #+#    #+#             */
/*   Updated: 2014/06/24 16:50:41 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>


void	browse(t_ast *ast)
{
	print_ast(ast);
	exec_node(ast, STDIN_FILENO, STDOUT_FILENO);
}

void	test()
{
	ft_printf("%d\n", STDIN_FILENO);
	ft_printf("%d\n", STDOUT_FILENO);
	ft_printf("%d,\n", stdin_get());
	ft_printf("%d,\n", stdout_get());
	stdio_init_dup();
	ft_printf("%d,\n", stdin_get());
	ft_printf("%d,\n", stdout_get());
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
	(void)argc;
	(void)argv;
	copyenv(env);
	test();
	while (1)
	{
		ft_putstr("$> ");
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
