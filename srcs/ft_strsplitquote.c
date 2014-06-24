/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitquote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:19:30 by svachere          #+#    #+#             */
/*   Updated: 2014/06/24 17:54:42 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
#include <stdlib.h>

static int		isin(char c, char *str, int reset)
{
	static int	quote;
	static int	dbquote;

	quote = (reset == 1) ? 0 : quote;
	dbquote = (reset == 1) ? 0 : dbquote;
	if (reset == 1)
		return (0);
	if (reset != -1 && !dbquote && c == '\'')
		quote = quote ? 0 : 1;
	else if (reset != -1 && !quote && c == '"')
		dbquote = dbquote ? 0 : 1;
	while (*str)
	{
		if ((reset == -1 || (!quote && !dbquote)) && c == *str)
			return (1);
		str++;
	}
	return (0);
}

static char		*ft_remove_quotes(char *str)
{
	int			i;
	int			j;
	int			quote;
	char		*clean;

	if ((clean = ft_strnew(ft_strlen(str))))
	{
		i = -1;
		j = -1;
		quote = 0;
		while (*(str + (++i)))
		{
			if (*(str + i) != '\'' && *(str + i) != '"')
				*(clean + (++j)) = *(str + i);
			else if (quote == '\'' && *(str + i) == '"')
				*(clean + (++j)) = *(str + i);
			else if (quote == '"' && *(str + i) == '\'')
				*(clean + (++j)) = *(str + i);
			if (!quote && (*(str + i) == '\'' || *(str + i) == '"'))
				quote = *(str + i);
			else
			{
				quote = (quote == '\'' && *(str + i) == quote) ? 0 : quote;
				quote = (quote == '"' && *(str + i) == quote) ? 0 : quote;
			}
		}
		ft_strdel(&str);
	}
	return (clean);
}

static char		*ft_extract_word(char *s, char *splitchars)
{
	int			len;
	char		*word;

	len = 0;
	while (!isin(s[len], splitchars, 0) && s[len] != '\0')
		len++;
	if (!(word = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	word[len] = '\0';
	while (len--)
		word[len] = s[len];
	return (ft_remove_quotes(word));
}

static char		**ft_add_word_to_table(char *word, char **table)
{
	int			i;
	char		**tmptable;

	if (!(tmptable = (char**)malloc(sizeof(char*) * (ft_strvlen(table) + 2))) ||
		word == NULL)
		return (NULL);
	i = 0;
	while (table != NULL && table[i] != NULL)
	{
		tmptable[i] = table[i];
		i++;
	}
	tmptable[i] = word;
	tmptable[i + 1] = NULL;
	if (table != NULL)
		free(table);
	return (tmptable);
}

char			**ft_strsplitquote(char const *s, char *splitchars)
{
	int			i;
	char		**table;
	char		*word;

	if (s == NULL)
		return (NULL);
	table = NULL;
	i = 0;
	isin(0, NULL, 1);
	while (s[i])
	{
		if (!isin(s[i], splitchars, -1) &&
			(i == 0 || isin(s[i - 1], splitchars, -1)))
		{
			word = ft_extract_word((char*)(s + i), splitchars);
			table = ft_add_word_to_table(word, table);
			i += ft_strlen(word);
		}
		i++;
	}
	if (table == NULL)
		return (ft_add_word_to_table(NULL, table));
	return (table);
}
