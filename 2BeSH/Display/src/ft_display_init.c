/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:16 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:46:09 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_private.h"

void		p_display_init_attributes(t_display *display)
{
	display->m_fd = 1;
	display->m_active = false;
}

void		p_display_init_methodes(t_display *display)
{
	display->putchar = p_display_putchar;
	display->set_fd = p_display_set_fd;
	display->prompt = p_display_write_prompt;
	display->mv_prev = p_display_mv_cursor_prev;
	display->mv_next = p_display_mv_cursor_next;
	display->rm_cur = p_display_rm_cursor;
	display->rm_prev = p_display_rm_previous_cursor;
	display->set_active = p_display_set_active;
	display->is_active = p_display_is_active;
	display->puts = p_display_termcaps_puts;
	display->putstr = p_display_putstr;
	display->height = p_display_height;
	display->width = p_display_width;
	display->col = p_display_get_column;
	display->resize = p_display_resize;
	display->save_cursor = p_display_save_cursor;
	display->restore_cursor = p_display_restore_cursor;
}
