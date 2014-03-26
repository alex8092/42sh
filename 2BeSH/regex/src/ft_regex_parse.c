/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:03 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 06:28:31 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "regex_private.h"

static void		cond(t_regbuilder *rb)
{
	if (rb->str[rb->pos] == '^' && rb->pos == 0)
		ft_create_opbeg(rb);
	else if (rb->str[rb->pos] == '$' && rb->str[rb->pos + 1] == 0)
		ft_create_opend(rb);
	else if (rb->str[rb->pos] == '|')
		ft_create_oppipe(rb);
	else if (rb->str[rb->pos] == '[')
		ft_create_opbrack(rb);
	else if (rb->str[rb->pos] == '{')
		ft_create_oprep(rb);
	else if (ft_isinarray(rb->str[rb->pos], "()"))
		ft_create_opsub(rb);
	else if (rb->str[rb->pos] == '.')
		ft_create_opany(rb);
	else if (rb->str[rb->pos] == '\\')
	{
		rb->escape = true;
		++rb->pos;
	}
	else
		ft_create_opbase(rb);
}

void			ft_regex_parse(t_regbuilder *rb)
{
	while (rb->str[rb->pos])
	{
		if (!rb->escape)
			cond(rb);
		else
		{
			ft_create_opbase(rb);
			rb->escape = false;
		}
		if (!rb->begin)
			rb->begin = rb->end;
	}
}
