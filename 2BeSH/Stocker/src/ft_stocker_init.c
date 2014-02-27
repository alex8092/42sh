#include "ft_stocker_private.h"

void		p_stocker_init_methods(t_stocker*stocker)
{
	stocker->push_back = p_stocker_push_back_lst;
	stocker->push_front = p_stocker_push_front_lst;
	stocker->rm_back = p_stocker_remove_back_lst;
	stocker->rm_front = p_stocker_remove_front_lst;
	stocker->to_string = p_stocker_to_string;
	stocker->size = p_stocker_size;
}

void		p_stocker_init_attributes(t_stocker *stocker)
{
	stocker->m_length = 0;
	stocker->m_start = 0;
	stocker->m_end = 0;
}
