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
		singleton = (t_history*)ft_memalloc(sizeof(t_history));
		history_init(singleton);
	}
	return (singleton);
}
