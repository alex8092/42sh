#include "ft_parser_private.h"
#include "ft_security.h"

t_pars	*p_pars_init(void)
{
	t_pars	*init;

	init = (t_pars*)ft_memalloc(sizeof(t_pars));
	if (!init)
		security_singleton()->critical("malloc");
	return (init);
}
