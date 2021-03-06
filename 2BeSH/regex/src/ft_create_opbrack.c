/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_opbrack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:02 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:02 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

t_opbrack	*ft_create_opbrack(t_regbuilder *rb)
{
	t_opbrack	*bk;

	bk = (t_opbrack*)ft_new_reg(rb->end, REGOP_BRACK, sizeof(t_opbrack));
	if (bk)
	{
		++rb->pos;
		bk->str = rb->str + rb->pos;
		while (rb->str[rb->pos] && (rb->str[rb->pos] != ']'))
			++rb->pos;
		if (rb->str[rb->pos])
		{
			bk->str = ft_strndup(bk->str, rb->str + rb->pos - bk->str);
			++rb->pos;
		}
		rb->end = (t_regex *)bk;
	}
	return (bk);
}
