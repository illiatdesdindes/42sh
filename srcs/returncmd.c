/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returncmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 17:12:47 by apergens          #+#    #+#             */
/*   Updated: 2014/05/29 17:13:03 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		returncmd(int n, int set)
{
	static int	ret;

	ret = set ? n : ret;
	if (set)
		returnrun(0, 1);
	return (ret);
}

int		returnrun(int n, int set)
{
	static int	ret;

	ret = set ? n : ret;
	return (ret);
}

char	*returnflare(char *str)
{
	static char	*path;

	if (path == NULL && str != NULL)
		path = ft_strjoin(str, "/BTreeViewer/flare.json");
	return (path);
}

char	*returncurr(char *str, char *name)
{
	char		*tmp;
	static char	*path;

	if (path == NULL && str != NULL && name != NULL)
	{
		tmp = ft_strjoin(str, "/");
		path = ft_strjoin(tmp, name);
		ft_strdel(&tmp);
	}
	return (path);
}
