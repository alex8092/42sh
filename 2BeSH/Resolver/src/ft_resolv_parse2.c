/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_parse2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:06:23 by amerle            #+#    #+#             */
/*   Updated: 2014/03/26 19:08:46 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_resolver.h"
#include "ft_executor.h"

void		parse_tr_2(t_resop **b, t_resop **e, t_pars *t, t_lex_op cur_op)
{
	if (t->op->op != LEX_OP_BACK)
		parse_tr(b, e, t->left, cur_op);
	else
		parse_tr(b, e, t->left, t->op->op);
}

void		parse_tr_3(t_resop **b, t_resop **e, t_pars *t, t_lex *cur)
{
	if ((cur->op / 10) != (LEX_OP_PIPE / 10))
		resolv_exec(b, e, cur->tmpop);
	if (cur->op >= 100)
		cur->tmpop = cur->op;
	else
	{
		add_op(b, e, t, cur->tmpop);
		resolv_exec(b, e, cur->tmpop);
	}
}
