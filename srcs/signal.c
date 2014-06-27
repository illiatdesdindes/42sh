/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 13:56:19 by alepinoy          #+#    #+#             */
/*   Updated: 2014/06/27 08:38:27 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	sig_handler(int sig)
{
	if (sig == SIGSEGV)
	{
		ft_putstr("parse error\n");
		execve(returncurr(NULL, NULL), NULL, g_environ);
		return ;
	}
	ft_putchar('\n');
	if (!returnrun(0, 0))
		putprompt();
}
