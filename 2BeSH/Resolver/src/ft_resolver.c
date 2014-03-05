#include "ft_resolver.h"
#include "ft_security.h"
#include "common.h"
#include "ft_executor.h"
#include "ft_debug.h"
#include <stdio.h>
#include "ft_parser.h"
#include "ft_lexer.h"

static void	parse_tree(t_resop **b, t_resop **e, t_pars *t, t_lex_op cur_op)
{
	t_lex		*cur;

	if (t)
	{
		parse_tree(b, e, t->left, cur_op);
		cur = t->op;
		if (cur && cur->op < 100)
		{
			if (cur_op != LEX_OP_PIPE && *b)
			{
				ft_resolv_redirects(*b, &(*b)->lex);
				exec_singleton()->start(*b);
				*b = NULL;
			}
			*e = ft_new_operation(*e, cur);
			if (!(*b))
				*b = *e;
		}
		else
			cur_op = cur->op;
		parse_tree(b, e, t->right, cur_op);
	}
}

static void	resolver_start(t_pars *tree)
{
	static t_resolver	*rv = NULL;
	t_operation			*begin;
	t_operation			*end;

	begin = NULL;
	end = NULL;
	if (!rv)
		rv = resolver_singleton();
	parse_tree(&begin, &end, tree, LEX_OP_NO);
	ft_resolv_redirects(begin, &begin->lex);
	exec_singleton()->start(begin);
}

static void	resolver_init(t_resolver *rv)
{
	rv->start = resolver_start;
}

t_resolver	*resolver_singleton()
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

