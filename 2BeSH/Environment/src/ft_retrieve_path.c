/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieve_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:54 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 06:34:10 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_environment.h"
#include <dirent.h>
#include <stdlib.h>

static char	*concat_all(char *str, char *str2, char *str3)
{
	char	*res;
	char	*res2;

	res = ft_strjoin(str, str2);
	res2 = ft_strjoin(res, str3);
	free(res);
	return (res2);
}

static void	path_add(char **res, char *str)
{
	char	*tmp;

	tmp = *res;
	if (*res)
	{
		*res = concat_all(*res, ":", str);
		free(str);
	}
	else
		*res = str;
	if (tmp)
		free(tmp);
}

static void	path_sub(char **res, char *path, int level)
{
	DIR				*d;
	struct dirent	*item;

	if (!(d = opendir(path)))
		return ;
	while ((item = readdir(d)))
	{
		if (!ft_strcmp(item->d_name, "bin")
			|| !ft_strcmp(item->d_name, "sbin"))
			path_add(res, concat_all(path, "/", item->d_name));
		else if (level < 2 && ft_strcmp(item->d_name, ".")
				&& ft_strcmp(item->d_name, ".."))
		{
			if (path[1] != 0)
				path_sub(res, concat_all(path, "/", item->d_name), level + 1);
			else
				path_sub(res, ft_strjoin(path, item->d_name), level + 1);
		}
	}
	free(path);
	closedir(d);
}

void		p_env_retrieve_path(void)
{
	char	*res;

	res = NULL;
	path_sub(&res, ft_strdup("/"), 0);
	if (res)
		env_singleton()->set("PATH", res);
}
