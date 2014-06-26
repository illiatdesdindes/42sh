/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:45:23 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 16:55:13 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	ast_put_str(t_ast *ast, int fd)
{
	if (ast->type == STRING)
		ft_putstr_fd("STRING", fd);
	if (ast->type == REDIN)
		ft_putstr_fd("REDIN", fd);
	if (ast->type == REDOUT)
		ft_putstr_fd("REDOUT", fd);
	if (ast->type == REDAPP)
		ft_putstr_fd("REDAPP", fd);
	ft_putstr_fd(" : ", fd);
	ft_putstr_fd(ast->str, fd);
}

void	ast_put_name(t_ast *ast, int fd)
{
	ft_putstr_fd("\"name\": ", fd);
	ft_putchar_fd('"', fd);
	if (ast && (ast->type == STRING || ast->type == REDIN 
				|| ast->type == REDOUT|| ast->type == REDAPP))
		ast_put_str(ast, fd);
	if (ast && ast->type == PIPE)
		ft_putstr_fd("PIPE", fd);
	if (ast && ast->type == AND)
		ft_putstr_fd("AND", fd);
	if (ast && ast->type == OR)
		ft_putstr_fd("OR", fd);
	if (ast && ast->type == SEMIC)
		ft_putstr_fd("SEMIC", fd);
	ft_putchar_fd('"', fd);
}

void	ast_recur(t_ast *ast, int fd)
{
	ft_putstr_fd("{", fd);
	ast_put_name(ast, fd);
	if (ast != NULL && (ast->left != NULL || ast->right != NULL))
	{
		ft_putstr_fd(", \"children\" : [", fd);
		ast_recur(ast->right, fd);
		ft_putstr_fd(" , ", fd);
		ast_recur(ast->left, fd);
		ft_putstr_fd("] ", fd);
	}
	ft_putstr_fd("}", fd);
}

void	print_ast(t_ast *ast)
{
	int		fd;

	fd = open(returnflare(NULL), O_WRONLY | O_CREAT | O_TRUNC);
	error_if(fd == -1, "can't open flare.json\n");
	ft_putstr_fd("AST_JSON = ", fd);
	ast_recur(ast, fd);
	ft_putstr_fd(";", fd);
	close(fd);
}

void	print_tokens(t_tok *tokens)
{
	ft_putstr_fd("\n#####      tokens     #####\n", STDERR_FILENO);
	while (tokens)
	{
		ft_putchar_fd('[', STDERR_FILENO);
		if (tokens->type == AND)
			ft_putstr_fd("AND", STDERR_FILENO);
		if (tokens->type == OR)
			ft_putstr_fd("OR", STDERR_FILENO);
		if (tokens->type == PIPE)
			ft_putstr_fd("PIPE", STDERR_FILENO);
		if (tokens->type == SEMIC)
			ft_putstr_fd("SEMIC", STDERR_FILENO);
		if (tokens->type == REDIN)
			ft_printf("REDIN %s", tokens->str);
		if (tokens->type == REDOUT)
			ft_printf("REDOUT %s", tokens->str);
		if (tokens->type == REDAPP)
			ft_printf("REDAPP %s", tokens->str);
		if (tokens->type == STRING)
			ft_printf("STRING %s", tokens->str);
		ft_putchar_fd(']', STDERR_FILENO);
		if ((tokens = tokens->next))
			ft_putstr_fd(", ", STDERR_FILENO);
	}
	ft_putstr_fd("\n\n", STDERR_FILENO);
}
