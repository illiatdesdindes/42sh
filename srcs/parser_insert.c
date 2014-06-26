/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 22:18:20 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 22:20:56 by svachere         ###   ########.fr       */
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
