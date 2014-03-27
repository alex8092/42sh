/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:41:08 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:49:19 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history_private.h"
#include "ft_resolver.h"
#include <stdlib.h>
#include <fcntl.h>

static t_lst_history	*p_history_create_el(char *cmd)
{
	t_lst_history	*el;

	el = ft_memalloc(sizeof(t_lst_history));
	el->cmd = cmd;
	return (el);
}

t_history				*p_history_save(t_lst_history *new, t_bool save)
{
	t_history		*history;
	char			*cmd;

	history = history_singleton();
	history->m_length++;
	history->m_pos++;
	history->m_end = new;
	if (history->m_fd != -1 && save)
	{
		cmd = ft_strjoin(new->cmd, "\n");
		ft_putstr_fd(history->m_fd, cmd);
		free(cmd);
	}
	return (history);
}

static void				doi(t_history *h, char *s, t_lst_history *n, t_bool sa)
{
	if (ft_strcmp(h->m_end->cmd, s))
	{
		h->m_end->next = n;
		n->prev = h->m_end;
		h->save(n, sa);
	}
	else
	{
		free(n->cmd);
		free(n);
	}
}

t_history				*p_history_push(char *str, t_bool save)
{
	t_history		*history;
	t_lst_history	*new;

	history = history_singleton();
	if (ft_strlen(str))
	{
		new = p_history_create_el(str);
		if (!history->m_start)
		{
			history->m_start = new;
			history->m_end = new;
			history->save(new, save);
		}
		else if (history->m_end)
			doi(history, str, new, save);
	}
	else
		free(str);
	return (history);
}
