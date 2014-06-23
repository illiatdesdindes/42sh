/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:38:44 by svachere          #+#    #+#             */
/*   Updated: 2014/06/23 14:38:52 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <sh42.h>

t_ast	*ast_new(t_tok *token)
{
	t_ast	*ast;

	ast = (t_ast*)malloc(sizeof(t_ast));
	error_if(ast == NULL, "NULL malloc");
	ast->type = token->type;
	ast->up = NULL;
	ast->left = NULL;
	ast->right = NULL;
	ast->str = NULL;
	if (token->type == STRING)
		ast->str = ft_strdup(token->str);
	return (ast);
}

t_ast	*ast_root(t_ast *ast)
{
	while (ast->up)
		ast = ast->up;
	return (ast);
}
