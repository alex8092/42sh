/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:18 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:47:31 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_event_private.h"
#include <stdlib.h>
#include <unistd.h>

static void	event_init(t_event *event)
{
	p_event_init_attributes(event);
	p_event_init_methodes(event);
	p_event_init_mapping_key(event);
}

t_event		*event_singleton(void)
{
	static t_event	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_event*)ft_memalloc(sizeof(t_event));
		event_init(singleton);
	}
	return (singleton);
}
