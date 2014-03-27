/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_development3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:24:59 by thrivier          #+#    #+#             */
/*   Updated: 2014/03/27 17:25:03 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_private_developement.h"
#include "ft_environment.h"
#include <stdlib.h>

t_lex				*ft_remplace_dollar(t_lex *begin)
{
	int		i;
	int		y;
	char	*str;
	char	*tmp;

	i = ft_findfirstof(begin->str, "$");
	y = ft_find_end_dollar(begin->str + i + 1);
	tmp = ft_strndup(begin->str + i + 1, y);
	if ((str = env_singleton()->get(tmp)))
	{
		if (i == 0)
			test(&begin, str, y);
		else
			test2(&begin, str, y, i);
	}
	else
	{
		if (!test3(&begin, i, y))
		{
			ft_clear_lex(begin);
			ft_memdel((void **)&begin);
		}
	}
	free(tmp);
	return (begin);
}

void				ft_find_dollar(t_lex **cur, t_lex **tmp, int i)
{
	if (i == -1)
		return ;
	else
		put_lex(cur, tmp, ft_remplace_dollar);
}

t_dir				*ft_new_dir(char *str)
{
	t_dir	*dir;

	dir = NULL;
	dir = ft_memalloc(sizeof(t_dir));
	if (!str)
	{
		dir->name = ft_strdup(env_singleton()->get("PWD"));
		dir->delname = true;
	}
	else
		dir->name = str;
	dir->next = NULL;
	return (dir);
}
