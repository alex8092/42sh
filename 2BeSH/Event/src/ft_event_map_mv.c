#include "ft_event_private.h"
#include "ft_stocker.h"

t_event		*p_event_map_prev(void)
{
	stocker_singleton()->mv_prev();
	return (event_singleton());
}

t_event		*p_event_map_next(void)
{
	stocker_singleton()->mv_next();
	return (event_singleton());
}

t_event		*p_event_map_back(void)
{
	stocker_singleton()->mv_back();
	return (event_singleton());
}

t_event		*p_event_map_front(void)
{
	stocker_singleton()->mv_front();
	return (event_singleton());
}
