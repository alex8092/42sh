/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:04 by amerle            #+#    #+#             */
/*   Updated: 2014/03/26 10:42:50 by rivers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_resolver.h"
#include <ft/flagger.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

static void			print_special(char c)
{
	if (c == 'n')
		ft_putstr_fd(1, "\n");
	else if (c == 't')
		ft_putstr_fd(1, "\t");
	else if (c == 'a')
		ft_putstr_fd(1, "\a");
	else if (c == 'b')
		ft_putstr_fd(1, "\b");
	else if (c == 'r')
		ft_putstr_fd(1, "\r");
	else if (c == 'v')
		ft_putstr_fd(1, "\v");
	else if (c == '\\')
		ft_putstr_fd(1, "\\");
	else if (c == 'e')
		ft_putstr_fd(1, "\033");
	else if (c == 'f')
		ft_putstr_fd(1, "\f");
}

static void			print(t_flagger *flagger, char *str, t_bool next)
{
	char	*find;
	char	*tmp;

	tmp = str;
	if (!flagger->is_active(flagger, "E") && ft_strlen(str) > 1)
	{
		while ((find = ft_strchr(tmp, '\\')))
		{
			*find = 0;
			ft_putstr_fd(1, tmp);
			print_special(*(find + 1));
			*find = '\\';
			tmp = find + 2;
		}
		if ((str + ft_strlen(str) - tmp) > 1)
			ft_putstr_fd(1, tmp);
	}
	else
		ft_putstr_fd(1, str);
	if (next)
		ft_putstr_fd(1, " ");
}

static t_flagger	*create_flagger(char *name)
{
	t_flagger	*flagger;
	char		*str;

	str = resolver_singleton()->resolv_path("~/.2BeSH/conf/echo.conf");
	printf("name : %s\n", str);
	flagger = ft_flagger_create(str, name);
	free(str);
	return (flagger);
}

int					p_buildins_echo(char **tab)
{
	t_flagger	*flagger;
	t_bool		cond;

	flagger = create_flagger(tab[0]);
	++tab;
	if (flagger->parse(flagger, &tab))
	{
		while (*tab)
		{
			cond = (*(tab + 1)) ? true : false;
			print(flagger, *tab, cond);
			++tab;
		}
		if (!flagger->is_active(flagger, "n"))
			ft_putstr_fd(1, "\n");
	}
	else
	{
		flagger->print_help(flagger);
		flagger->free(&flagger);
		return (1);
	}
	flagger->free(&flagger);
	return (0);
}
