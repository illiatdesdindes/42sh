/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:33:34 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 17:23:45 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	error_if(int boolean, char *error_message)
{
	if (boolean)
	{
		error_exit(error_message);
	}
}
