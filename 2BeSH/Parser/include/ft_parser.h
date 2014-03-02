#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "ft_operation.h"
# include "ft_lexer.h"

typedef struct s_parser	t_parser;
typedef struct s_pars	t_pars;


struct 		s_pars
{
	t_lex	*op;
	t_pars	*right;
	t_pars	*left;
	t_pars	*parent;
};

struct		s_parser
{
	void			(*start)(t_lex *begin);
	t_pars		*(*parse)(t_lex*);
};

t_parser	*parser_singleton(void);

#endif
