#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "ft_operation.h"

typedef struct s_parser	t_parser;
typedef struct s_pars	t_pars;


struct 		s_pars
{
	t_lex	*t_op;
	t_lex	*right;
	t_lex	*left;
	t_lex	*parent;

}
struct		s_parser
{
	void			(*start)();
	t_operation		*(*parse)(char *);
};

t_parser	*parser_singleton(void);

#endif
