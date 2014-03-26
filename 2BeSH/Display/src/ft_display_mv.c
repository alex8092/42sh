/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_mv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:19 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 18:44:24 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_private.h"
#include <term.h>

t_display		*p_display_mv_cursor_prev(void)
{
	t_display		*display;
	int				col;

	display = display_singleton();
	col = display->col();
	if (col < display->width())
		display->puts("le");
	else
	{
		display->puts("up");
		while (col--)
			display->puts("nd");
	}
	return (display);
}

t_display		*p_display_mv_cursor_next(void)
{
	t_display		*display;

	display = display_singleton();
	if (display->col() != display->width())
		display->puts("nd");
	else
	{
		display->puts("cr");
		display->puts("do");
	}
	return (display);
}
