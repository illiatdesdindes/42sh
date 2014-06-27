/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strvutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 15:09:31 by svachere          #+#    #+#             */
/*   Updated: 2014/06/27 09:34:42 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

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
	if (strv && *strv)
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
	if (strv && *strv)
		free(*strv);
	*strv = newstrv;
	return (0);
}

void	strvtrim(char **strv)
{
	char	*trimed;

	while (strv && *strv)
	{
		trimed = ft_strtrim(*strv);
		free(*strv);
		*strv = trimed;
		strv++;
	}
}
