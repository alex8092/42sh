/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:41:05 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:49:14 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_history_private.h"
#include "ft_stocker.h"
#include <stdlib.h>

int			p_history_size(void)
{
	return (history_singleton()->m_length);
}

t_history	*p_history_save_active(void)
{
	t_stocker	*stocker;
	t_history	*history;

	history = history_singleton();
	stocker = stocker_singleton();
	if (history->m_active
		&& !ft_strcmp(stocker->to_string(), history->m_active))
		free(history->m_active);
	history->m_active = ft_strdup(stocker->to_string());
	return (history);
}

t_bool		p_history_is_end(void)
{
	t_history	*history;

	history = history_singleton();
	if (history->m_pos == (history->m_length - 1))
		return (true);
	else
		return (false);
}

t_bool		p_history_is_first(void)
{
	t_history	*history;

	history = history_singleton();
	if (history->m_pos == 1)
		return (true);
	else
		return (false);
}
