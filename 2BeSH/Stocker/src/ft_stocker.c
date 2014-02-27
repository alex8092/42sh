#include "ft_stocker_private.h"
#include <stdlib.h>

static void			stocker_init(t_stocker *stocker)
{
	stocker->m_length = 0;
	stocker->m_start = 0;
	stocker->m_end = 0;
	stocker->push_back = p_stocker_push_back_lst;
	stocker->push_front = p_stocker_push_front_lst;
	stocker->rm_back = p_stocker_remove_back_lst;
	stocker->rm_front = p_stocker_remove_front_lst;
	stocker->to_string = p_stocker_to_string;
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
