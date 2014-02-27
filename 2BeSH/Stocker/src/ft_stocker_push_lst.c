#include "ft_stocker_private.h"

t_stocker		*p_stocker_push_back_lst(char c)
{
	t_lst_stocker	*el;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	el = p_stocker_new_lst_el(c);
	if (stocker->m_length > 1)
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
	return (stocker);
}

t_stocker		*p_stocker_push_front_lst(char c)
{
	t_lst_stocker	*el;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	el = p_stocker_new_lst_el(c);
	if (stocker->m_length > 1)
	{
		el->next = stocker->m_start;
		stocker->m_start->prev = el;
		stocker->m_start = stocker->m_start->prev;
	}
	else
	{
		stocker->m_start = el;
		stocker->m_end = el;
	}
	return (stocker);
}

t_stocker	*p_stocker_after_current_push(char c)
{
	t_lst_stocker	*el;
	t_lst_stocker	*current;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	current = stocker->m_current;
	el = p_stocker_new_lst_el(c);
	if (stocker->m_length > 1)
	{
		if (stocker->m_current->next)
		{
			el->next = current->next;
			el->next->prev = el;
		}
		else
			stocker->m_end = el;
		current->next = el;
	}
	else
	{
		stocker->m_start = el;
		stocker->m_end = el;
	}
	return (stocker);
}
