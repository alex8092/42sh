#include "ft_stocker_private.h"

t_stocker		*p_stocker_remove_back_lst(void)
{
	t_stocker		*stocker;

	stocker = stocker_singleton();
	return (stocker);
}

t_stocker		*p_stocker_remove_front_lst(void)
{
	t_stocker		*stocker;

	stocker = stocker_singleton();
	return (stocker);
}
