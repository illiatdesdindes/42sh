/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svachere <svachere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:45:23 by svachere          #+#    #+#             */
/*   Updated: 2014/05/21 17:08:54 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

void	print_tokens(t_tok *tokens)
{
	while (tokens)
	{
		ft_putchar('[');
		if (tokens->type == PIPE)
			ft_putstr("PIPE");
		if (tokens->type == SEMIC)
			ft_putstr("SEMIC");
		if (tokens->type == STRING)
		{
			ft_putstr("STRING ");
			ft_putstr(tokens->str);
		}
		ft_putchar(']');
		if (tokens->next)
			ft_putstr(", ");
		tokens = tokens->next;
	}
	ft_putchar('\n');
}
