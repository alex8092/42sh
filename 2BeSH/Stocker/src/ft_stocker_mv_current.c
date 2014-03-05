#include "ft_stocker_private.h"

t_stocker	*p_stocker_current_prev(void)
{
	t_lst_stocker		*cursor;
	t_stocker			*stocker;

	stocker = stocker_singleton();
	cursor = stocker->m_current;
	if (!stocker->is_first())
	{
		if (cursor && cursor->prev)
			cursor = cursor->prev;
		stocker->m_current = cursor;
		stocker->m_pos--;
	}
	return (stocker);
}

t_stocker	*p_stocker_current_next(void)
{
	t_lst_stocker		*cursor;
	t_stocker			*stocker;

	stocker = stocker_singleton();
	cursor = stocker->m_current;
	if (!stocker->is_end())
	{
		if (cursor && cursor->next)
			cursor = cursor->next;
		stocker->m_current = cursor;
		stocker->m_pos++;
	}
	return (stocker);
}

t_stocker	*p_stocker_current_front(void)
{
	t_stocker			*stocker;

	stocker = stocker_singleton();
	stocker->m_current = stocker->m_start;
	stocker->m_pos = 0;
	return (stocker);
}

t_stocker	*p_stocker_current_back(void)
{
	t_stocker			*stocker;

	stocker = stocker_singleton();
	stocker->m_current = stocker->m_end;
	stocker->m_pos = stocker->m_length;
	return (stocker);
}
