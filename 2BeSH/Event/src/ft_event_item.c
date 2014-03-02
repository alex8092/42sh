#include "ft_event.h"
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
}

