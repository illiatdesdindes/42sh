/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 20:32:30 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 20:35:04 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		isredir(enum e_toktype type)
{
	if (type == REDIN || type == REDOUT || type == REDAPP)
		return (1);
	return (0);
}

int		isstringwithredir(t_tok *token, t_ast *ast)
{
	if (token->type == STRING && isredir(ast->type))
		return (1);
	return (0);
}

int		isstrredir(enum e_toktype type)
{
	if (type == STRING || isredir(type))
		return (1);
	return (0);
}
