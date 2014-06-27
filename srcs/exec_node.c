/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:43:35 by svachere          #+#    #+#             */
/*   Updated: 2014/06/27 10:06:08 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		exec_semic(t_ast *ast)
{
	t_pipe	pipes;

	pipes.in[0] = STDIN_FILENO;
	pipes.in[1] = -1;
	pipes.out[0] = -1;
	pipes.out[1] = STDOUT_FILENO;
	exec_node(ast->left, pipes);
	exec_node(ast->right, pipes);
	return (1);
}

int		exec_string(t_ast *ast, t_pipe pipes)
{
	char	**av;
	int		ret;

	ret = 1;
	av = NULL;
	if (SINGLE_LINE && ast->str)
		av = ft_strsplitquote(ast->str, " \t");
	else if (ast->str)
		av = ft_strsplit(ast->str, " \t");
	if (!isbuiltin(av))
		ret = findcmd(av, pipes);
	if (ret != 0)
		returncmd(ret, 1);
	ft_strvdel(&av);
	return (1);
}

int		exec_pipe(t_ast *ast, t_pipe pipes)
{
	int		fildes[2];
	t_pipe	pipes2;

	error_if(pipe(fildes) == -1, "pipe() failed");
	pipes2.in[0] = fildes[0];
	pipes2.in[1] = fildes[1];
	pipes2.out[0] = pipes.out[0];
	pipes2.out[1] = pipes.out[1];
	pipes.out[0] = fildes[0];
	pipes.out[1] = fildes[1];
	exec_node(ast->left, pipes);
	exec_node(ast->right, pipes2);
	close(fildes[0]);
	close(fildes[1]);
	return (1);
}

int		exec_and_or(t_ast *ast, t_pipe pipes)
{
	exec_node(ast->left, pipes);
	if (ast->type == AND && returncmd(0, 0) == 0)
		exec_node(ast->right, pipes);
	if (ast->type == OR && returncmd(0, 0) != 0)
		exec_node(ast->right, pipes);
	return (1);
}

int		exec_node(t_ast *ast, t_pipe pipes)
{
	int		ret;

	ret = 1;
	if (ast == NULL)
		return (0);
	if (ast->type == SEMIC)
		ret = exec_semic(ast);
	if (ast->type == AND || ast->type == OR)
		ret = exec_and_or(ast, pipes);
	if (ast->type == PIPE)
		ret = exec_pipe(ast, pipes);
	if (ast->type == REDAPP)
		ret = exec_redapp(ast, pipes);
	if (ast->type == REDOUT)
		ret = exec_redout(ast, pipes);
	if (ast->type == REDIN)
		ret = exec_redin(ast, pipes);
	if (ast->type == STRING)
		ret = exec_string(ast, pipes);
	return (ret);
}
