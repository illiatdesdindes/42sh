/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 12:55:09 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 16:58:01 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		*count_quotes(char *str)
{
	int			count;
	int			quote;
	static int	save[] = {0, 0};

	count = 0;
	quote = 0;
	while (((quote == -1 && !(quote = 0)) || quote >= 0) && *str)
	{
		quote = (quote > 0 && *str == quote && ++count) ? -1 : quote;
		if (!quote && (*str == '\'' || *str == '"') && ++count)
			quote = *str;
		if (*str == '\\' && (*(str + 1) == '\'' || *(str + 1) == '"'))
			str++;
		str++;
	}
	save[0] = count;
	save[1] = quote;
	return (save);
}

int		token_add_red(t_tok **tokens, char *str, int *i)
{
	int			ret;
	int			org;
	int			pos;
	char		*cmd;

	ret = 0;
	org = (*(str + 1) == '<' || *(str + 1) == '>') ? 1 : 0;
	while (isspce(*(str + (++org))))
		pos = org + 1;
	while (*(str + pos) && !(isopsymb(*(str + pos)) || isspce(*(str + pos))))
		pos++;
	cmd = ft_strsub(str, org, pos - org);
	if (*str == '>' && *(str + 1) == '>' && ++ret)
		token_add(tokens, REDAPP, cmd);
	else if (*str == '>' && ++ret)
		token_add(tokens, REDOUT, cmd);
	else if (*str == '<' && ++ret)
		token_add(tokens, REDIN, cmd);
	while (isspce(*(str + (pos))))
		pos++;
	*i += pos - 1;
	return (ret);
}

t_tok	*token_add_string(t_tok **tokens, char **str, int *ilexer)
{
	int			i;
	int			*repeat;
	char		*gnl;
	t_tok		*tok;

	i = 0;
	gnl = NULL;
	repeat = NULL;
	while (repeat == NULL || (MULTI_LINE && repeat[0] % 2))
	{
		if (repeat != NULL && repeat[0])
		{
			ft_printf("%cquote> ", (repeat[1] == 39) ? 0 : 'd');
			if (get_next_line(0, &gnl) >= 0)
				*str = joinlines(str, &gnl, 3);
		}
		while ((*str)[i] != '\0' && !isopsymb((*str)[i]))
			i++;
		repeat = count_quotes(*str);
	}
	tok = token_add(tokens, STRING, ft_strsub(*str, 0, i));
	ft_strdel(str);
	*ilexer += i - 1;
	return (tok);
}

t_tok	*token_add(t_tok **tokens, t_toktype toktype, char *str)
{
	t_tok		*newtok;
	t_tok		*itok;

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
