#include "ft_event.h"
#include "ft_display.h"
#include "common.h"
#include <stdlib.h>
#include <unistd.h>

static t_event	*doEvent(char *c)
{
	if (ft_isprint(c[0]) || c[0] == '\n')
		display_singleton()->writec(c[0]);
	return (event_singleton());
}

static void	event_init(t_event *event)
{
	event->doEvent = doEvent;
}

t_event		*event_singleton()
{
	static t_event	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_event*)malloc(sizeof(t_event));
		if (!singleton)
			exit(1);
		event_init(singleton);
	}
	return (singleton);
}
