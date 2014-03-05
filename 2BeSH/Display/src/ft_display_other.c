#include "ft_display_private.h"
#include "common.h"

t_display		*p_display_set_fd(int fd)
{
	static t_display	*display = NULL;

	if (!display)
		display = display_singleton();
	display->m_fd = fd;
	return ((t_display *)display);
}

t_display		*p_display_set_active(t_bool status)
{
	t_display	*display;

	display = display_singleton();
	display->m_active = status;
	return (display);
}

t_bool			p_display_is_active(void)
{
	return (display_singleton()->m_active);
}
