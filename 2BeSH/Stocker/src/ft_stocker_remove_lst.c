#include "ft_stocker_private.h"
#include <stdlib.h>
#include <stdio.h>

t_stocker		*p_stocker_remove_back_lst(void)
{
	t_stocker		*stocker;

	stocker = stocker_singleton();
	if (stocker->m_end)
	{
		if (stocker->m_end->prev)
		{
			stocker->m_end = stocker->m_end->prev;
			free(stocker->m_end->next);
			stocker->m_end->next = 0;
		}
		else
		{
			free(stocker->m_start);
			stocker->m_start = 0;
			stocker->m_end = 0;
		}
		stocker->m_length--;
	}
	stocker->m_current = stocker->m_end;
	return (stocker);
}

t_stocker		*p_stocker_remove_front_lst(void)
{
	t_stocker		*stocker;

	stocker = stocker_singleton();
	if (stocker->m_start)
	{
		if (stocker->m_start->next)
		{
			stocker->m_start = stocker->m_start->next;
			if (stocker->m_start->prev)
				free(stocker->m_start->prev);
			stocker->m_start->prev = 0;
		}
		else
		{
			free(stocker->m_start);
			stocker->m_start = 0;
			stocker->m_end = 0;
		}
		stocker->m_length--;
	}
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
	if (current && current->prev)
	{
		tmp = current->prev;
		current->prev = tmp->prev;
		tmp->prev->next = current;
		free(tmp);
	}
	return (stocker);
}

t_stocker		*p_stocker_remove_next_lst(void)
{
	t_lst_stocker	*current;
	t_lst_stocker	*tmp;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	current = stocker->m_current;
	if (current &&current->next)
	{
		tmp = current->next;
		current->next = tmp->next;
		tmp->next->prev = current;
		free(tmp);
	}
	return (stocker);
}

t_stocker		*p_stocker_clean_lst(void)
{
	t_lst_stocker	*cursor;
	t_lst_stocker	*tmp;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	if (stocker->m_length > 0)
	{
		cursor = stocker->m_start;
		while (cursor)
		{
			tmp = cursor->next;
			free(cursor);
			cursor = tmp;
		}
		stocker->m_length = 0;
		stocker->m_start = 0;
		stocker->m_end = 0;
	}
	return (stocker);
}
