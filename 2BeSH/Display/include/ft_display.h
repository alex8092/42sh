#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

# include "common.h"

typedef struct s_display	t_display;

struct	s_display
{
	int				m_fd;

	char			m_buffer[2048];

	t_bool			m_active;

	void			(*resize)(int);

	int				(*height)(void);
	int				(*width)(void);

	t_bool			(*is_active)(void);

	t_display		*(*set_active)(t_bool);
	t_display		*(*set_fd)(int);
	t_display		*(*putchar)(char);
	t_display		*(*putstr)(char *);
	t_display		*(*puts)(char *);
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
