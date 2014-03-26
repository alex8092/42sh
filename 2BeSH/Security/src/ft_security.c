/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:05 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:05 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_security_private.h"
#include <stdlib.h>

static void	secu_init(t_security *security)
{
	p_security_init_attributes(security);
	p_security_init_methodes(security);
	p_security_init_signal();
}

t_security	*security_singleton(void)
{
	static t_security	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_security*)malloc(sizeof(t_security));
		if (!singleton)
			_exit(1);
		secu_init(singleton);
	}
	return (singleton);
}
