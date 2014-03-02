#include "ft_event.h"
#include "ft_display.h"
#include "ft_stocker.h"
#include "common.h"
#include <stdlib.h>
#include <unistd.h>

static t_event	*doEvent(char *c)
{
	if (ft_isprint(c[0]) || c[0] == '\n')
	{
		display_singleton()->writec(c[0]);
		if (c[0] != '\n')
			stocker_singleton()->push_back(c[0]);
		int index = 0;
		while (st->size)
		{
			if (st->elem->key == (int)c;
				st->elem->function(...)
		}
		c[0] = 27
		c[1] = 91
		c[2] = 65
	}
	return (event_singleton());
}

static void	event_init(t_event *event)
{
	event->doEvent = doEvent;
}

t_event		*event_singleton(void)
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

struct s_evs
{
	int		key;
	void 	(*function)(...);
	s_evs	*next;
};
