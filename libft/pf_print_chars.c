/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 15:34:12 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 17:22:35 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int	pf_percent(va_list ap, t_format format)
{
	(void)ap;
	(void)format;
	write(1, "%", 1);
	return (1);
}

int	pf_char(va_list ap, t_format format)
{
	char	c;

	(void)format;
	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	pf_str(va_list ap, t_format format)
{
	(void)format;
	return (pf_putstr(va_arg(ap, char*)));
}
