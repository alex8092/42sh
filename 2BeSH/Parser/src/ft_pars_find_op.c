/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_find_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:00 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:00 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_lex		*p_find_op(t_lex *begin)
{
	t_lex				*cur;
	t_lex				*op;
	unsigned int		nb;

	cur = begin;
	op = begin;
	nb = begin->op / 10;
	while (cur != NULL)
	{
		if ((cur->op / 10) > nb && cur->op >= 100)
		{
			nb = (cur->op / 10);
			op = cur;
		}
		cur = cur->next;
	}
	return (op);
}
