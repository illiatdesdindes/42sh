/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:39:38 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 09:38:37 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static int		syntax_notsemic(t_tok *token)
{
	if (token->prev == NULL || token->prev->type != STRING
			|| token->next == NULL || token->next->type != STRING)
	{
		if (token->type == PIPE)
			ft_putendl_fd("syntax error near '|'", STDERR_FILENO);
		else if (token->type == AND)
			ft_putendl_fd("syntax error near '&&'", STDERR_FILENO);
		else
			ft_putendl_fd("syntax error near '||'", STDERR_FILENO);
		return (0);
	}
	return (1);
}

static int		syntax_semic(t_tok *token)
{
	if ((token->prev != NULL && token->prev->type != STRING)
			|| (token->next != NULL && token->next->type != STRING))
	{
		ft_putendl_fd("syntax error near ';'", STDERR_FILENO);
		return (0);
	}
	return (1);
}

int				syntax(t_tok *token)
{
	int		ret;

	ret = 1;
	if (token == NULL)
		return (1);
	if (token->type == PIPE || token->type == AND || token->type == OR)
		ret = syntax_notsemic(token);
	if (ret && token->type == SEMIC)
		ret = syntax_semic(token);
	if (ret)
		syntax(token->next);
	return (ret);
}
