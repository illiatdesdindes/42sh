/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 16:06:07 by alepinoy          #+#    #+#             */
/*   Updated: 2014/06/25 16:06:12 by alepinoy         ###   ########.fr       */
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
	char	host[1024];

	host[1023] = '\0';
	info = (char *)malloc(sizeof(char) * ft_strlen(ft_getenv("USER")));
	info = ft_getenv("USER");
	ft_putstr("\x1B[32m");
	ft_putstr(info);
	ft_putstr("\033[0m:\x1B[34m");
	gethostname(host, 1023);
	ft_putstr(get_host(host));
	ft_putstr("\x1B[31m @ ");
	pwd = (char *)malloc(sizeof(char) * ft_strlen(ft_getenv("PWD")));
	pwd = ft_getenv("PWD");
	info = (char *)malloc(sizeof(char) * ft_strlen(pwd));
	ft_putstr("\x1B[33m");
	info = get_last(pwd);
	ft_putstr(info);
	ft_putstr("\033[0m ~> ");
}
