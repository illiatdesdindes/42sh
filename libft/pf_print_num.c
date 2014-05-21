/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 14:09:16 by svachere          #+#    #+#             */
/*   Updated: 2014/03/11 15:08:43 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_int(va_list ap, t_format format)
{
	(void)format;
	return (pf_putnbr(va_arg(ap, int)));
}
