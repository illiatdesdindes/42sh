/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strvutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 15:09:31 by svachere          #+#    #+#             */
/*   Updated: 2014/05/21 17:10:51 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void	putstrv(char **strv)
{
	while (*strv)
	{
		ft_putendl(*strv);
		strv++;
	}
}

int		strvput(char **strv, char *s)
{
	free(*strv);
	*strv = s;
	return (0);
}

int		strvadd(char ***strv, char *s)
{
	char	**newstrv;
	int		len;

	len = 0;
	while ((*strv)[len])
		len++;
	if ((newstrv = (char**)malloc(sizeof(char*) * (len + 2))) == NULL)
		return (-1);
	newstrv[len + 1] = NULL;
	newstrv[len] = s;
	while (len--)
		newstrv[len] = (*strv)[len];
	free(*strv);
	*strv = newstrv;
	return (0);
}

void	strvtrim(char **strv)
{
	char	*trimed;

	while (*strv)
	{
		trimed = ft_strtrim(*strv);
		free(*strv);
		*strv = trimed;
		strv++;
	}
}
