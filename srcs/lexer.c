/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 17:07:42 by svachere          #+#    #+#             */
/*   Updated: 2014/05/21 19:29:52 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		isspce(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		isopsymb(char c)
{
	if (c == '|' || c == ';')
		return (1);
	return (0);
}

t_tok	*lexer(char *line)
{
	int		i;
	t_tok	*tokens;

	i = -1;
	tokens = NULL;
	while (line[++i])
	{
		if (line[i] == ';')
			token_add(&tokens, SEMIC, NULL);
		else if (line[i] == '|')
			token_add(&tokens, PIPE, NULL);
		else if (!isspce(line[i]))
			token_add_string(&tokens, line + i, &i);
	}
	return (tokens);
}
