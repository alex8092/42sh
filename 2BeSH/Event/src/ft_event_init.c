#include "ft_event_private.h"
#include "ft_stocker.h"
#include "ft_environment.h"
#include <unistd.h>

void		p_event_init_attributes(t_event *event)
{
	(void)event;
}

void		p_event_init_methodes(t_event *event)
{
	event->read = p_event_read;
	event->map_prev = p_event_map_prev;
	event->map_next = p_event_map_next;
	event->map_back = p_event_map_back;
	event->map_front = p_event_map_front;
	event->dell_cur = p_event_dell_cur;
	event->dell_prev = p_event_dell_prev;
}

void		p_event_init_mapping_key(t_event *event)
{
	t_event_item	*item;
	int				calc;

	if (!env_singleton()->get("TERM"))
	{
		calc = (27 << 24) | (91 << 16) | (68 << 8);
		item = p_event_add_item(NULL, calc, (void *)event->map_prev);
		event->m_begin = item;
		calc = (27 << 24) | (91 << 16) | (67 << 8);
		item = p_event_add_item(item, calc, (void *)event->map_next);
		calc = (27 << 24) | (91 << 16) | (70 << 8) | 0;
		item = p_event_add_item(item, calc, (void *)event->map_back);
		calc = (27 << 24) | (91 << 16) | (72 << 8) | 0;
		item = p_event_add_item(item, calc, (void *)event->map_front);
		calc = (27 << 24) | (91 << 16) | (51 << 8) | 126;
		item = p_event_add_item(item, calc, (void *)event->dell_cur);
		calc = (127 << 24) | (0 << 16) | (0 << 8) | 0;
		item = p_event_add_item(item, calc, (void *)event->dell_prev);
	}
}
