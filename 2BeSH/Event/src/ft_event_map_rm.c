/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_map_rm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:49 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:48:16 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_event_private.h"
#include "ft_display.h"
#include "ft_stocker.h"
#include "ft_history.h"
#include <stdlib.h>

t_event		*p_event_map_rm_cur(void)
{
	if (!stocker_singleton()->is_end())
	{
		stocker_singleton()->rm_cur();
		display_singleton()->rm_cur();
		p_event_reprint_str();
	}
	if (history_singleton()->m_active)
		free(history_singleton()->m_active);
	history_singleton()->m_active = stocker_singleton()->to_string();
	history_singleton()->m_current = 0;
	return (event_singleton());
}

t_event		*p_event_map_rm_prev(void)
{
	if (!stocker_singleton()->is_first())
	{
		stocker_singleton()->rm_prev();
		display_singleton()->rm_prev();
		p_event_reprint_str();
	}
	if (history_singleton()->m_active)
		free(history_singleton()->m_active);
	history_singleton()->m_active = stocker_singleton()->to_string();
	history_singleton()->m_current = 0;
	return (event_singleton());
}
