#include "ft_event.h"
#include "ft_display.h"
#include "ft_stocker.h"
#include "common.h"
#include <stdlib.h>
#include <unistd.h>

static t_event	*doEvent(char *c)
{
	t_event_item	*cur;
	int				comp;

	if (ft_isprint(c[0]) || c[0] == '\n')
	{
		display_singleton()->writec(c[0]);
		if (c[0] != '\n')
			stocker_singleton()->push(c[0]);
	}
	else
	{
		cur = event_singleton()->m_begin;
		while (cur)
		{
			comp = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];
			if (comp == cur->key)
			{
				cur->function();
				break ;
			}
			cur = cur->next;
		}
	}
	return (event_singleton());
}

static void	event_init(t_event *event)
{
	event->doEvent = doEvent;
	p_event_init(event);
}

t_event		*event_singleton(void)
{
	static t_event	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_event*)ft_memalloc(sizeof(t_event));
		if (!singleton)
			exit(1);
		event_init(singleton);
	}
	return (singleton);
}
