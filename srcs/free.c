/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 17:18:29 by svachere          #+#    #+#             */
/*   Updated: 2014/06/23 14:30:00 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	freefindcmd(char **path, char *file)
{
	free(file);
	if (path)
		ft_strvdel(&path);
}

void	free_ast(t_ast *ast)
{
	if (ast != NULL)
	{
		free_ast(ast->left);
		free_ast(ast->right);
		if (ast->str != NULL)
			free(ast->str);
		free(ast);
	}
}

void	free_token(t_tok *tok)
{
	if (tok != NULL)
	{
		free_token(tok->next);
		if (tok->str != NULL)
			free(tok->str);
		free(tok);
	}
}

void	free_token_ast(t_tok **tok, t_ast **ast)
{
	free_token(*tok);
	*tok = NULL;
	free_ast(*ast);
	*ast = NULL;
}
