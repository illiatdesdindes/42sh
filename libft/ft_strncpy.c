/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:42:40 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 17:08:15 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		cpy_end;

	i = 0;
	cpy_end = 0;
	while (i < n)
	{
		if (s2[i] && !cpy_end)
			s1[i] = s2[i];
		else
		{
			s1[i] = '\0';
			cpy_end = 1;
		}
		i++;
	}
	return (s1);
}
