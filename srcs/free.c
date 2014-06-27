/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 17:18:29 by svachere          #+#    #+#             */
/*   Updated: 2014/06/27 11:02:06 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	freefindcmd(char **path, char *file)
{
	ft_strdel(&file);
	if (path)
		ft_strvdel(&path);
}

void	free_ast(t_ast **ast)
{
	if (ast && *ast)
	{
		free_ast(&(*ast)->left);
		free_ast(&(*ast)->right);
		ft_strdel(&(*ast)->str);
		ft_bzero(*ast, sizeof(t_ast));
		ft_memdel((void *)*ast);
	}
}

void	free_token(t_tok **tok)
{
	if (tok && *tok)
	{
		free_token(&(*tok)->next);
		ft_strdel(&(*tok)->str);
		ft_bzero(*tok, sizeof(t_tok));
		ft_memdel((void *)*tok);
	}
}

void	free_token_ast(t_tok **tok, t_ast **ast)
{
	free_token(tok);
	*tok = NULL;
	free_ast(ast);
	*ast = NULL;
}
