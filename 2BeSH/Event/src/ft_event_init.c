/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:34 by triviere          #+#    #+#             */
/*   Updated: 2014/03/27 20:47:31 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_event_private.h"
#include "ft_display.h"

void		p_event_init_attributes(t_event *event)
{
	(void)event;
}

void		p_event_init_methodes(t_event *event)
{
	event->read = p_event_read;
	event->mv_prev = p_event_map_prev;
	event->mv_next = p_event_map_next;
	event->mv_back = p_event_map_back;
	event->mv_front = p_event_map_front;
	event->mv_up = p_event_map_history_prev;
	event->mv_down = p_event_map_history_next;
	event->mv_mup = p_event_map_history_mprev;
	event->mv_mdown = p_event_map_history_mnext;
	event->mv_word_prev = p_event_map_word_prev;
	event->mv_word_next = p_event_map_word_next;
	event->rm_cur = p_event_map_rm_cur;
	event->rm_prev = p_event_map_rm_prev;
	event->init_terms = p_event_init_terms;
	event->reset = p_event_reset;
	event->clean = p_event_map_clean;
	event->end = p_event_end;
}

static void	p_event_map_silent_ctrls(t_event_item *item)
{
	item = p_event_add_item(item, CTRLW_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLX_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLF_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLU_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLD_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLA_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLE_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLR_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLT_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLP_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLH_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLK_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLB_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLN_KEY, (void *)p_event_map_silent);
	item = p_event_add_item(item, CTRLTAB_KEY, (void *)p_event_map_silent);
}

void		p_event_init_mapping_key(t_event *event)
{
	t_event_item	*item;

	event->init_terms();
	if (display_singleton()->is_active())
	{
		item = p_event_add_item(NULL, PREV_KEY, (void *)event->mv_prev);
		event->m_begin = item;
		item = p_event_add_item(item, NEXT_KEY, (void *)event->mv_next);
		item = p_event_add_item(item, BACK_KEY, (void *)event->mv_back);
		item = p_event_add_item(item, FRONT_KEY, (void *)event->mv_front);
		item = p_event_add_item(item, UP_KEY, (void *)event->mv_up);
		item = p_event_add_item(item, DOWN_KEY, (void *)event->mv_down);
		item = p_event_add_item(item, HUP_KEY, (void *)event->mv_mup);
		item = p_event_add_item(item, HDOWN_KEY, (void *)event->mv_mdown);
		item = p_event_add_item(item, WPREV_KEY, (void *)event->mv_word_prev);
		item = p_event_add_item(item, WNEXT_KEY, (void *)event->mv_word_next);
		item = p_event_add_item(item, RM_CUR_KEY, (void *)event->rm_cur);
		item = p_event_add_item(item, RM_PREV_KEY, (void *)event->rm_prev);
		item = p_event_add_item(item, TAB_KEY, (void *)p_event_map_tab);
		item = p_event_add_item(item, CLEAN_KEY, (void *)p_event_map_clean);
		item = p_event_add_item(item, SILENT_KEY, (void *)p_event_map_silent);
		p_event_map_silent_ctrls(item);
	}
}
