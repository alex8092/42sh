#include "ft_resolver.h"
#include "common.h"
#include "ft_executor.h"
#include "ft_debug.h"
#include <stdio.h>

static void	parse_tree(t_pars *tree)
{
	t_lex	*cur;

	if (tree)
	{
		parse_tree(tree->left);
		cur = tree->op;
		printf("Command : {{");
		while (cur)
		{
			printf(" %s", cur->str);
			cur = cur->next;
		}
		printf(" }}\n");
		parse_tree(tree->right);
	}
}

static void	resolver_start(t_pars *tree)
{
	static t_resolver	*rv = NULL;

	if (!rv)
		rv = resolver_singleton();
	parse_tree(tree);
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
			_exit(1);
		resolver_init(singleton);
	}
	return (singleton);
}

