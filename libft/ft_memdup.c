/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:02:19 by svachere          #+#    #+#             */
/*   Updated: 2014/03/11 18:08:44 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

void	*ft_memdup(const void *s, size_t n)
{
	void	*new;

	if ((new = malloc(sizeof(unsigned char) * n)) == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(new, s, n);
	return (new);
}
