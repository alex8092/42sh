/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:38 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:47:51 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_event_private.h"
#include <unistd.h>

t_event_item	*p_event_add_item(t_event_item *p, int key, void (*f)(void))
{
	t_event_item	*item;

	item = (t_event_item *)ft_memalloc(sizeof(t_event_item));
	item->key = key;
	item->function = f;
	if (p != NULL)
		p->next = item;
	return (item);
}
