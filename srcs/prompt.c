/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 16:06:07 by alepinoy          #+#    #+#             */
/*   Updated: 2014/06/26 09:24:46 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

char	*get_last(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	if (!str || str == NULL || str[0] == '\0')
		return (".");
	i = 0;
	j = 0;
	while (str[i])
		i++;
	i--;
	j = i;
	while (str[i] && str[i] != '/')
		i--;
	tmp = (char *)malloc(sizeof(char) * (j - i + 1));
	j = 0;
	while (str[++i])
	{
		tmp[j] = str[i];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*get_host(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str || str == NULL || str[0] == '\0')
		return ("42");
	while (str[i] && str[i] != '.')
		i++;
	tmp = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] && str[i] != '.')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	putprompt(void)
{
	char	*info;
	char	*pwd;
	char	*tmp;
	char	host[1024];

	ft_bzero(host, 1024);
	info = ft_getenv("USER");
	ft_printf("\x1B[32m%s\033[0m:\x1B[34m", info);
	gethostname(host, 1023);
	pwd = ft_getenv("PWD");
	info = get_last(pwd);
	tmp = get_host(host);
	ft_printf("%s\x1B[31m @ \x1B[33m%s\033[0m ~> ", tmp, info);
	ft_strdel(&info);
	ft_strdel(&tmp);
}
