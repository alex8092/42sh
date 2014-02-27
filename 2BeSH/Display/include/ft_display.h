#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

# include "common.h"

typedef struct s_display	t_display;

struct	s_display
{
	t_display		*(*init_terms)(t_bool active);
	t_display		*(*display_char)(char c);
};

t_display	*display_singleton();

#endif
