#ifndef FT_EVENT_PRIVATE_H
# include "ft_event.h"
#include "common.h"

struct				s_event_item
{
	int				key;
	void			(*function)(void);
	t_event_item	*next;
};

void		p_event_init_attributes(t_event *event);
void		p_event_init_methodes(t_event *event);
void		p_event_init_mapping_key(t_event *event);

t_event		*p_event_map_rm_prev(void);
t_event		*p_event_map_rm_cur(void);
t_event		*p_event_map_front(void);
t_event		*p_event_map_back(void);
t_event		*p_event_map_next(void);
t_event		*p_event_map_prev(void);
t_event		*p_event_read(char *c);
t_event		*p_event_init_terms(void);

t_event_item	*p_event_add_item(t_event_item *p, int key, void (*f)(void));

#endif
