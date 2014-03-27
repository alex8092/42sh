/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:30 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:47:40 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_event_private.h"
#include "ft_history.h"
#include <stdlib.h>

t_event		*p_event_map_history_prev(void)
{
	t_event		*event;
	char		*prev;

	event = event_singleton();
	prev = history_singleton()->prev(true);
	if (prev)
	{
		event_singleton()->reset(prev);
	}
	return (event);
}

t_event		*p_event_map_history_next(void)
{
	t_event		*event;
	char		*next;

	event = event_singleton();
	next = history_singleton()->next(true);
	if (next)
		event->reset(next);
	return (event);
}

t_event		*p_event_map_history_mprev(void)
{
	t_event		*event;
	char		*prev;

	event = event_singleton();
	prev = history_singleton()->prev(false);
	if (prev)
		event_singleton()->reset(prev);
	return (event);
}

t_event		*p_event_map_history_mnext(void)
{
	t_event		*event;
	char		*next;

	event = event_singleton();
	next = history_singleton()->next(false);
	if (next)
		event->reset(next);
	return (event);
}
