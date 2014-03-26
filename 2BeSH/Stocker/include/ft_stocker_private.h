/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocker_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:24 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 18:48:46 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCKER_PRIVATE_H
# define FT_STOCKER_PRIVATE_H

# include "ft_stocker.h"

struct			s_lst_stocker
{
	char				c;
	t_lst_stocker		*prev;
	t_lst_stocker		*next;
};

t_lst_stocker	*p_stocker_new_lst_el(char c);

t_bool			p_stocker_is_end(void);
t_bool			p_stocker_is_first(void);

t_stocker		*p_stocker_push_back_lst(char c);
t_stocker		*p_stocker_push_front_lst(char c);
t_stocker		*p_stocker_push_str(char *str);
t_stocker		*p_stocker_remove_back_lst(void);
t_stocker		*p_stocker_remove_front_lst(void);
t_stocker		*p_stocker_remove_current_lst(void);
t_stocker		*p_stocker_remove_prev_lst(void);
t_stocker		*p_stocker_clean_lst(void);
t_stocker		*p_stocker_after_current_push(char c);
t_stocker		*p_stocker_current_prev(void);
t_stocker		*p_stocker_current_next(void);
t_stocker		*p_stocker_current_front(void);
t_stocker		*p_stocker_current_back(void);

char			p_stocker_get_current_char(void);

char			*p_stocker_to_string(void);

int				p_stocker_size(void);
int				p_stocker_get_current_pos(void);

void			p_stocker_init_methods(t_stocker *stocker);
void			p_stocker_init_attributes(t_stocker *stocker);

#endif
