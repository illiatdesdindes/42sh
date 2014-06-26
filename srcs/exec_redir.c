/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:30:39 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 21:23:26 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		exec_redin(t_ast *ast, t_pipe pipes)
{
	int		pipeup[2];
	int		pipedown[2];
	int		fd;
	char	c;

	error_if(pipe(pipedown) == -1, "pipe() failed");
	pipeup[0] = pipes.in[0];
	pipeup[1] = pipes.in[1];
	pipes.in[0] = pipedown[0];
	pipes.in[1] = pipedown[1];
	if (ast->left != NULL)
		exec_node(ast->left, pipes);
	else
		exec_node(ast->right, pipes);
	if (pipeup[0] != STDIN_FILENO)
		close(pipeup[1]);
	close(pipes.in[0]);
	while (pipeup[0] != STDIN_FILENO && read(pipeup[0], &c, 1) > 0)
		write(pipes.in[1], &c, 1);
	fd = open(ast->str, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		write(pipes.in[1], &c, 1);
	close(fd);
	close(pipes.in[1]);
	close(pipeup[0]);
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
