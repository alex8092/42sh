#ifndef FT_PARSER_H
# define FT_PARSER_H

typedef struct s_parser	t_parser;

struct		s_parser
{
	void	(*start)();
};

t_parser	*parser_singleton();

#endif
