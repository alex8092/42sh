/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:51 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:46:45 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include <unistd.h>

static t_buildin	*buildins_get(char *name)
{
	t_buildin	*cur;

	cur = buildins_singleton()->m_begin;
	while (cur)
	{
		if (!ft_strcmp(cur->name, name))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

static t_bool		buildins_isbuildins(char *name)
{
	t_buildin	*find;

	if (name)
	{
		find = buildins_get(name);
		if (find)
			return (true);
	}
	return (false);
}

static int			buildins_exec(char *name, char **argv)
{
	const t_buildin	*buildin = buildins_get(name);

	return (buildin->exec(argv));
}

static void			buildins_init(t_buildins *bi)
{
	bi->is_buildin = buildins_isbuildins;
	bi->exec = buildins_exec;
	p_buildins_init_builds(bi);
}

t_buildins			*buildins_singleton(void)
{
	static t_buildins	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_buildins*)ft_memalloc(sizeof(t_buildins));
		if (!singleton)
			_exit(1);
		buildins_init(singleton);
	}
	return (singleton);
}
