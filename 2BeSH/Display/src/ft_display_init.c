#include "ft_display_private.h"

void		p_display_init_attributes(t_display *display)
{
	display->m_fd = 1;
}

void		p_display_init_methodes(t_display *display)
{
	display->writec = p_display_write_char;
	display->set_fd = p_display_set_fd;
}
