/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:04 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:04 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_resolver.h"
#include <ft/regex.h>
#include "ft_environment.h"
#include "ft_executor.h"
#include <stdlib.h>

static char		*g_regex[] = {
	"^~/",
	"/[^/]{1,}/\\.\\./",
	"/\\./",
	"/\\.$",
	"/\\.\\.$",
	"/{2,}"
};

char			*ft_resolv_path_do(char *str, int begin, t_bool do_free)
{
	char	*res;

	res = ft_strdup(str);
	if (begin)
	{
		if (str[ft_strlen(str) - 1] != '/')
		{
			free(res);
			res = ft_strjoin(str, "/");
		}
	}
	else
	{
		if (str[ft_strlen(str) - 1] == '/' && ft_strlen(str) > 1)
		{
			free(res);
			res = ft_strndup(str, ft_strlen(str) - 1);
		}
	}
	if (do_free)
		free(str);
	return (res);
}

static t_regex	*get_reg(int index)
{
	static t_regex	*regs[6] = { 0 };

	if (!regs[index])
		regs[index] = ft_regex(g_regex[index]);
	return (regs[index]);
}

static void		resolv_bis_2(char **str2, char **tmp2)
{
	char	*str;
	char	*tmp;

	str = *str2;
	tmp = *tmp2;
	str = ft_resolv_path_do(str, 1, true);
	tmp = str;
	while ((str = ft_regmatch_replace(tmp, get_reg(1), "/")))
	{
		free(tmp);
		str = ft_resolv_path_do(str, 1, true);
		tmp = str;
	}
	str = tmp;
	str = ft_resolv_path_do(str, 0, true);
	tmp = str;
	while ((str = ft_regmatch_replace(tmp, get_reg(4), "/")))
	{
		free(tmp);
		tmp = str;
	}
	str = tmp;
	str = ft_regmatch_replace_all(str, get_reg(2), "/");
	*str2 = str;
	*tmp2 = tmp;
}

static char		*resolv_bis_3(char *str, char *tmp)
{
	if (str != tmp)
		free(tmp);
	tmp = str;
	str = ft_regmatch_replace_all(str, get_reg(3), "/");
	if (str != tmp)
		free(tmp);
	tmp = str;
	str = ft_regmatch_replace_all(str, get_reg(5), "/");
	if (str != tmp)
		free(tmp);
	tmp = str;
	str = ft_resolv_path_do(str, 0, true);
	return (str);
}

char			*ft_resolv_bis(char *str, char *pwd, t_bool first)
{
	char	*tmp[2];

	if (!str[0])
		return (ft_strdup("/"));
	if (!ft_strcmp(str, "~") || !ft_strcmp(str, "~/"))
		return (ft_strdup(env_singleton()->get("HOME")));
	if (str[0] != '/' && str[0] != '~')
	{
		tmp[0] = ft_strjoin(pwd, "/");
		if (!ft_rep_p_cond(ft_strncmp(str, "./", 2), &str, tmp[0]))
			str = ft_resolv_path_do(ft_strjoin(tmp[0], str + 2), 0, true);
		free(tmp[0]);
	}
	else
		str = ft_resolv_path_do(ft_strdup(str), 0, true);
	tmp[1] = ft_resolv_path_do(env_singleton()->get("HOME"), 1, false);
	if (first)
	{
		tmp[0] = str;
		str = ft_regmatch_replace_all(str, get_reg(0), tmp[1]);
		free(tmp[0]);
	}
	free(tmp[1]);
	resolv_bis_2(&str, &tmp[0]);
	return (resolv_bis_3(str, tmp[0]));
}
