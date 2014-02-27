#include "ft_stocker_private.h"
#include <stdlib.h>

t_lst_stocker	*p_stocker_new_lst_el(char c)
{
	t_lst_stocker	*el;

	el = (t_lst_stocker*)malloc(sizeof(t_lst_stocker));
	el->next = 0;
	el->prev = 0;
	el->is_print = true;
	el->c = c;
	return (el);
}
