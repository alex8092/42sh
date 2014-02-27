#include "ft_parser_private.h"
#include "ft_stocker.h"
#include "ft_resolver.h"
#include <stdlib.h>

static void	parser_start()
{
	t_operation	*ops;

	ops = parser_singleton()->parse(stocker_singleton()->to_string());
	resolver_singleton()->start(ops);
	while (stocker_singleton()->size() > 0)
		stocker_singleton()->rm_back();
	return ;
}

static void	parser_init(t_parser *p)
{
	p->start = parser_start;
	p->parse = p_parser_parse;
}

t_parser	*parser_singleton()
{
	static t_parser	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_parser*)malloc(sizeof(t_parser));
		if (!singleton)
			exit(1);
		parser_init(singleton);
	}
	return (singleton);
}
