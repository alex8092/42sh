/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:08 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 18:44:50 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_private.h"
#include <stdlib.h>
#include <unistd.h>

static void			display_init(t_display *display)
{
	p_display_init_attributes(display);
	p_display_init_methodes(display);
}

t_display			*display_singleton(void)
{
	static t_display	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_display*)ft_memalloc(sizeof(t_display));
		display_init(singleton);
	}
	return (singleton);
}
