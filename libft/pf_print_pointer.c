/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:04:40 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 17:23:00 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

char	get_digit(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n - 10 + 'a');
}

char	*ft_ptoa(void *p)
{
	unsigned long	tmpn;
	unsigned long	n;
	int				len;
	char			*str;

	n = (unsigned long)p;
	tmpn = (unsigned long)p;
	len = 4;
	while (tmpn /= 16)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = get_digit(n % 16);
		n = n / 16;
	}
	str[1] = 'x';
	str[0] = '0';
	return (str);
}

int		pf_pointer(va_list ap, t_format format)
{
	(void)format;
	return (pf_putstr(ft_ptoa(va_arg(ap, void*))));
}
