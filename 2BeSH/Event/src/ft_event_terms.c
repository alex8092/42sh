/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_terms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:55 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 19:00:15 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_event_private.h"
#include "ft_display.h"
#include "ft_stocker.h"
#include "ft_environment.h"
#include <term.h>

t_event			*p_event_init_terms(void)
{
	char		*termtype;
	static char	buffer[2048];

	termtype = env_singleton()->get("TERM");
	if (termtype)
	{
		if (tgetent(buffer, termtype) > 0)
			display_singleton()->set_active(true);
		else
			display_singleton()->set_active(false);
	}
	return (event_singleton());
}

t_event			*p_event_reset(char *cmd)
{
	t_event		*event;
	int			length;

	length = stocker_singleton()->size();
	event = event_singleton();
	event->mv_back();
	while (length-- > 0)
	{
		if (!stocker_singleton()->is_first())
		{
			stocker_singleton()->rm_prev();
			display_singleton()->rm_prev();
			p_event_reprint_str();
		}
	}
	stocker_singleton()->clean()->push_str(cmd);
	length = 0;
	while (cmd && cmd[length])
		display_singleton()->putchar(cmd[length++]);
	return (event);
}
