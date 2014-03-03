#include "ft_event_private.h"
#include "ft_display.h"
#include "ft_stocker.h"

t_event		*p_event_map_rm_cur(void)
{
	stocker_singleton()->rm_cur();
	display_singleton()->rm_cur();
	return (event_singleton());
}

t_event		*p_event_map_rm_prev(void)
{
	stocker_singleton()->rm_prev();
	display_singleton()->rm_prev();
	return (event_singleton());
}
