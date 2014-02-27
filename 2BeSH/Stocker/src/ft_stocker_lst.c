#include "ft_stocker_private.h"
#include <stdlib.h>

t_lst_stocker	*p_stocker_new_lst_el(char c)
{
	t_lst_stocker	*el;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	el = (t_lst_stocker*)malloc(sizeof(t_lst_stocker));
	el->next = 0;
	el->prev = 0;
	el->is_print = true;
	el->c = c;
	stocker->m_current = el;
	stocker->m_length++;
	return (el);
}

char			*p_stocker_to_string(void)
{
	t_stocker		*stocker;
	t_lst_stocker	*cursor;
	char			*str;
	int				i;

	i = 0;
	stocker = stocker_singleton();
	str = (char*)malloc(sizeof(sizeof(char) * (stocker->m_length + 1)));
	cursor = stocker->m_start;
	while (i < stocker->m_length)
	{
		if (cursor->is_print)
		{
			str[i] = cursor->c;
			i++;
		}
		cursor = cursor->next;
	}
	str[i] = 0;
	return (str);
}
