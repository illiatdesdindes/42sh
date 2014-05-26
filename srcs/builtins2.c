/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 11:55:22 by svachere          #+#    #+#             */
/*   Updated: 2014/05/21 17:09:52 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	bi_setenv(char **av)
{
	ft_setenv(av[1], av[2], 1);
}

void	bi_unsetenv(char **av)
{
	ft_unsetenv(av[1]);
}
