/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:23 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:46:25 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_private.h"

t_display		*p_display_set_fd(int fd)
{
	static t_display	*display = NULL;

	if (!display)
		display = display_singleton();
	display->m_old_fd = display->m_fd;
	display->m_fd = fd;
	return ((t_display *)display);
}

t_display		*p_display_set_active(t_bool status)
{
	t_display	*display;

	display = display_singleton();
	display->m_active = status;
	return (display);
}

t_bool			p_display_is_active(void)
{
	return (display_singleton()->m_active);
}
