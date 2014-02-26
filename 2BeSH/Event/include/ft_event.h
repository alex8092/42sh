#ifndef FT_EVENT_H
# define FT_EVENT_H

typedef struct s_event	t_event;

struct	s_event
{
	t_event	*(*doEvent)(char *c);
};

t_event	*event_singleton();

#endif
