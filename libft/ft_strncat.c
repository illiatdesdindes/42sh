/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:49:58 by svachere          #+#    #+#             */
/*   Updated: 2013/11/21 19:09:14 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		s1_end;

	i = 0;
	while (s1[i])
		i++;
	s1_end = i;
	while (s2[i - s1_end] && i - s1_end < n)
	{
		s1[i] = s2[i - s1_end];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
