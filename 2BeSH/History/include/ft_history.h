/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:40:41 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:48:42 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HISTORY_H
# define FT_HISTORY_H

# include <ft/common.h>

typedef struct s_lst_history		t_lst_history;
typedef struct s_history			t_history;

struct					s_history
{
	t_lst_history		*m_start;
	t_lst_history		*m_end;
	t_lst_history		*m_current;

	char				*m_active;

	int					m_length;
	int					m_pos;
	int					m_fd;

	t_bool				(*is_first)(void);
	t_bool				(*is_end)(void);

	char				*(*prev)(t_bool all);
	char				*(*next)(t_bool all);

	int					(*size)(void);

	t_history			*(*push)(char *str, t_bool save);
	t_history			*(*load)(void);
	t_history			*(*save)(t_lst_history *new, t_bool save);
	void				(*unload)(void);
};

t_history				*history_singleton(void);

#endif
