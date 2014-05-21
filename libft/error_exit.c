/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:43:12 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 16:56:51 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	error_exit(char *error_message)
{
	ft_putstr("ERROR");
	if (error_message != NULL)
	{
		ft_putstr(" : ");
		ft_putendl(error_message);
	}
	exit(1);
}
