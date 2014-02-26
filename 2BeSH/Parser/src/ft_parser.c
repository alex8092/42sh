#include "ft_parser.h"
#include <stdlib.h>

static void	parser_start()
{
	return ;
}

static void	parser_init(t_parser *p)
{
	p->start = parser_start;
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
