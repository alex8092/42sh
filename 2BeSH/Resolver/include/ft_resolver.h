#ifndef FT_RESOLVER_H
# define FT_RESOLVER_H

# include "ft_operation.h"
# include "ft_parser.h"

typedef struct s_resolver	t_resolver;

struct		s_resolver
{
	void	(*start)(t_pars *ops);
};

t_resolver	*resolver_singleton(void);

#endif
