#include "ft_event_private.h"
#include "ft_display.h"
#include "ft_stocker.h"

t_event		*p_event_map_rm_cur(void)
{
	if (!stocker_singleton()->is_end())
	{
		display_singleton()->rm_cur();
		stocker_singleton()->rm_cur();
	}
	return (event_singleton());
}

t_event		*p_event_map_rm_prev(void)
{
	if (!stocker_singleton()->is_first())
	{
		display_singleton()->rm_prev();
		stocker_singleton()->rm_prev();
	}
	return (event_singleton());
}
