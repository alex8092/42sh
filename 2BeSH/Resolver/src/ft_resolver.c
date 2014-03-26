/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:04 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:04 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_resolver.h"
#include "ft_security.h"
#include "ft_executor.h"
#include "ft_lexer.h"
#include <sys/types.h>
#include <stdlib.h>

static void	resolver_start(t_pars *tree)
{
	static t_resolver	*rv = NULL;
	t_operation			*begin;
	t_operation			*end;
	t_lex_op			op;

	exec_singleton()->m_status = -1;
	resolver_singleton()->m_last_op = LEX_OP_NO;
	exec_singleton()->m_first = true;
	begin = NULL;
	end = NULL;
	if (!rv)
		rv = resolver_singleton();
	op = parse_tr(&begin, &end, tree, LEX_OP_NO);
	if (resolver_singleton()->m_last_op != LEX_OP_NO)
		resolv_exec(&begin, &end, resolver_singleton()->m_last_op);
	else
		resolv_exec(&begin, &end, op);
}

static void	resolver_init(t_resolver *rv)
{
	rv->start = resolver_start;
	rv->resolv_path = ft_resolv_path;
}

t_resolver	*resolver_singleton(void)
{
	static t_resolver	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_resolver*)ft_memalloc(sizeof(t_resolver));
		if (!singleton)
			security_singleton()->critical("malloc");
		resolver_init(singleton);
	}
	return (singleton);
}
