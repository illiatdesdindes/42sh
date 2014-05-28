/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 12:55:09 by svachere          #+#    #+#             */
/*   Updated: 2014/05/28 17:09:47 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

t_tok	*token_add_string(t_tok **tokens, char *str, int *ilexer)
{
	int		i;
	t_tok	*tok;

	i = 0;
	while (str[i] != '\0' && !isopsymb(str[i]))
		i++;
	tok = token_add(tokens, STRING, ft_strsub(str, 0, i));
	*ilexer += i - 1;
	return (tok);
}

t_tok	*token_add(t_tok **tokens, t_toktype toktype, char *str)
{
	t_tok	*newtok;
	t_tok	*itok;

	if ((newtok = (t_tok*)malloc(sizeof(t_tok))) == NULL)
		return (NULL);
	newtok->type = toktype;
	newtok->str = str;
	newtok->next = NULL;
	newtok->prev = NULL;
	if (*tokens == NULL)
		return (*tokens = newtok);
	itok = *tokens;
	while (itok->next)
		itok = itok->next;
	itok->next = newtok;
	newtok->prev = itok;
	return (newtok);
}
