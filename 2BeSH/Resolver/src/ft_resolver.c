#include "ft_resolver.h"
#include "common.h"
#include "ft_executor.h"
#include "ft_debug.h"
#include <stdio.h>
#include "ft_parser.h"

static void	resolver_start(t_pars *ops)
{
	static t_resolver	*rv = NULL;
	/*char				**tmp;*/

	if (!rv)
		rv = resolver_singleton();
	(void)ops;
}

static void	resolver_init(t_resolver *rv)
{
	rv->start = resolver_start;
}

t_resolver	*resolver_singleton()
{
	static t_resolver	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_resolver*)ft_memalloc(sizeof(t_resolver));
		if (!singleton)
			_exit(1);
		resolver_init(singleton);
	}
	return (singleton);
}

