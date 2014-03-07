#ifndef FT_RESOLVER_H
# define FT_RESOLVER_H

# include "ft_operation.h"
# include "ft_parser.h"


typedef struct s_resolver	t_resolver;
typedef t_operation	t_resop;

struct		s_resolver
{
	void	(*start)(t_pars *ops);
	char	(*resolv_path)(char *);
};

t_resolver	*resolver_singleton(void);
void		ft_resolv_redirects(t_operation *op, t_lex **begin);
char		*ft_resolv_path(char *str);

#endif

