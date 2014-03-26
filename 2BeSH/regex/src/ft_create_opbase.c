/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_opbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:01 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:01 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

t_opbase	*ft_create_opbase(t_regbuilder *rb)
{
	t_opbase	*reg;

	reg = (t_opbase*)ft_new_reg(rb->end, REGOP_BASE, sizeof(t_opbase));
	if (reg)
	{
		reg->c = rb->str[rb->pos];
		rb->end = (t_regex *)reg;
		++rb->pos;
	}
	return (reg);
}
