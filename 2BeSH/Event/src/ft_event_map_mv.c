/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_map_mv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:45 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:48:10 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_event_private.h"
#include "ft_display.h"
#include "ft_stocker.h"

t_event		*p_event_map_prev(void)
{
	if (!stocker_singleton()->is_first())
	{
		stocker_singleton()->mv_prev();
		display_singleton()->mv_prev();
	}
	return (event_singleton());
}

t_event		*p_event_map_next(void)
{
	if (!stocker_singleton()->is_end())
	{
		display_singleton()->mv_next();
		stocker_singleton()->mv_next();
	}
	return (event_singleton());
}

t_event		*p_event_map_back(void)
{
	while (!stocker_singleton()->is_end())
	{
		display_singleton()->mv_next();
		stocker_singleton()->mv_next();
	}
	return (event_singleton());
}

t_event		*p_event_map_front(void)
{
	while (!stocker_singleton()->is_first())
	{
		event_singleton()->mv_prev();
	}
	return (event_singleton());
}

t_event		*p_event_map_silent(void)
{
	return (event_singleton());
}
