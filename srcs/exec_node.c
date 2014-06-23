/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:43:35 by svachere          #+#    #+#             */
/*   Updated: 2014/06/23 15:55:58 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		exec_semic(t_ast *ast)
{
	exec_node(ast->left, STDIN_FILENO, STDOUT_FILENO);
	exec_node(ast->right, STDIN_FILENO, STDOUT_FILENO);
	return (0);
}

int		exec_string(t_ast *ast, int fdin, int fdout)
{
	char	**av;

	(void)fdin;
	(void)fdout;
	av = ft_strsplit(ast->str, " \t");
	findcmd(av);
	ft_strvdel(&av);
	return (1);
}

int		exec_node(t_ast *ast, int fdin, int fdout)
{
	if (ast->type == SEMIC)
		exec_semic(ast);
	if (ast->type == STRING)
		exec_string(ast, fdin, fdout);
	return (1);
}
