/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_opbegend.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:01 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:01 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

t_opbeg	*ft_create_opbeg(t_regbuilder *rb)
{
	t_opbeg	*beg;

	beg = (t_regex *)ft_new_reg(rb->end, REGOP_BEG, sizeof(t_opbeg));
	if (beg)
	{
		++rb->pos;
		rb->end = (t_regex *)beg;
	}
	return (beg);
}

t_opend	*ft_create_opend(t_regbuilder *rb)
{
	t_opend	*end;

	end = (t_opend *)ft_new_reg(rb->end, REGOP_END, sizeof(t_opend));
	if (end)
	{
		++rb->pos;
		rb->end = (t_regex *)end;
	}
	return (end);
}
