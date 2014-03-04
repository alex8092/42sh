#ifndef FT_DISPLAY_PRIVATE_H
# define FT_DISPLAY_PRIVATE_H

# include "ft_display.h"

void			p_display_init_attributes(t_display *display);
void			p_display_init_methodes(t_display *display);

t_display		*p_display_putchar(char c);
t_display		*p_display_set_fd(int fd);
t_display		*p_display_write_prompt(void);
t_display		*p_display_mv_cursor_prev(void);
t_display		*p_display_mv_cursor_next(void);
t_display		*p_display_mv_cursor_front(void);
t_display		*p_display_mv_cursor_back(void);
t_display		*p_display_rm_cursor(void);
t_display		*p_display_rm_previous_cursor(void);

#endif
