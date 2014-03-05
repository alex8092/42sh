#ifndef FT_DISPLAY_PRIVATE_H
# define FT_DISPLAY_PRIVATE_H

# include "ft_display.h"
# include "common.h"

void			p_display_init_attributes(t_display *display);
void			p_display_init_methodes(t_display *display);

t_bool			p_display_is_active(void);

t_display		*p_display_putchar(char);
t_display		*p_display_putstr(char *);
t_display		*p_display_set_fd(int);
t_display		*p_display_write_prompt(void);
t_display		*p_display_mv_cursor_prev(void);
t_display		*p_display_mv_cursor_next(void);
t_display		*p_display_mv_cursor_front(void);
t_display		*p_display_mv_cursor_back(void);
t_display		*p_display_rm_cursor(void);
t_display		*p_display_rm_previous_cursor(void);
t_display		*p_display_set_active(t_bool);
t_display		*p_display_termcaps_puts(char *);

#endif
