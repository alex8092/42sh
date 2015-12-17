/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:04 by amerle            #+#    #+#             */
/*   Updated: 2014/03/27 22:22:48 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_resolver.h"
#include "ft_executor.h"
#include "ft_security.h"
#include "ft_development.h"

void			add_op(t_resop **b, t_resop **e, t_pars *t, t_lex_op cur_op)
{
	if (cur_op == LEX_OP_PIPE_REDIR && *e)
		(*e)->err_to_out = true;
	*e = ft_new_operation(*e, t->op);
	if (cur_op == LEX_OP_BACK)
		(*e)->background = true;
	if (!(*b))
		*b = *e;
}

static void		resolv_exec_bis(t_resop *b)
{
	t_resop	*cur;

	cur = b;
	while (cur)
	{
		if (!dev_singleton()->start(cur->lex))
		{
			exec_singleton()->m_status = 1;
			return ;
		}
		ft_resolv_redirects(cur, &cur->lex);
		cur = cur->next;
	}
	exec_singleton()->start(b);
	security_singleton()->active_raw(true);
}

void			resolv_exec(t_resop **b, t_resop **e, t_lex_op cur_op)
{
	t_bool	cond;

	if (*b)
	{
		cond = cur_op == LEX_OP_AND && exec_singleton()->m_status;
		cond = cond || (cur_op == LEX_OP_OR && !exec_singleton()->m_status);
		cond = !cond || exec_singleton()->m_first;
		if (cond)
			resolv_exec_bis(*b);
		ft_free_op(*b);
		*b = NULL;
		*e = NULL;
	}
}

static void		do_pipe(t_resop **b, t_resop **e, t_pars *t, t_lex_op cur_op)
{
	t_lex	*cur;

	if (t)
	{
		parse_tr(b, e, t->left, cur_op);
		cur = t->op;
		if (cur && cur->op >= 100 && (cur->op / 10) != (LEX_OP_PIPE / 10))
			return ;
		else if (cur->op < 100)
			add_op(b, e, t, cur_op);
		parse_tr(b, e, t->right, cur_op);
	}
}

t_lex_op		parse_tr(t_resop **b, t_resop **e, t_pars *t, t_lex_op cur_op)
{
	t_lex	*cur;

	if (t && ((cur = t->op) || true))
	{
		if (t->op && (t->op->op / 10) == (LEX_OP_PIPE / 10))
		{
			resolver_singleton()->m_last_op = cur_op;
			do_pipe(b, e, t->left, cur_op);
		}
		else
			parse_tr_2(b, e, t, cur_op);
		if ((cur_op / 10) == (LEX_OP_PIPE / 10) && cur && cur->op < 100)
			do_pipe(b, e, t, cur_op);
		else if (cur && ((cur->tmpop = cur_op) || true))
		{
			parse_tr_3(b, e, t, cur);
			cur_op = cur->tmpop;
		}
		parse_tr(b, e, t->right, cur_op);
		if (t->op->op >= 100)
			ft_lex_free_secure_item(&t->op);
	}
	return (cur_op);
}
