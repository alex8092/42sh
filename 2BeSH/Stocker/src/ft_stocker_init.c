#include "ft_stocker_private.h"

void		p_stocker_init_attributes(t_stocker *stocker)
{
	stocker->m_length = 0;
	stocker->m_start = 0;
	stocker->m_end = 0;
	stocker->m_current = 0;
}

void		p_stocker_init_methods(t_stocker*stocker)
{
	stocker->push = p_stocker_after_current_push;
	stocker->push_back = p_stocker_push_back_lst;
	stocker->push_front = p_stocker_push_front_lst;
	stocker->rm_back = p_stocker_remove_back_lst;
	stocker->rm_front = p_stocker_remove_front_lst;
	stocker->rm_prev = p_stocker_remove_prev_lst;
	stocker->rm_next = p_stocker_remove_next_lst;
	stocker->clean = p_stocker_clean_lst;
	stocker->mv_prev = p_stocker_current_prev;
	stocker->mv_next = p_stocker_current_next;
	stocker->mv_front = p_stocker_current_front;
	stocker->mv_back = p_stocker_current_back;
	stocker->size = p_stocker_size;
	stocker->to_string = p_stocker_to_string;
}
