#include "ft_stocker_private.h"

t_stocker		*p_stocker_add_back_lst(char c)
{
	t_lst_stocker	*el;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	el = p_stocker_new_lst_el(c);
	if (stocker->length != 0)
	{
		el->prev = stocker->m_end;
		stocker->m_end->next = el;
		stocker->m_end = stocker->m_end->next;
	}
	else
	{
		stocker->m_start = el;
		stocker->m_end = el;
	}
	stocker->length++;
	return (stocker);
}

t_stocker		*p_stocker_add_front_lst(char c)
{
	t_lst_stocker	*el;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	el = p_stocker_new_lst_el(c);
	if (stocker->length != 0)
	{
		el->next = stocker->m_start;
		stocker->m_start->prev = el;
		stocker->m_start = stocker->m_start->prev;
	}
	else
	{
		stocker->m_start = el;
		stocker->m_end =el;
	}
	stocker->length++;
	return (stocker);
}
