/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_opsub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:02 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:02 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

t_opsub	*ft_create_opsub(t_regbuilder *rb)
{
	t_opsub	*sub;

	sub = (t_opsub *)ft_new_reg(rb->end, REGOP_SUB, sizeof(t_opsub));
	if (sub)
	{
		if (rb->str[rb->pos] == '(')
			sub->type_sub = 0;
		else
			sub->type_sub = 1;
		++rb->pos;
		rb->end = (t_regex *)sub;
	}
	return (sub);
}
