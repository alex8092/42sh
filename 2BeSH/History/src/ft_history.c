/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:40:54 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:48:58 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history_private.h"
#include <stdlib.h>

static void			history_init(t_history *history)
{
	p_history_init_attributes(history);
	p_history_init_methods(history);
}

void				p_history_free(void)
{
	t_lst_history	*cur;
	t_lst_history	*tmp;

	cur = history_singleton()->m_start;
	while (cur)
	{
		tmp = cur->next;
		free(cur->cmd);
		free(cur);
		cur = tmp;
	}
}

t_history			*history_singleton(void)
{
	static t_history	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_history*)ft_memalloc(sizeof(t_history));
		history_init(singleton);
	}
	return (singleton);
}
