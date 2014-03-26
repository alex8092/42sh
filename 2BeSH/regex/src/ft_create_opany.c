/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_opany.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:01 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:01 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

t_opany	*ft_create_opany(t_regbuilder *rb)
{
	t_opany	*any;

	any = ft_new_reg(rb->end, REGOP_ANY, sizeof(t_opany));
	if (any)
	{
		++rb->pos;
		rb->end = (t_regex *)any;
	}
	return (any);
}
