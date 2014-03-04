#include "ft_resolver.h"
#include "common.h"
#include "ft_executor.h"
#include "ft_debug.h"
#include <stdio.h>
#include "ft_parser.h"
#include "ft_lexer.h"

static void	parse_tree(t_operation **begin, t_operation **end, t_pars *tree)
{
	t_lex		*cur;
	t_lex_op		cur_op;

	cur_op = LEX_OP_NO;
	if (tree)
	{
		parse_tree(begin, end, tree->left);
		cur = tree->op;
		if (cur && cur->op < 100)
		{
			if (cur_op != LEX_OP_PIPE && *begin)
			{
				ft_resolv_redirects(*begin, &(*begin)->lex);
				exec_singleton()->start(*begin);
				*begin = NULL;
			}
			*end = ft_new_operation(*end, cur);
			if (!(*begin))
				*begin = *end;
			printf("Command : {{");
			while (cur)
			{
				printf(" %s", cur->str);
				cur = cur->next;
			}
			printf(" }}\n");
		}
		else
			cur_op = cur->op;
		parse_tree(begin, end, tree->right);
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
	parse_tree(&begin, &end, tree);
	ft_resolv_redirects(end, &end->lex);
	exec_singleton()->start(end);
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
			_exit(1);
		resolver_init(singleton);
	}
	return (singleton);
}

