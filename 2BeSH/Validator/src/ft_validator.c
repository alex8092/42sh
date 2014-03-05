#include "ft_validator.h"
#include "ft_security.h"
#include "common.h"
#include <stdlib.h>

static void	validator_init(t_validator *val)
{
	(void)val;
}

t_validator	*validator_singleton(void)
{
	static t_validator	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_validator *)ft_memalloc(sizeof(t_validator));
		if (!singleton)
			security_singleton()->critical("malloc");
		validator_init(singleton);
	}
	return (singleton);
}
