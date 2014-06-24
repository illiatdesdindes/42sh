/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/26 00:22:22 by apergens          #+#    #+#             */
/*   Updated: 2014/05/26 14:16:48 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh42.h>

static char		*bi_cd_delvolumes(char **pwd)
{
	int		len;

	len = ft_strlen("/Volumes/DATA");
	if (!ft_strncmp(*pwd, "/Volumes/DATA", len - 1))
		*pwd += len;
	return (*pwd);
}

static void		bi_cd_strdir(char *pwd, int endl)
{
	char	*home;

	home = ft_getenv("HOME");
	if (home != NULL && !ft_strncmp(home, pwd, ft_strlen(home) - 1))
	{
		pwd += ft_strlen(home);
		ft_putchar('~');
	}
	if (endl)
		ft_putendl(pwd);
	else
		ft_putstr(pwd);
	return ;
}

static int		bi_cd_deleg2(char *dir, char *get)
{
	char	*dir2;

	dir2 = NULL;
	if (ft_strncmp(dir, "~/", 2) == 0)
	{
		dir2 = ft_strjoin(ft_getenv("HOME"), dir + 1);
		if (chdir(dir2) > -1)
		{
			ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
			ft_setenv("PWD", get, 1);
		}
		ft_strdel(&dir2);
	}
	else
	{
		ft_putstr_fd("cd: No such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(dir, STDERR_FILENO);
	}
	return (0);
}

static int		bi_cd_deleg(char *dir, char **av, int home)
{
	char	get[GETCWD_SIZE + 1];

	home = 0;
	if (chdir(dir) > -1)
	{
		if (getcwd(get, GETCWD_SIZE) != NULL && !(*(get + GETCWD_SIZE) = '\0'))
		{
			ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
			ft_setenv("PWD", get, 1);
		}
	}
	else if (!(*(av + 1) != NULL && *(av + 2) != NULL))
		bi_cd_deleg2(dir, get);
	return (0);
}

void			bi_cd(char **av)
{
	char	*dir;

	if (*(av + 1) != NULL && *(av + 2) != NULL)
		ft_putendl_fd("cd: too many arguments", 2);
	dir = *(av + 1);
	if (dir == NULL || !*dir)
		dir = ft_getenv("HOME");
	else if (*dir == '-' && *(dir + 1) == '\0')
	{
		dir = ft_getenv("OLDPWD");
		bi_cd_strdir(bi_cd_delvolumes(&dir), 1);
	}
	else if (*dir == '-' && *(dir + 1) != '\0')
	{
		if (ft_isdigit(*(dir + 1)))
			ft_putendl_fd("cd: no such entry in dir stack", 2);
		else
			ft_putstr_fd("cd: no such file or directory: ", STDERR_FILENO);
		if (!ft_isdigit(*(dir + 1)))
			ft_putendl_fd(dir, STDERR_FILENO);
		return ;
	}
	bi_cd_deleg(dir, av, 0);
}
