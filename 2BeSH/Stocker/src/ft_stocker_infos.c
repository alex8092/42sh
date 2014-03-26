/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocker_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:33 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:50:40 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stocker_private.h"

t_bool		p_stocker_is_end(void)
{
	t_stocker	*stocker;

	stocker = stocker_singleton();
	if (stocker->m_pos >= stocker->m_length)
		return (true);
	else
		return (false);
}

t_bool		p_stocker_is_first(void)
{
	t_stocker	*stocker;

	stocker = stocker_singleton();
	if (stocker->m_pos == 0)
		return (true);
	else
		return (false);
}
