#include "ft_event_private.h"
#include "ft_stocker.h"

t_event		*p_event_dell_cur(void)
{
	stocker_singleton()->rm_cur();
	return (event_singleton());
}

t_event		*p_event_dell_prev(void)
{
	stocker_singleton()->rm_prev();
	return (event_singleton());
}
