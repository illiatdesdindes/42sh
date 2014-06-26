/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:39:15 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 20:35:04 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	insert(t_tok *token, t_ast *ast)
{
	t_ast	*newast;

	newast = ast_new(token);
	newast->left = ast;
	newast->up = ast->up;
	ast->up = newast;
	if (newast->up != NULL)
		newast->up->right = newast;
}

void	insert_right(t_tok *token, t_ast *ast)
{
	t_ast	*newast;

	newast = ast_new(token);
	ast->right = newast;
	newast->up = ast;
}

void	insert_left(t_tok *token, t_ast *ast)
{
	t_ast	*newast;

	newast = ast_new(token);
	ast->left = newast;
	newast->up = ast;
}

int		type_rank(enum e_toktype type)
{
	if (type == STRING)
		return (1);
	if (type == REDIN)
		return (2);
	if (type == REDOUT)
		return (3);
	if (type == REDAPP)
		return (4);
	if (type == PIPE)
		return (5);
	if (type == AND || type == OR)
		return (6);
	return (7);
}

t_ast	*descend(t_tok *token, t_ast *ast)
{
	if (ast == NULL)
		return (ast_new(token));
	if ((isredir(token->type) || isstringwithredir(token, ast))
			&& type_rank(token->type) < type_rank(ast->type)
			&& ast->left != NULL)
		descend(token, ast->left);
	else if (!isredir(token->type) && type_rank(token->type) < type_rank(ast->type)
			&& ast->right != NULL)
		descend(token, ast->right);
	else if (isredir(token->type)
			&& type_rank(token->type) < type_rank(ast->type)
			&& ast->left == NULL)
		insert_left(token, ast);
	else if (!isredir(token->type) && type_rank(token->type) < type_rank(ast->type)
			&& ast->right == NULL)
		insert_right(token, ast);
	else
		insert(token, ast);
	return (ast);
}

t_ast	*parser(t_tok *token, t_ast *ast)
{
	while (token)
	{
		ast = descend(token, ast);
		ast = ast_root(ast);
		token = token->next;
	}
	return (ast);
}
