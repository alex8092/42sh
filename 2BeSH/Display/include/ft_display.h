/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:35:54 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 18:48:10 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_H
# define FT_DISPLAY_H

# include <ft/common.h>

typedef struct s_display	t_display;

struct						s_display
{
	int				m_fd;
	int				m_old_fd;

	t_bool			m_active;

	void			(*resize)(int signal);

	int				(*height)(void);
	int				(*width)(void);
	int				(*col)(void);

	t_bool			(*is_active)(void);

	t_display		*(*set_active)(t_bool status);
	t_display		*(*set_fd)(int fd);
	t_display		*(*putchar)(char c);
	t_display		*(*putstr)(char *str);
	t_display		*(*puts)(char *cmd);
	t_display		*(*prompt)(void);
	t_display		*(*mv_prev)(void);
	t_display		*(*mv_next)(void);
	t_display		*(*mv_front)(void);
	t_display		*(*mv_back)(void);
	t_display		*(*rm_cur)(void);
	t_display		*(*rm_prev)(void);
	t_display		*(*save_cursor)(void);
	t_display		*(*restore_cursor)(void);
};

t_display					*display_singleton(void);

#endif
