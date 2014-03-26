/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:17 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 18:57:23 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCKER_H
# define FT_STOCKER_H

# include <ft/common.h>

typedef struct s_lst_stocker		t_lst_stocker;
typedef struct s_stocker			t_stocker;

struct								s_stocker
{
	t_lst_stocker		*m_start;
	t_lst_stocker		*m_end;
	t_lst_stocker		*m_current;

	int					m_length;
	int					m_pos;

	int					(*size)(void);
	int					(*current_pos)(void);
	char				(*char_current)(void);

	char				*(*to_string)(void);

	t_bool				(*is_end)(void);
	t_bool				(*is_first)(void);

	t_stocker			*(*push)(char c);
	t_stocker			*(*push_str)(char *str);
	t_stocker			*(*push_back)(char c);
	t_stocker			*(*push_front)(char c);
	t_stocker			*(*rm_back)(void);
	t_stocker			*(*rm_front)(void);
	t_stocker			*(*rm_prev)(void);
	t_stocker			*(*rm_cur)(void);
	t_stocker			*(*clean)(void);
	t_stocker			*(*mv_prev)(void);
	t_stocker			*(*mv_next)(void);
	t_stocker			*(*mv_front)(void);
	t_stocker			*(*mv_back)(void);
};

t_stocker							*stocker_singleton(void);

#endif
