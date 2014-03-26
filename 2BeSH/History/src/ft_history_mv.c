/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_mv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:41:02 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:49:08 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history_private.h"
#include "ft_stocker.h"
#include <ft/common.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

static char		**p_history_get_cur(int *pos, t_lst_history **cur, char **base)
{
	t_history			*history;
	static char			*s_old = NULL;

	history = history_singleton();
	if (history->m_active)
		*base = ft_strjoin(history->m_active, "*");
	else
		*base = ft_strdup("");
	if (!s_old)
		s_old = ft_strdup(*base);
	if (history->m_current)
		*pos = history->m_pos;
	else
	{
		history->m_current = history->m_end;
		*pos = history->m_length;
	}
	*cur = history->m_current;
	return (&s_old);
}

static char		*p_history_get_prev(t_history *history, t_bool all)
{
	char			**old;
	t_lst_history	*cur;
	char			*base;
	int				pos;
	t_bool			prev;

	prev = !history->m_current ? false : true;
	old = p_history_get_cur(&pos, &cur, &base);
	while (cur && pos > 0)
	{
		cur = (prev && pos-- && cur->prev) ? cur->prev : cur;
		prev = (!(prev && pos)) ? true : prev;
		if (all || (ft_matchn(cur->cmd, base) && ft_strcmp(cur->cmd, *old)))
		{
			free(*old);
			*old = ft_strdup(cur->cmd);
			history->m_current = cur;
			history->m_pos = pos;
			free(base);
			return (cur->cmd);
		}
	}
	free(base);
	ft_strdel(old);
	return (NULL);
}

static char		*p_history_get_next(t_history *history, t_bool all)
{
	char			**old;
	t_lst_history	*cur;
	char			*base;
	int				pos;

	old = p_history_get_cur(&pos, &cur, &base);
	while (cur && cur->next && pos < history->m_length)
	{
		pos++;
		cur = cur->next;
		if (all || (ft_matchn(cur->cmd, base) && ft_strcmp(cur->cmd, *old)))
		{
			free(*old);
			*old = ft_strdup(cur->cmd);
			history->m_current = cur;
			history->m_pos = pos;
			return (cur->cmd);
		}
	}
	history->m_current = 0;
	history->m_pos = 0;
	free(*old);
	*old = NULL;
	return (history->m_active);
}

char			*p_history_prev(t_bool all)
{
	t_history		*history;
	char			*cmd;

	cmd = NULL;
	history = history_singleton();
	if (!history->m_current && history->m_end)
	{
		if (history->m_active)
			free(history->m_active);
		history->m_active = stocker_singleton()->to_string();
	}
	if ((history->m_current && !history->is_first()) || history->m_end)
		cmd = p_history_get_prev(history, all);
	return (cmd);
}

char			*p_history_next(t_bool all)
{
	t_history		*history;
	char			*cmd;

	cmd = NULL;
	history = history_singleton();
	cmd = p_history_get_next(history, all);
	return (cmd);
}
