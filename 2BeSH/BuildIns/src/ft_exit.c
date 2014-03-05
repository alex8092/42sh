#include "ft_buildins_private.h"
#include "ft_security.h"
#include <stdio.h>

void	p_buildins_exit(char **argv)
{
	(void)argv;
	security_singleton()->activeRaw(false);
	_exit(0);
}
