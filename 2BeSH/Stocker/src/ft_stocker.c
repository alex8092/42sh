#include "ft_stocker_private.h"
#include <stdlib.h>

static void			stocker_init(t_stocker *stocker)
{
	stocker->length = 0;
	stocker->m_start = 0;
	stocker->m_end = 0;
	stocker->add_back = p_stocker_add_back_lst;
	stocker->add_front = p_stocker_add_front_lst;
	stocker->size = p_stocker_size;
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
