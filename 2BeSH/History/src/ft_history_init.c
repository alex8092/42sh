/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:40:57 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:49:03 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history_private.h"
#include "ft_resolver.h"
#include <ft/getnextline.h>
#include <fcntl.h>
#include <stdlib.h>

void		p_history_init_attributes(t_history *history)
{
	history->m_length = 0;
	history->m_start = 0;
	history->m_end = 0;
	history->m_current = 0;
	history->m_active = 0;
}

void		p_history_init_methods(t_history *history)
{
	history->push = p_history_push;
	history->size = p_history_size;
	history->is_first = p_history_is_first;
	history->is_end = p_history_is_end;
	history->prev = p_history_prev;
	history->next = p_history_next;
	history->load = p_history_load;
	history->save = p_history_save;
	history->unload = p_history_free;
}

t_history	*p_history_load(void)
{
	t_history	*history;
	char		*line;
	char		*file;

	history = history_singleton();
	file = resolver_singleton()->resolv_path("~/.2BeSH/history");
	history->m_fd = open(file, O_RDWR | O_CREAT, 0700);
	free(file);
	if (history->m_fd != -1)
	{
		while (get_next_line(history->m_fd, &line) > 0)
			history->push(line, false);
	}
	return (history);
}
