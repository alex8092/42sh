#include "ft_stocker_private.h"
#include "common.h"

t_bool		p_stocker_is_end(void)
{
	t_stocker	*stocker;

	stocker = stocker_singleton();
	if (stocker->m_pos == stocker->m_length)
		return (true);
	else
		return (false);
}

t_bool		p_stocker_is_first(void)
{
	t_stocker	*stocker;

	stocker = stocker_singleton();
	if (stocker->m_pos == 0)
		return (true);
	else
		return (false);
}
