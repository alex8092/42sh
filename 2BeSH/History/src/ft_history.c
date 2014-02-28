#include "ft_history_private.h"
#include <stdlib.h>

static void			history_init(t_history *history)
{
	p_history_init_attributes(history);
	p_history_init_methods(history);
}


t_history			*history_singleton(void)
{
	static t_history	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_history*)malloc(sizeof(t_history));
		if (!singleton)
			exit(1);
		history_init(singleton);
	}
	return (singleton);
}
