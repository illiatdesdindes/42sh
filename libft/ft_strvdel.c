/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:19:29 by svachere          #+#    #+#             */
/*   Updated: 2014/03/05 14:22:42 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strvdel(char ***strv)
{
	int		i;

	if (*strv != NULL)
	{
		i = -1;
		while ((*strv)[++i])
			free((*strv)[i]);
		free((*strv));
		*strv = NULL;
	}
}
