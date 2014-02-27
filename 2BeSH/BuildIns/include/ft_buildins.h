#ifndef FT_BUILDINS_H
# define FT_BUILDINS_H

# include "common.h"

typedef struct s_buildins	t_buildins;

struct		s_buildins
{
	t_bool	(*is_buildin)(char *);
};

t_buildins	*buildins_singleton();

#endif
