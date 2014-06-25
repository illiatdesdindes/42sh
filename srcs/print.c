/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:45:23 by svachere          #+#    #+#             */
/*   Updated: 2014/06/25 08:43:30 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	ast_put_name(t_ast *ast, int fd)
{
	ft_putstr_fd("\"name\": ", fd);
	ft_putchar_fd('"', fd);
	if (ast && ast->type == STRING)
	{
		ft_putstr_fd("STRING : ", fd);
		ft_putstr_fd(ast->str, fd);
	}
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

	fd = open("BTreeViewer/flare.json", O_WRONLY | O_CREAT | O_TRUNC);
	error_if(fd == -1, "can't open flare.json\n");
	ft_putstr_fd("AST_JSON = ", fd);
	ast_recur(ast, fd);
	ft_putstr_fd(";", fd);
	close(fd);
}

void	print_tokens(t_tok *tokens)
{
	ft_putstr("\n#####      tokens     #####\n");
	while (tokens)
	{
		ft_putchar('[');
		if (tokens->type == AND)
			ft_putstr("AND");
		if (tokens->type == OR)
			ft_putstr("OR");
		if (tokens->type == PIPE)
			ft_putstr("PIPE");
		if (tokens->type == SEMIC)
			ft_putstr("SEMIC");
		if (tokens->type == STRING)
			ft_printf("STRING %s", tokens->str);
		ft_putchar(']');
		if (tokens->next)
			ft_putstr(", ");
		tokens = tokens->next;
	}
	ft_putstr("\n\n");
}
