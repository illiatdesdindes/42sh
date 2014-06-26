/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:30:39 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 22:07:33 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		exec_redin(t_ast *ast, t_pipe pipes)
{
	int		fd;

	fd = open(ast->str, O_RDONLY);
	if (pipes.in[0] != STDIN_FILENO)
		close(pipes.in[0]);
	close(pipes.in[1]);
	pipes.in[0] = fd;
	if (ast->left != NULL)
		exec_node(ast->left, pipes);
	else
		exec_node(ast->right, pipes);
	close(fd);
	return (1);
}

int		exec_redout(t_ast *ast, t_pipe pipes)
{
	int		pipeup[2];
	int		fd;

	fd = open(ast->str, O_WRONLY | O_TRUNC | O_CREAT);
	pipeup[0] = pipes.out[0];
	pipeup[1] = pipes.out[1];
	pipes.out[0] = -1;
	pipes.out[1] = fd;
	if (ast->left != NULL)
		exec_node(ast->left, pipes);
	else
		exec_node(ast->right, pipes);
	if (pipeup[1] != STDOUT_FILENO)
	{
		chmod(ast->str, S_IRWXU | S_IRWXG | S_IROTH);
		fd = open(ast->str, O_RDONLY);
		dup2(fd, pipeup[0]);
		close(pipeup[1]);
	}
	return (1);	
}

int		exec_redapp(t_ast *ast, t_pipe pipes)
{
	int		pipeup[2];
	int		fd;

	fd = open(ast->str, O_WRONLY | O_CREAT | O_APPEND);
	pipeup[0] = pipes.out[0];
	pipeup[1] = pipes.out[1];
	pipes.out[0] = -1;
	pipes.out[1] = fd;
	if (ast->left != NULL)
		exec_node(ast->left, pipes);
	else
		exec_node(ast->right, pipes);
	if (pipeup[1] != STDOUT_FILENO)
	{
		chmod(ast->str, S_IRWXU | S_IRWXG | S_IROTH);
		fd = open(ast->str, O_RDONLY);
		dup2(fd, pipeup[0]);
		close(pipeup[1]);
	}
	return (1);	
}
