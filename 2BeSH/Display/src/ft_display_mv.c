#include "ft_display_private.h"
#include "ft_stocker.h"
#include "common.h"

t_display		*p_display_mv_cursor_prev(void)
{
	t_display		*display;

	display = display_singleton();
	display->puts("le");
	return (display);
}

t_display		*p_display_mv_cursor_next(void)
{
	t_display		*display;

	display = display_singleton();
	display->putchar(stocker_singleton()->char_current());
	return (display);
}
