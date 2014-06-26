/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 13:56:19 by alepinoy          #+#    #+#             */
/*   Updated: 2014/06/25 13:56:21 by alepinoy         ###   ########.fr       */
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
