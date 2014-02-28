#ifndef FT_BUILDINS_H
# define FT_BUILDINS_H

# include "common.h"

typedef struct s_buildins	t_buildins;
typedef struct s_buildin	t_buildin;

struct		s_buildins
{
	t_buildin	*m_begin;
	t_bool		(*is_buildin)(char *);
	int			(*exec)(char *, char **);
};

t_buildins	*buildins_singleton(void);

#endif
