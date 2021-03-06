/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocker_remove_lst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:56 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:51:13 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stocker_private.h"
#include <stdlib.h>

t_stocker		*p_stocker_remove_back_lst(void)
{
	t_stocker		*stocker;

	stocker = stocker_singleton();
	stocker = stocker_singleton()->mv_back()->rm_prev();
	stocker->m_current = stocker->m_end;
	return (stocker);
}

t_stocker		*p_stocker_remove_front_lst(void)
{
	t_stocker		*stocker;

	stocker = stocker_singleton()->mv_front()->rm_cur();
	stocker->m_current = stocker->m_start;
	return (stocker);
}

t_stocker		*p_stocker_remove_prev_lst(void)
{
	t_lst_stocker	*current;
	t_lst_stocker	*tmp;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	current = stocker->m_current;
	if (!stocker->is_first())
	{
		tmp = current->prev;
		if (tmp->prev)
		{
			current->prev = tmp->prev;
			tmp->prev->next = current;
		}
		else
		{
			current->prev = 0;
			stocker->m_start = current;
		}
		stocker->m_length--;
		stocker->m_pos--;
		free(tmp);
	}
	return (stocker);
}

t_stocker		*p_stocker_remove_current_lst(void)
{
	t_lst_stocker	*current;
	t_lst_stocker	*tmp;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	current = stocker->m_current;
	if (stocker->m_pos < stocker->m_length)
	{
		tmp = current->next;
		if (current->prev)
		{
			current->prev->next = tmp;
			tmp->prev = current->prev;
		}
		else
		{
			tmp->prev = 0;
			stocker->m_start = tmp;
		}
		free(current);
		stocker->m_length--;
		stocker->m_current = tmp;
	}
	return (stocker);
}

t_stocker		*p_stocker_clean_lst(void)
{
	t_lst_stocker	*cursor;
	t_lst_stocker	*tmp;
	t_stocker		*stocker;
	int				i;

	i = 0;
	stocker = stocker_singleton();
	if (stocker->m_length > 0)
	{
		tmp = NULL;
		cursor = stocker->m_start;
		while (cursor->c && ((tmp = cursor->next) || true))
		{
			free(cursor);
			cursor = tmp;
			i++;
		}
		cursor->prev = 0;
		stocker->m_length = 0;
		stocker->m_pos = 0;
		stocker->m_start = tmp;
		stocker->m_end = tmp;
		stocker->m_current = tmp;
	}
	return (stocker);
}
