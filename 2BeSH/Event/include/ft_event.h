#ifndef FT_EVENT_H
# define FT_EVENT_H

typedef struct s_event	t_event;
typedef struct s_event_item	t_event_item;

struct	s_event
{
	t_event_item	*m_begin;

	t_event			*(*read)(char *c);
	t_event			*(*map_prev)(void);
};

t_event			*event_singleton(void);

#endif
