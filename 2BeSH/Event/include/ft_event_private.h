/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:39:07 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 18:59:46 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVENT_PRIVATE_H
# define FT_EVENT_PRIVATE_H

# include "ft_event.h"

# define HUP_KEY (50 << 24) | (65 << 16) | (0 << 8) | 0
# define HDOWN_KEY (50 << 24) | (66 << 16) | (0 << 8) | 0
# define UP_KEY (27 << 24) | (91 << 16) | (65 << 8)
# define DOWN_KEY (27 << 24) | (91 << 16) | (66 << 8)
# define PREV_KEY (27 << 24) | (91 << 16) | (68 << 8)
# define NEXT_KEY (27 << 24) | (91 << 16) | (67 << 8)

# define WNEXT_KEY (50 << 24) | (67 << 16) | (0 << 8) | 0
# define WPREV_KEY (50 << 24) | (68 << 16) | (0 << 8) | 0

# define RM_PREV_KEY (127 << 24) | (0 << 16) | (0 << 8)
# define RM_CUR_KEY (27 << 24) | (91 << 16) | (51 << 8) | 126

# define TAB_KEY (9 << 24) | (0 << 16) | (0 << 8)
# define CLEAN_KEY (12 << 24) | (0 << 16) | (0 << 8) | 0

# define SILENT_KEY (27 << 24) | (91 << 16) | (49 << 8) | 59

# ifdef __APPLE__
#  define FRONT_KEY (27 << 24) | (91 << 16) | (72 << 8) | 0
#  define BACK_KEY (27 << 24) | (91 << 16) | (70 << 8) | 0
# else
#  define FRONT_KEY (27 << 24) | (79 << 16) | (72 << 8) | 0
#  define BACK_KEY (27 << 24) | (79 << 16) | (70 << 8) | 0
# endif

struct			s_event_item
{
	int				key;
	void			(*function)(void);
	t_event_item	*next;
};

void			p_event_init_attributes(t_event *event);
void			p_event_init_methodes(t_event *event);
void			p_event_init_mapping_key(t_event *event);
void			p_event_reprint_str(void);

t_event			*p_event_reset(char *cmd);
t_event			*p_event_map_rm_prev(void);
t_event			*p_event_map_rm_cur(void);
t_event			*p_event_map_front(void);
t_event			*p_event_map_back(void);
t_event			*p_event_map_next(void);
t_event			*p_event_map_prev(void);
t_event			*p_event_map_word_prev(void);
t_event			*p_event_map_word_next(void);
t_event			*p_event_map_history_prev(void);
t_event			*p_event_map_history_next(void);
t_event			*p_event_map_history_mprev(void);
t_event			*p_event_map_history_mnext(void);
t_event			*p_event_read(char *c);
t_event			*p_event_init_terms(void);
t_event			*p_event_end(void);
t_event			*p_event_map_tab(void);
t_event			*p_event_map_silent(void);
t_event			*p_event_map_clean(void);

t_event_item	*p_event_add_item(t_event_item *p, int key, void (*f)(void));

#endif
