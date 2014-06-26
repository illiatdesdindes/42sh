/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 15:03:21 by svachere          #+#    #+#             */
/*   Updated: 2014/03/11 15:20:35 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int	pf_putnbr(int n)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	len = pf_putstr(s);
	free(s);
	return (len);
}
