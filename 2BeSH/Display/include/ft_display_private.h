/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:01 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 18:46:06 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DISPLAY_PRIVATE_H
# define FT_DISPLAY_PRIVATE_H

# include "ft_display.h"

int				p_display_width(void);
int				p_display_height(void);
int				p_display_get_column(void);

void			p_display_init_attributes(t_display *display);
void			p_display_init_methodes(t_display *display);
void			p_display_resize(int signal);

t_bool			p_display_is_active(void);

t_display		*p_display_putchar(char c);
t_display		*p_display_putstr(char *str);
t_display		*p_display_set_fd(int fd);
t_display		*p_display_write_prompt(void);
t_display		*p_display_mv_cursor_prev(void);
t_display		*p_display_mv_cursor_next(void);
t_display		*p_display_rm_cursor(void);
t_display		*p_display_rm_previous_cursor(void);
t_display		*p_display_set_active(t_bool status);
t_display		*p_display_termcaps_puts(char *cmd);
t_display		*p_display_save_cursor(void);
t_display		*p_display_restore_cursor(void);

#endif
