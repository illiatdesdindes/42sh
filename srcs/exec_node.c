/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:43:35 by svachere          #+#    #+#             */
/*   Updated: 2014/06/24 19:30:01 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		exec_semic(t_ast *ast)
{
	exec_node(ast->left, stdin_get(), stdout_get());
	exec_node(ast->right, stdin_get(), stdout_get());
	return (0);
}

int		exec_string(t_ast *ast, int fdin, int fdout)
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

int		exec_pipe(t_ast *ast, int fdin, int fdout)
{
	int		fildes[2];

	error_if(pipe(fildes) == -1, "pipe() failed");
	exec_node(ast->left, fdin, fildes[1]);
	exec_node(ast->right, fildes[0], fdout);
	close(fildes[0]);
	close(fildes[1]);
	return (1);
}

int		exec_node(t_ast *ast, int fdin, int fdout)
{
	if (ast->type == SEMIC)
		exec_semic(ast);
	if (ast->type == PIPE)
		exec_pipe(ast, fdin, fdout);
	if (ast->type == STRING)
		exec_string(ast, fdin, fdout);
	return (1);
}
