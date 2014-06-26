/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerever <akerever@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 17:36:53 by akerever          #+#    #+#             */
/*   Updated: 2014/06/25 17:36:58 by akerever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

extern char	**g_environ;

int		copyenv(char **env)
{
	int		len;
	char	**newenv;

	len = 0;
	while (env[len])
		len++;
	if ((newenv = (char**)malloc(sizeof(char*) * len + 1)) == NULL)
		return (-1);
	newenv[len] = NULL;
	while (len--)
	{
		if ((newenv[len] = ft_strdup(env[len])) == NULL)
			return (-1);
	}
	g_environ = newenv;
	return (0);
}
