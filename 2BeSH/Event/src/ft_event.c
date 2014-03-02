#include "ft_event.h"
#include "ft_display.h"
#include "ft_stocker.h"
#include "ft_event_private.h"
#include "common.h"
#include <stdlib.h>
#include <unistd.h>

static void	event_init(t_event *event)
{
	p_event_init_attributes(event);
	p_event_init_methodes(event);
	p_event_init_mapping_key(event);
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
