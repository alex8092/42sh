#include "ft_history_private.h"

void		p_history_init_attributes(t_history *history)
{
	history->size = p_history_size;
}

void		p_history_init_methods(t_history *history)
{
	history->m_length = 0;
	history->m_start = 0;
	history->m_end = 0;
	history->m_current = 0;
}
