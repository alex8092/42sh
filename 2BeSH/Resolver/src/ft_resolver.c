#include "ft_resolver.h"
#include "ft_security.h"
#include "common.h"
#include "ft_executor.h"
#include "ft_debug.h"
#include <stdio.h>
#include "ft_parser.h"

static void	parse_tree(t_operation **begin, t_operation **end, t_pars *tree)
{
	t_lex		*cur;

	if (tree)
	{
		parse_tree(begin, end, tree->left);
		cur = tree->op;
		if (cur && cur->op < 100)
		{
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
	exec_singleton()->start(tree);
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

