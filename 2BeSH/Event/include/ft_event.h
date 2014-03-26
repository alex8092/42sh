/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:39:12 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 18:58:20 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENT_H
# define FT_EVENT_H

# include <ft/common.h>

typedef struct s_event		t_event;
typedef struct s_event_item	t_event_item;

struct						s_event
{
	t_event_item	*m_begin;

	t_event			*(*reset)(char *cmd);
	t_event			*(*read)(char *c);
	t_event			*(*mv_prev)(void);
	t_event			*(*mv_next)(void);
	t_event			*(*mv_back)(void);
	t_event			*(*mv_front)(void);
	t_event			*(*mv_down)(void);
	t_event			*(*mv_up)(void);
	t_event			*(*mv_mup)(void);
	t_event			*(*mv_mdown)(void);
	t_event			*(*mv_word_next)(void);
	t_event			*(*mv_word_prev)(void);
	t_event			*(*rm_cur)(void);
	t_event			*(*rm_prev)(void);
	t_event			*(*init_terms)(void);
	t_event			*(*clean)(void);
	t_event			*(*end)(void);
};

t_event						*event_singleton(void);

#endif
