#include "ft_stocker_private.h"
#include <stdlib.h>

t_lst_stocker	*p_stocker_new_lst_el(char c)
{
	t_lst_stocker	*el;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	el = (t_lst_stocker*)ft_memalloc(sizeof(t_lst_stocker));
	el->next = 0;
	el->prev = 0;
	el->c = c;
	return (el);
}
