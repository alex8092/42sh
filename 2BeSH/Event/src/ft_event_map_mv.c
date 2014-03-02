#include "ft_event_private.h"
#include "ft_stocker.h"

t_event		*p_event_map_prev(void)
{
	stocker_singleton()->mv_prev();
	return (event_singleton());
}
