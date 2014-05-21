/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 17:18:29 by svachere          #+#    #+#             */
/*   Updated: 2014/05/21 17:10:07 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void	freestrv(char **strv)
{
	int	i;

	i = -1;
	while (strv[++i])
		free(strv[i]);
	free(strv);
}

void	freefindcmd(char **path, char *file)
{
	free(file);
	if (path)
		freestrv(path);
}
