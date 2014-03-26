/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocker_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 07:02:16 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 07:02:19 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stocker_private.h"

void		p_stocker_init_attributes(t_stocker *stocker)
{
	t_lst_stocker		*first;

	first = p_stocker_new_lst_el(0);
	stocker->m_length = 0;
	stocker->m_start = first;
	stocker->m_end = first;
	stocker->m_current = first;
	stocker->m_pos = 0;
}

void		p_stocker_init_methods(t_stocker*stocker)
{
	stocker->push = p_stocker_after_current_push;
	stocker->push_str = p_stocker_push_str;
	stocker->push_back = p_stocker_push_back_lst;
	stocker->push_front = p_stocker_push_front_lst;
	stocker->rm_back = p_stocker_remove_back_lst;
	stocker->rm_front = p_stocker_remove_front_lst;
	stocker->rm_prev = p_stocker_remove_prev_lst;
	stocker->rm_cur = p_stocker_remove_current_lst;
	stocker->clean = p_stocker_clean_lst;
	stocker->mv_prev = p_stocker_current_prev;
	stocker->mv_next = p_stocker_current_next;
	stocker->mv_front = p_stocker_current_front;
	stocker->mv_back = p_stocker_current_back;
	stocker->size = p_stocker_size;
	stocker->to_string = p_stocker_to_string;
	stocker->is_end = p_stocker_is_end;
	stocker->is_first = p_stocker_is_first;
	stocker->char_current = p_stocker_get_current_char;
	stocker->current_pos = p_stocker_get_current_pos;
}
