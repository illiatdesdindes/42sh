/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:39:38 by svachere          #+#    #+#             */
/*   Updated: 2014/06/23 14:39:55 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		syntax_pipe(t_tok *token)
{
	if (token->prev == NULL
			|| token->prev->type != STRING
			|| token->next == NULL
			|| token->next->type != STRING)
	{
		error_exit("syntax error near '|'");
		return (0);
	}
	return (1);
}
