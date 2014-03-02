#ifndef FT_EVENT_H
# define FT_EVENT_H

typedef struct s_event	t_event;
typedef struct s_event_item	t_event_item;

struct	s_event
{
	t_event_item	*m_begin;
	t_event			*(*doEvent)(char *c);
};

struct				s_event_item
{
	int				key;
	void			(*function)(void);
	t_event_item	*next;
};

t_event			*event_singleton(void);
t_event_item	*p_event_add_item(t_event_item *p, int key, void (*f)(void));
void			p_event_init(t_event *event);

#endif
