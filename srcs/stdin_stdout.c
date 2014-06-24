/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_stdout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 16:07:02 by svachere          #+#    #+#             */
/*   Updated: 2014/06/24 16:50:41 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

int		stdio_store(int inorout, int getorset, int fd)
{
	static int	indup = STDIN_FILENO;
	static int	outdup = STDOUT_FILENO;

	if (inorout == STDIN_FILENO)
	{
		if (getorset == SET)
			indup = fd;
		return indup;
	}
	else if (inorout == STDOUT_FILENO)
	{
		if (getorset == SET)
			outdup = fd;
		return outdup;
	}
	return (-1);
}

void	stdio_init_dup()
{
	int		newfdin;
	int		newfdout;

	newfdin = dup(STDIN_FILENO);
	newfdout = dup(STDOUT_FILENO);
	stdio_store(STDIN_FILENO, SET, newfdin);
	stdio_store(STDOUT_FILENO, SET, newfdout);
}

int		stdin_get()
{
	return (stdio_store(STDIN_FILENO, GET, 0));
}

int		stdout_get()
{
	return (stdio_store(STDOUT_FILENO, GET, 0));
}
