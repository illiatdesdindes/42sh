/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 17:01:31 by alepinoy          #+#    #+#             */
/*   Updated: 2014/06/27 08:38:20 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	bi_cd_deleg3(char *get)
{
	if (getcwd(get, GETCWD_SIZE) != NULL
			&& !(*(get + GETCWD_SIZE) = '\0'))
	{
		ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
		ft_setenv("PWD", get, 1);
	}
}
