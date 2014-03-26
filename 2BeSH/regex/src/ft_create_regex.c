/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_regex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:02 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:02 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

t_regex	*ft_new_reg(t_regex *parent, t_regop type, int size)
{
	t_regex	*regex;

	regex = (t_regex *)ft_memalloc(size);
	if (regex)
	{
		regex->type = type;
		regex->prev = parent;
		if (parent)
			parent->next = regex;
	}
	return (regex);
}
