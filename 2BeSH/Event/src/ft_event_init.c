#include "ft_event_private.h"
#include "ft_stocker.h"
#include <unistd.h>

void		p_event_init_attributes(t_event *event)
{
	t_event_item	*item;
	int				calc;

	calc = (27 << 24) | (91 << 16) | (68 << 8);
	item = p_event_add_item(NULL, calc, (void *)event->map_prev);
	event->m_begin = item;
}

void		p_event_init_methodes(t_event *event)
{
	event->read = p_event_read;
	event->map_prev = p_event_map_prev;
}

void		p_event_init_mapping_key(t_event *event)
{
	t_event_item	*item;
	int				calc;

	calc = (27 << 24) | (91 << 16) | (67 << 8);
	item = p_event_add_item(event->m_begin, calc, (void *)stocker_singleton()->mv_next);
	calc = (27 << 24) | (91 << 16) | (70 << 8) | 0;
	item = p_event_add_item(item, calc, (void *)stocker_singleton()->mv_back);
	calc = (27 << 24) | (91 << 16) | (72 << 8) | 0;
	item = p_event_add_item(item, calc, (void *) stocker_singleton()->mv_front);
	calc = (27 << 24) | (91 << 16) | (51 << 8) | 126;
	item = p_event_add_item(item, calc, (void *) stocker_singleton()->rm_cur);
	calc = (127 << 24) | (0 << 16) | (0 << 8) | 0;
	item = p_event_add_item(item, calc, (void *) stocker_singleton()->rm_prev);

}
