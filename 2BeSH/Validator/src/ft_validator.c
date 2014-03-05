#include "ft_validator.h"
#include "common.h"
#include "ft_environment.h"
#include <stdlib.h>
#include <stdio.h>

static t_bool	is_valid(t_operation *op)
{
	char	*str;

	str = env_singleton()->get("PATH");
	printf("path : %s\n", str);
	(void)op;
	return (true);
}

static void		validator_init(t_validator *val)
{
	val->is_valid = is_valid;
	(void)val;
}

t_validator	*validator_singleton(void)
{
	static t_validator	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_validator *)ft_memalloc(sizeof(t_validator));
		validator_init(singleton);
	}
	return (singleton);
}
