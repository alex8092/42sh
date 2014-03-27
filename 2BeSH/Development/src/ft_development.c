/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_development.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:52 by amerle            #+#    #+#             */
/*   Updated: 2014/03/26 16:54:13 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_private_developement.h"
#include "ft_lexer.h"
#include "ft_environment.h"
#include <stdlib.h>
#include "ft_resolver.h"

static t_lex		*ft_resolve(t_lex *current)
{
	char	*tmp;
	int		y;
	int		i;

	tmp = ft_strdup(current->str);
	free(current->str);
	current->str = NULL;
	current->str = ft_resolv_path(tmp);
	free(tmp);
	y = ft_strlen(env_singleton()->get("PWD"));
	i = ft_strlen(current->str);
	if (i != y && !ft_strncmp(current->str, env_singleton()->get("PWD"), y))
	{
		if (y == 1)
			tmp = ft_strdup(current->str + y);
		else
			tmp = ft_strdup(current->str + y + 1);
		free(current->str);
		current->str = ft_strdup(tmp);
		free(tmp);
	}
	return (current);
}

static t_lex		*dev_start(t_lex *begin)
{
	t_lex	*cur;
	t_lex	*tmp2;

	cur = begin->next;
	tmp2 = begin;
	while (cur)
	{
		while (cur && ft_findfirstof(cur->str, "$") > -1)
			ft_find_dollar(&cur, &tmp2, ft_findfirstof(cur->str, "$"));
		if (cur)
		{
			if (ft_findfirstof(cur->str, "*?") > -1 && cur->op != LEX_OP_STR)
			{
				if (!put_lex(&cur, &tmp2, ft_parse_stars))
				{
					ft_putstr_fd(2, ".: error :. No match found\n");
					return (NULL);
				}
			}
			ft_resolve(cur);
			tmp2 = cur;
			cur = cur->next;
		}
	}
	return (begin);
}

static void			ft_dev_init(t_development *dev)
{
	dev->start = dev_start;
	(void)dev;
}

t_development		*dev_singleton(void)
{
	static t_development	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_development*)ft_memalloc(sizeof(t_development));
		ft_dev_init(singleton);
	}
	return (singleton);
}
