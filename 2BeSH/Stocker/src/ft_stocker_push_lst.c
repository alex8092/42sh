/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocker_push_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:51 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:51:08 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stocker_private.h"

t_stocker		*p_stocker_push_back_lst(char c)
{
	t_stocker		*stocker;

	stocker = stocker_singleton()->mv_back()->push(c);
	stocker->m_current = stocker->m_end;
	stocker->m_pos = stocker->m_length - 1;
	return (stocker);
}

t_stocker		*p_stocker_push_front_lst(char c)
{
	t_stocker		*stocker;

	stocker = stocker_singleton()->mv_front()->push(c);
	stocker->m_current = stocker->m_start;
	stocker->m_pos = 0;
	return (stocker);
}

t_stocker		*p_stocker_after_current_push(char c)
{
	t_lst_stocker		*el;
	t_lst_stocker		*current;
	t_stocker			*stocker;

	stocker = stocker_singleton();
	current = stocker->m_current;
	el = p_stocker_new_lst_el(c);
	if (current->prev)
	{
		el->prev = current->prev;
		current->prev->next = el;
	}
	else
		stocker->m_start = el;
	current->prev = el;
	el->next = current;
	stocker->m_pos++;
	stocker->m_length++;
	return (stocker);
}

t_stocker		*p_stocker_push_str(char *str)
{
	t_stocker	*stocker;
	int			i;

	i = 0;
	stocker = stocker_singleton();
	if (str)
	{
		while (str[i])
			stocker->push(str[i++]);
	}
	return (stocker);
}
