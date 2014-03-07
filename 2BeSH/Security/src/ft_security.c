#include "ft_security_private.h"
#include <stdlib.h>

static void	secu_init(t_security *security)
{
	p_security_init_attributes(security);
	p_security_init_methodes(security);
	p_security_init_signal();
}

t_security	*security_singleton(void)
{
	static t_security	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_security*)malloc(sizeof(t_security));
		if (!singleton)
			_exit(1);
		secu_init(singleton);
	}
	return (singleton);
}
