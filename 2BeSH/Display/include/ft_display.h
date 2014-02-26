#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

typedef struct s_display	t_display;

struct	s_display
{
	t_display		*(*display_char)(char c);
};

t_display	*display_singleton();

#endif
