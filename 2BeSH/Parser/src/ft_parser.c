#include "ft_parser_private.h"
#include <stdlib.h>

static void	parser_start()
{
	parser_singleton()->parse("ls -lRa | grep \"tmp\" && xargs rm ; cd tmpdir || mkdir -p tmpdir");
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
