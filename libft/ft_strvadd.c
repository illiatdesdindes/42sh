/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:04:05 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 17:20:08 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_strvadd(char ***strv, char *s)
{
	char	**newstrv;
	int		len;

	len = 0;
	if (*strv == NULL)
		len = 0;
	else
		len = ft_strvlen(*strv);
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
