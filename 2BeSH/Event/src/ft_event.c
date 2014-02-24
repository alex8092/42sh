/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrivier <thrivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 19:43:09 by thrivier          #+#    #+#             */
/*   Updated: 2014/02/23 20:00:55 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_event.h"
#include <stdlib.h>
#include <unistd.h>

static t_event	*doEvent(char *c)
{
	write(1, c, 1);
	return event_singleton();
}

static void	event_init(t_event *event)
{
	event->doEvent = doEvent;
}

t_event		*event_singleton()
{
	static t_event	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_event*)malloc(sizeof(t_event));
		if (!singleton)
			exit(1);
		event_init(singleton);
	}
	return (singleton);
}