#ifndef FT_BUILDINS_H
# define FT_BUILDINS_H

# include "common.h"

typedef struct s_buildins	t_buildins;
typedef struct s_buildin	t_buildin;

struct		s_buildins
{
	t_buildin	*m_begin;
	t_buildins	*(*add_buildin)(char *name, void (*)(char **args));
	t_bool		(*is_buildin)(char *);
};

t_buildins	*buildins_singleton();

#endif
