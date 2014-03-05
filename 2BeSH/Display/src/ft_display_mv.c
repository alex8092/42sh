#include "ft_display_private.h"
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
	display->puts("nd");
	return (display);
}

t_display		*p_display_mv_cursor_back(void)
{
	t_display		*display;

	display = display_singleton();
	return (display);
}

t_display		*p_display_mv_cursor_front(void)
{
	t_display		*display;

	display = display_singleton();
	return (display);
}
