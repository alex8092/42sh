#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

# include "common.h"

typedef struct s_display	t_display;

struct	s_display
{
	int				m_fd;
	char			m_buffer[2048];

	t_display		*(*set_fd)(int fd);
	t_display		*(*init_terms)(t_bool active);
	t_display		*(*putchar)(char c);
	t_display		*(*prompt)(void);
	t_display		*(*mv_prev)(void);
	t_display		*(*mv_next)(void);
	t_display		*(*mv_front)(void);
	t_display		*(*mv_back)(void);
	t_display		*(*rm_cur)(void);
	t_display		*(*rm_prev)(void);
};

t_display	*display_singleton(void);

#endif
