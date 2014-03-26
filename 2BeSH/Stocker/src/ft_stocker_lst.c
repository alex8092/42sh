/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocker_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:40 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:50:50 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stocker_private.h"

t_lst_stocker	*p_stocker_new_lst_el(char c)
{
	t_lst_stocker	*el;

	el = (t_lst_stocker*)ft_memalloc(sizeof(t_lst_stocker));
	el->next = 0;
	el->prev = 0;
	el->c = c;
	return (el);
}
