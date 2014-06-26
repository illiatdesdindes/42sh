/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:16:58 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 18:44:41 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <string.h>
# include <stdarg.h>

typedef struct	s_format
{
	int	flag;
	int	width;
	int	preci;
	int type;
}				t_format;

int				ft_printf(const char *format, ...);
int				pf_putnbr(int n);
int				pf_putstr(char const *s);
t_format		pf_extract_format(char **s);
int				pf_int(va_list ap, t_format format);
int				pf_percent(va_list ap, t_format format);
int				pf_char(va_list ap, t_format format);
int				pf_str(va_list ap, t_format format);
int				pf_pointer(va_list ap, t_format format);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_isdigit(int c);
#endif
