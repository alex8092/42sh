/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:21:04 by thrivier          #+#    #+#             */
/*   Updated: 2014/03/27 17:22:10 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_resolver.h"
#include <stdlib.h>
#include <sys/stat.h>

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

	result = ft_strlen(*str);
	while ((*str)[result] != '/')
		result--;
	tmp = ft_strdup(*str);
	tmp[result] = 0;
	result = lstat(*str, &ptr);
	while (S_ISLNK(ptr.st_mode) && flagger->is_active(flagger, "L"))
	{
		gogo(buf, &tmp, str);
		result = lstat(*str, &ptr);
		if (result == -1)
		{
			free(tmp);
			ft_cd_error(str, 1);
			return (0);
		}
	}
	free(tmp);
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
			if ((ret = stat(*str, &ptr)) == -1)
				return (ft_cd_error(str, 0));
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
	char		*tmp;

	ret = 0;
	i = -1;
	tab = ft_strsplit(s, '/', false);
	tmp = *str;
	while (tab[++i])
	{
		tmp = *str;
		*str = ft_resolv_path_force(tab[i], *str, i == 0);
		free(tmp);
		ret = lstat(*str, &ptr);
		if (!what_is_this(offset, str, flagger, i) && !(tmp = NULL))
			break ;
		else if (ret == -1)
			break ;
	}
	ft_tabstrdel(tab);
	return ((ret == -1) ? ft_cd_error(str, 0) : tmp);
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
