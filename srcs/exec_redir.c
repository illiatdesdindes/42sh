/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:30:39 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 15:42:08 by svachere         ###   ########.fr       */
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
	close(pipeup[1]);
	close(pipes.in[0]);
	while (read(pipeup[0], &c, 1) > 0)
		write(pipes.in[1], &c, 1);
	fd = open(ast->str, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		write(pipes.in[1], &c, 1);
	close(fd);
	close(pipes.in[1]);
	close(pipeup[0]);
	return (1);
}
