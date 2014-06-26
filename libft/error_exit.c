/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:43:12 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 09:39:14 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	error_exit(char *error_message)
{
	ft_putstr_fd("ERROR", STDERR_FILENO);
	if (error_message != NULL)
	{
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd(error_message, STDERR_FILENO);
	}
	exit(1);
}
