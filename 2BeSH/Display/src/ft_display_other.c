#include "ft_display_private.h"

t_display		*p_display_set_fd(int fd)
{
	static t_display	*display = NULL;

	if (!display)
		display = display_singleton();
	display->m_fd = fd;
	return ((t_display *)display);
}
