/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   svdebug.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 12:23:06 by svachere          #+#    #+#             */
/*   Updated: 2014/03/25 12:34:59 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SVDEBUG_H
# define SVDEBUG_H
# include <libftprintf.h>

# define PRI(var) ft_printf( #var " : %d ; ", var)
# define PRINL(var) ft_printf( #var " : %d ; \n", var)
# define PRS(var) ft_printf( #var " : \"%s\" ; ", var)
# define PRSNL(var) ft_printf( #var " : \"%s\" ; \n", var)

#endif

