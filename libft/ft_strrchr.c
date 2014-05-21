/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:05:02 by svachere          #+#    #+#             */
/*   Updated: 2013/11/20 17:06:57 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s) + 1;
	while (--len)
	{
		if (s[len] == (char)c)
			return ((char*)s + len);
	}
	if (s[len] == (char)c)
		return ((char*)s + len);
	return (NULL);
}
