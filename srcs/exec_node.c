/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:43:35 by svachere          #+#    #+#             */
/*   Updated: 2014/06/25 13:56:28 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		exec_semic(t_ast *ast)
{
	t_pipe	pipes;

	pipes.in[0] = stdin_get();
	pipes.in[1] = -1;
	pipes.out[0] = -1;
	pipes.out[1] = stdout_get();
	exec_node(ast->left, pipes);
	exec_node(ast->right, pipes);
	return (0);
}

int		exec_string(t_ast *ast, t_pipe pipes)
{
	char	**av;

	error_if(dup2(fdin, STDIN_FILENO) == -1, "dup2 fdin failed");
	error_if(dup2(fdout, STDOUT_FILENO) == -1, "dup2 fdout failed");
	av = ft_strsplitquote(ast->str, " \t");
	if (!isbuiltin(av))
		findcmd(av);
	ft_strvdel(&av);
	return (1);
}

int		exec_pipe(t_ast *ast, t_pipe pipes)
{
	int		fildes[2];

	error_if(pipe(fildes) == -1, "pipe() failed");
	exec_node(ast->left, );
	exec_node(ast->right, );
	return (1);
}

int		exec_node(t_ast *ast, t_pipe pipes)
{
	if (ast->type == SEMIC)
		exec_semic(ast);
	if (ast->type == PIPE)
		exec_pipe(ast, pipes);
	if (ast->type == STRING)
		exec_string(ast, pipes);
	return (1);
}
