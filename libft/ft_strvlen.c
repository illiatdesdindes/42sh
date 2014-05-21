/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 15:22:54 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 17:20:22 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strvlen(char **strv)
{
	int		i;

	i = 0;
	while (strv[i])
		i++;
	return (i);
}
