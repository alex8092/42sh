#ifndef FT_SECURITY_H
# define FT_SECURITY_H

# include "common.h"

typedef struct s_security	t_security;

struct	s_security
{
	void		(*critical)(char *error);

	t_security	*(*activeRaw)(t_bool);
};

t_security	*security_singleton(void);

#endif
