#include "ft_display_private.h"

t_display		*p_display_rm_cursor(void)
{
	t_display		*display;

	display = display_singleton();
	return (display);
}

t_display		*p_display_rm_previous_cursor(void)
{
	t_display	*display;

	display = display_singleton();
	return (display);
}
