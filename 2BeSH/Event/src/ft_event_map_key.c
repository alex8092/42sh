/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_map_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:41 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 14:55:23 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_event_private.h"
#include "ft_stocker.h"
#include "ft_prompt.h"
#include "ft_display.h"
#include <ft/common.h>

t_event		*p_event_map_word_prev(void)
{
	t_event		*event;
	t_stocker	*stocker;

	event = event_singleton();
	stocker = stocker_singleton();
	while (42)
	{
		event->mv_prev();
		if (stocker->is_first() || stocker->char_current() == ' ')
			break ;
	}
	return (event);
}

t_event		*p_event_map_word_next(void)
{
	t_event		*event;
	t_stocker	*stocker;

	event = event_singleton();
	stocker = stocker_singleton();
	while (42)
	{
		event->mv_next();
		if (stocker->is_end() || stocker->char_current() == ' ')
			break ;
	}
	return (event);
}

t_event		*p_event_map_tab(void)
{
	t_event		*event;

	event = event_singleton();
	return (event);
}

t_event		*p_event_map_clean(void)
{
	t_event		*event;
	t_display	*display;
	int			i;

	i = stocker_singleton()->size();
	event = event_singleton();
	display = display_singleton();
	display->puts("cl");
	display->putstr(prompt_singleton()->to_string());
	display->putstr(stocker_singleton()->to_string());
	event->init_terms();
	while (i-- > stocker_singleton()->current_pos())
		display->mv_prev();
	return (event);
}
