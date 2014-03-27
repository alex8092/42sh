/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_other.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:52 by triviere          #+#    #+#             */
/*   Updated: 2014/03/27 20:48:30 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_event_private.h"
#include "ft_stocker.h"
#include "ft_display.h"
#include "ft_history.h"
#include <ft/common.h>

void				p_event_reprint_str(void)
{
	int		pos;
	int		save;

	pos = stocker_singleton()->current_pos();
	save = pos;
	while (!stocker_singleton()->is_end())
	{
		display_singleton()->putchar(stocker_singleton()->char_current());
		stocker_singleton()->mv_next();
		++pos;
	}
	display_singleton()->putchar(' ');
	while (pos != save)
	{
		display_singleton()->mv_prev();
		stocker_singleton()->mv_prev();
		--pos;
	}
	display_singleton()->mv_prev();
}

t_event				*p_event_end(void)
{
	char	*cmd;

	cmd = stocker_singleton()->to_string();
	history_singleton()->push(cmd, true);
	history_singleton()->m_current = 0;
	event_singleton()->mv_back();
	display_singleton()->putchar('\n');
	return (event_singleton());
}

static void			p_event_read_for_print(char *c)
{
	while (c[0])
	{
		if (c[0] != '\n')
		{
			display_singleton()->puts("im");
			display_singleton()->putchar(c[0]);
			display_singleton()->puts("ei");
			stocker_singleton()->push((char)c[0]);
			p_event_reprint_str();
		}
		else
		{
			event_singleton()->end();
			break ;
		}
		c[0] = c[1];
		c[1] = c[2];
		c[2] = c[3];
		c[3] = 0;
	}
	if (history_singleton()->m_current)
	{
		history_singleton()->m_current = 0;
		history_singleton()->m_active = stocker_singleton()->to_string();
	}
}

static t_bool		p_event_read_for_key(char *c)
{
	t_event_item	*cur;
	int				comp;

	cur = event_singleton()->m_begin;
	comp = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];
	while (cur)
	{
		if (comp == cur->key)
		{
			cur->function();
			c[0] = 0;
			c[1] = 0;
			c[2] = 0;
			c[3] = 0;
			return (true);
		}
		cur = cur->next;
	}
	return (false);
}

t_event				*p_event_read(char *c)
{
	if (!p_event_read_for_key(c))
		p_event_read_for_print(c);
	return (event_singleton());
}
