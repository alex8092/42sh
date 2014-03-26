/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:40:48 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:48:47 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HISTORY_PRIVATE_H
# define FT_HISTORY_PRIVATE_H

# include "ft_history.h"

struct					s_lst_history
{
	char				*cmd;
	t_lst_history		*prev;
	t_lst_history		*next;
};

t_bool					p_history_is_end(void);
t_bool					p_history_is_first(void);

int						p_history_size(void);

char					*p_history_prev(t_bool all);
char					*p_history_next(t_bool all);

void					p_history_init_attributes(t_history *history);
void					p_history_init_methods(t_history *history);
void					p_history_free(void);
t_history				*p_history_load(void);
t_history				*p_history_push(char *str, t_bool save);
t_history				*p_history_save(t_lst_history *new, t_bool save);

#endif
