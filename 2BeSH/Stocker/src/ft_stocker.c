/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:29 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:50:35 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stocker_private.h"
#include <stdlib.h>

static void			stocker_init(t_stocker *stocker)
{
	p_stocker_init_attributes(stocker);
	p_stocker_init_methods(stocker);
}

t_stocker			*stocker_singleton(void)
{
	static t_stocker	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_stocker*)ft_memalloc(sizeof(t_stocker));
		stocker_init(singleton);
	}
	return (singleton);
}
