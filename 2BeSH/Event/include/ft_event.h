#ifndef FT_EVENT_H
# define FT_EVENT_H

# include "common.h"

typedef struct s_event	t_event;
typedef struct s_event_item	t_event_item;

struct	s_event
{
	t_event_item	*m_begin;

	t_event			*(*read)(char *c);
	t_event			*(*map_prev)(void);
	t_event			*(*map_next)(void);
	t_event			*(*map_back)(void);
	t_event			*(*map_front)(void);
	t_event			*(*rm_cur)(void);
	t_event			*(*rm_prev)(void);
	t_event			*(*init_terms)(void);
};

t_event			*event_singleton(void);

#endif
