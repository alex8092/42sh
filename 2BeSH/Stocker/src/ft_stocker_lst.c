#include "ft_stocker_private.h"
#include "ft_security.h"
#include <stdlib.h>

t_lst_stocker	*p_stocker_new_lst_el(char c)
{
	t_lst_stocker	*el;
	t_stocker		*stocker;

	stocker = stocker_singleton();
	el = (t_lst_stocker*)malloc(sizeof(t_lst_stocker));
	if (!el)
		security_singleton()->critical("malloc");
	el->next = 0;
	el->prev = 0;
	el->c = c;
	return (el);
}
