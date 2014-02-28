#include "ft_history_private.h"

void		p_history_init_attributes(t_history *history)
{
	history->size = p_history_size;
}

void		p_stocker_init_methods(t_history *history)
{
	history->length = 0;
}
