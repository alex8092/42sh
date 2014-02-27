#include "ft_stocker_private.h"

t_stocker		*p_stocker_remove_back_lst(void)
{
	t_stocker		*stocker;
	t_lst_stocker	*cursor;

	stocker = stocker_singleton();
	cursor = stocker->m_end;
	while (cursor && !cursor->is_print)
		cursor = cursor->prev;
	if (cursor)
	{
		cursor->is_print = false;
		stocker->m_length--;
	}
	return (stocker);
}

t_stocker		*p_stocker_remove_front_lst(void)
{
	t_stocker		*stocker;
	t_lst_stocker	*cursor;

	stocker = stocker_singleton();
	cursor = stocker->m_start;
	while (cursor && !cursor->is_print)
		cursor = cursor->next;
	if (cursor)
	{
		cursor->is_print = false;
		stocker->m_length--;
	}
	return (stocker);
}
