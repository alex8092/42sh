#include "ft_display_private.h"

t_display		*p_display_putchar(char c)
{
	static t_display	*dis = NULL;

	if (!dis)
		dis = display_singleton();
	write(dis->m_fd, &c, 1);
	return (dis);
}
