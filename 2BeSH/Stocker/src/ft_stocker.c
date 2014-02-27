#include "ft_stocker_private.h"
#include <stdlib.h>

static void			stocker_init(t_stocker *stocker)
{
	p_stocker_init_attributes(stocker);
	p_stocker_init_methods(stocker);
}


t_stocker			*stocker_singleton()
{
	static t_stocker	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_stocker*)malloc(sizeof(t_stocker));
		if (!singleton)
			exit(1);
		stocker_init(singleton);
	}
	return (singleton);
}
