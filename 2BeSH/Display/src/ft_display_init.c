#include "ft_display_private.h"

void		p_display_init_attributes(t_display *display)
{
	display->m_fd = 1;
}

void		p_display_init_methodes(t_display *display)
{
	display->putchar = p_display_putchar;
	display->set_fd = p_display_set_fd;
	display->prompt = p_display_write_prompt;
	display->mv_prev = p_display_mv_cursor_prev;
	display->mv_next = p_display_mv_cursor_next;
	display->mv_front = p_display_mv_cursor_front;
	display->mv_back = p_display_mv_cursor_back;
	display->rm_cur = p_display_rm_cursor;
	display->rm_prev = p_display_rm_previous_cursor;
}
