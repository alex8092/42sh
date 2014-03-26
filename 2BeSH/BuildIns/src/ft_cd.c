/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:57 by amerle            #+#    #+#             */
/*   Updated: 2014/03/26 19:53:04 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_environment.h"
#include "ft_resolver.h"
#include <ft/flagger.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

static char		*ft_get_pwd(char *s)
{
	char	*str;

	if ((str = ft_strdup(env_singleton()->get(s))))
		return (str);
	return (NULL);
}

static char	*ft_cd_error(char **str, int i)
{
	if (!*str)
		ft_putstr_fd(2, ".: cd :. : Bad Adress\n");
	else
	{
		if (i == 0)
			ft_putstr_fd(2, ".: cd :. : No file or Directory : ");
		else if (i == 1)
			ft_putstr_fd(2, ".: cd :. Symbolic link error ");
		else if (i == 2)
			ft_putstr_fd(2, ".: cd :. Not a directory ");
		else if (i == 3)
			ft_putstr_fd(2, ".: cd : Symbolic link : ");
		ft_putstr_fd(2, *str);
		ft_putchar_fd(2, '\n');
	}
	free(*str);
	*str = NULL;
	return (NULL);
}

void		gogo(char *buf, char **tmp, char **str)
{
	char	*tmp2;
	int		result;

	result = readlink(*str, buf, 511);
	buf[result] = '\0';
	tmp2 = *str;
	*str = ft_resolv_path_force(ft_strdup(buf), *tmp, true);
	free(tmp2);
}

int			find_all(char **str, char *buf, t_flagger *flagger)
{
	struct stat	ptr;
	char		*tmp;
	int			result;

	tmp = *str;
	result = lstat(*str, &ptr);
	while (S_ISLNK(ptr.st_mode) && flagger->is_active(flagger, "L"))
	{
		gogo(buf, &tmp, str);
		result = lstat(*str, &ptr);
		if (result == -1)
		{
			ft_cd_error(str, 1);
			return (0);
		}
	}
	return (1);
}

char		*what_is_this(int offset, char **str, t_flagger *flagger, int i)
{
	char		buf[512];
	struct stat ptr;
	int			ret;

	ret = 0;
	ret = lstat(*str, &ptr);
	if (ret != -1 && i >= offset + 1)
	{
		if (!find_all(str, buf, flagger))
			return (NULL);
		if (!S_ISDIR(ptr.st_mode) && !S_ISLNK(ptr.st_mode))
			return (ft_cd_error(str, 2));
		else if (S_ISLNK(ptr.st_mode) && i >= offset + 1)
		{
			if (flagger->is_active(flagger, "s"))
				return (ft_cd_error(str, 3));
		}
	}
	return ("42");
}

char		*parcour_tab(char *s, char **str, t_flagger *flagger, int offset)
{
	struct stat ptr;
	int			ret;
	char		**tab;
	int			i;

	ret = 0;
	i = 0;
	tab = ft_strsplit(s, '/', false);
	while (tab[i])
	{
		*str = ft_resolv_path_force(tab[i], *str, i == 0);
		ret = lstat(*str, &ptr);
		if (!what_is_this(offset, str, flagger, i))
			return (NULL);
		else if (ret == -1)
			return (ft_cd_error(str, 0));
		i++;
	}
	return ("42");
}

char		*find_pwd(char *s, t_flagger *flagger, int offset)
{
	char	*str;

	str = NULL;
	if (s[0] == '-' && !s[1])
		str = ft_get_pwd("OLDPWD");
	else
	{
		str = ft_get_pwd("PWD");
		if (!parcour_tab(s, &str, flagger, offset))
			return (NULL);
	}
	return (str);
}

static void		ft_execute_cd(char **chemin)
{
	int	ret;

	printf("chemin = %s\n", *chemin);
	ret = chdir(*chemin);
	(void)ret;
	ft_actualisation(*chemin);
}

static t_flagger	*create_flagger(char *name)
{
	t_flagger	*flagger;
	char		*str;

	str = resolver_singleton()->resolv_path("~/.2BeSH/conf/cd.conf");
	flagger = ft_flagger_create(str, name);
	free(str);
	return (flagger);
}

int			begin_cd(t_flagger **flagger, char **argv)
{
	char	*chemin;

	chemin = NULL;
	if (!argv[0])
		chemin = ft_get_pwd("HOME");
	else if (!argv[1])
		chemin = find_pwd(ft_strdup(argv[0]), *flagger, -1);
	else if (!argv[2])
		chemin = remplace_in_pwd(argv[0], argv[1], *flagger);
	else
	{
		ft_putstr_fd(2, ".: cd :. error too few arguments\n");
		return (1);
	}
	(*flagger)->free(flagger);
	if (chemin)
	{
		ft_execute_cd(&chemin);
		free(chemin);
	}
	else
		return (1);
	return (0);
}

int			p_buildins_cd(char **argv)
{
	t_flagger	*flagger;

	flagger = create_flagger(argv[0]);
	++argv;
	flagger->m_stop_single_tiret = true;
	if (flagger->parse(flagger, &argv))
		return (begin_cd(&flagger, argv));
	flagger->print_help(flagger);
	flagger->free(&flagger);
	return (1);
}
