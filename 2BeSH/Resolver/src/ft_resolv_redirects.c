/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_redirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:04 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:04 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_resolver.h"
#include <stdlib.h>

static void	ft_do_redir_out(t_lex *cur, t_operation *op, t_bool append)
{
	if (cur->str[0] != '2')
	{
		if (cur->next)
			op->s_fd_out = ft_strdup(cur->next->str);
		op->append_out = append;
	}
	else
	{
		if (cur->next)
			op->s_fd_err = ft_strdup(cur->next->str);
		op->append_err = append;
	}
	if (cur->str[ft_strlen(cur->str) - 1] == '&')
	{
		ft_strdel(&op->s_fd_err);
		op->err_to_out = true;
	}
}

static void	finalize_loop(t_lex *last, t_lex **cur2, t_lex **begin)
{
	t_lex	*cur;

	cur = *cur2;
	if (last)
	{
		last->next = (cur->next) ? cur->next->next : NULL;
		ft_lex_free_item(cur->next);
		ft_lex_free_item(cur);
		cur = last->next;
	}
	else
	{
		*begin = (cur->next) ? cur->next->next : NULL;
		ft_lex_free_item(cur->next);
		ft_strdel(&cur->str);
		cur->next = *begin;
		cur = *begin;
	}
	*cur2 = cur;
}

void		ft_resolv_redirects(t_operation *op, t_lex **begin)
{
	t_lex	*cur;
	t_lex	*last;

	cur = *begin;
	last = NULL;
	while (cur)
	{
		if (cur->op == LEX_OP_REDIRECT_OUT)
			ft_do_redir_out(cur, op, false);
		else if (cur->op == LEX_OP_REDIRECT_IN && cur->next)
			op->s_fd_in = ft_strdup(cur->next->str);
		else if (cur->op == LEX_OP_APPEND_OUT)
			ft_do_redir_out(cur, op, true);
		else
		{
			last = cur;
			cur = cur->next;
			continue ;
		}
		finalize_loop(last, &cur, begin);
	}
}
