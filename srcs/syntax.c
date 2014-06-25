/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 14:39:38 by svachere          #+#    #+#             */
/*   Updated: 2014/06/25 14:03:22 by svachere         ###   ########.fr       */
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
		ft_printf("syntax error near '|'\n");
		return (0);
	}
	return (1);
}
