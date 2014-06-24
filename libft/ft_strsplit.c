/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:19:30 by svachere          #+#    #+#             */
/*   Updated: 2014/06/24 14:49:55 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		isin(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

static char		*ft_extract_word(char *s, char *splitchars)
{
	int		len;
	char	*word;

	len = 0;
	while (!isin(s[len], splitchars) && s[len] != '\0')
		len++;
	word = (char*)malloc(sizeof(char) * (len + 1));
	word[len] = '\0';
	while (len--)
		word[len] = s[len];
	return (word);
}

static char		**ft_add_word_to_table(char *word, char **table)
{
	int		i;
	char	**tmptable;

	tmptable = (char**)malloc(sizeof(char*) * (ft_strvlen(table) + 2));
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

char			**ft_strsplit(char const *s, char *splitchars)
{
	int		i;
	char	**table;
	char	*word;

	if (s == NULL)
		return (NULL);
	table = NULL;
	i = 0;
	while (s[i])
	{
		if (!isin(s[i], splitchars) && (i == 0 || isin(s[i - 1], splitchars)))
		{
			word = ft_extract_word((char*)(s + i), splitchars);
			table = ft_add_word_to_table(word, table);
		}
		i++;
	}
	if (table == NULL)
		return (ft_add_word_to_table(NULL, table));
	return (table);
}
