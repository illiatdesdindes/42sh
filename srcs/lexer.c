/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 17:07:42 by svachere          #+#    #+#             */
/*   Updated: 2014/06/27 11:14:49 by apergens         ###   ########.fr       */
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
	if (c == '|' || c == ';' || c == '&' || c == '<' || c == '>')
		return (1);
	return (0);
}

t_tok	*lexer(char *line)
{
	int		i;
	char	*tmp;
	t_tok	*tokens;

	i = -1;
	tokens = NULL;
	while (line[++i])
	{
		if (line[i] == ';')
			token_add(&tokens, SEMIC, NULL);
		else if (line[i] == '&' && line[i + 1] == '&' && ++i)
			token_add(&tokens, AND, NULL);
		else if (line[i] == '|' && line[i + 1] == '|' && ++i)
			token_add(&tokens, OR, NULL);
		else if (line[i] == '|')
			token_add(&tokens, PIPE, NULL);
		else if (line[i] == '>' || line[i] == '<')
			token_add_red(&tokens, &line[i], &i);
		else if (!isspce(line[i]) && (tmp = ft_strdup(line + i)))
			token_add_string(&tokens, &tmp, &i);
	}
	return (tokens);
}
