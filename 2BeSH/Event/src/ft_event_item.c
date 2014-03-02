#include "ft_event.h"
#include "ft_stocker.h"
#include "common.h"
#include <unistd.h>

t_event_item	*p_event_add_item(t_event_item *p, int key, void (*f)(void))
{
	t_event_item	*item;

	item = (t_event_item *)ft_memalloc(sizeof(t_event_item));
	if (!item)
		_exit(1);
	item->key = key;
	item->function = f;
	if (p != NULL)
		p->next = item;
	return (item);
}

static void ft_ev_key_up()
{
}

void			p_event_init(t_event *event)
{
	t_event_item	*item;
	int				calc;

	calc = (27 << 24) | (91 << 16) | (65 << 8);
	item = p_event_add_item(NULL, calc, ft_ev_key_up);
	event->m_begin = item;
	calc = (27 << 24) | (91 << 16) | (68 << 8);
	item = p_event_add_item(item, calc, (void *)stocker_singleton()->mv_prev);
	calc = (27 << 24) | (91 << 16) | (67 << 8);
	item = p_event_add_item(item, calc, (void *)stocker_singleton()->mv_next);
	calc = (27 << 24) | (91 << 16) | (52 << 8) | 126;
	item = p_event_add_item(item, calc, (void *)stocker_singleton()->mv_back);
	calc = (27 << 14) | (91 << 16) | (49 << 8) | 126;
	item = p_event_add_item(item, calc, (void *) stocker_singleton()->mv_front);
	calc = (27 << 24) | (91 << 16) | (51 << 8) | 126;
	item = p_event_add_item(item, calc, (void *) stocker_singleton()->rm_cur);
	calc = 127;
	item = p_event_add_item(item, calc, (void *) stocker_singleton()->rm_prev);
}

