/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:47:18 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 18:12:32 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int		(*g_pf_func[])(va_list, t_format) = {pf_percent, pf_int, pf_str,
	pf_char, pf_pointer};

int			print_part(const char *start, const char *end)
{
	int len;

	len = 0;
	while (start + len != end)
		len++;
	write(1, start, len);
	return (len);
}

int			do_format(const char **str, va_list ap)
{
	int			len;
	t_format	format;

	len = 0;
	format = pf_extract_format((char**)str);
	if (format.type >= 0)
	{
		len = g_pf_func[format.type](ap, format);
	}
	*str = *str - 1;
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*str;
	int			len;

	len = 0;
	va_start(ap, format);
	str = format;
	while (*str)
	{
		if (*str == '%')
		{
			len += print_part(format, str);
			str = str + 1;
			len += do_format(&str, ap);
			format = str + 1;
		}
		str++;
	}
	len += pf_putstr(format);
	va_end(ap);
	return (len);
}
