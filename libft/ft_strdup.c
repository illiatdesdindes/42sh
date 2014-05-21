/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:17:57 by svachere          #+#    #+#             */
/*   Updated: 2014/03/11 18:08:28 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*new_str;

	len = ft_strlen(s1);
	new_str = (char*)malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
