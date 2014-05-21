/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 15:04:17 by svachere          #+#    #+#             */
/*   Updated: 2014/03/11 15:22:10 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int	pf_putstr(char const *s)
{
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
