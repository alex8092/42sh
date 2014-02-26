#include "ft_stocker_private.h"
#include <stdlib.h>

t_lst_stocker	*p_stocker_new_lst()
{
	t_lst_stocker	*lst;

	lst = (t_lst_stocker*)malloc(sizeof(t_lst_stocker));
	lst->prev = 0;
	lst->next = 0;
	return (lst);
}

t_lst_stocker	*p_stocker_new_lst_el(char c)
{
	t_lst_stocker	*el;

	el = (t_lst_stocker*)malloc(sizeof(t_lst_stocker));
	el->next = el;
	el->prev = el;
	el->c = c;
	return (el);
}

void			p_stocker_add_back_lst(t_lst_stocker *el)
{
	(void)el;
}

void			p_stocker_add_front_lst(t_lst_stocker *el)
{
	(void)el;
}
