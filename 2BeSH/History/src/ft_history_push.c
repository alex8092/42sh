#include "ft_history_private.h"

t_history		*p_history_push(char *str)
{
	t_history		*history;

	history = history_singleton();
	(void)str;
	return (history);
}
