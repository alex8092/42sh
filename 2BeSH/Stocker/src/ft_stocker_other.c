/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocker_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:48 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:51:02 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stocker_private.h"

int				p_stocker_size(void)
{
	return (stocker_singleton()->m_length);
}

char			*p_stocker_to_string(void)
{
	t_stocker		*stocker;
	t_lst_stocker	*cursor;
	char			*str;
	int				i;

	i = 0;
	stocker = stocker_singleton();
	str = (char*)ft_memalloc(sizeof(char) * (stocker->m_length + 1));
	cursor = stocker->m_start;
	while (cursor)
	{
		str[i] = cursor->c;
		cursor = cursor->next;
		i++;
	}
	return (str);
}

char			p_stocker_get_current_char(void)
{
	return (stocker_singleton()->m_current->c);
}

int				p_stocker_get_current_pos(void)
{
	return (stocker_singleton()->m_pos);
}
