#ifndef FT_PARSER_PRIVATE_H
# define FT_PARSER_PRIVATE_H

# include "ft_parser.h"
# include "ft_lexer.h"

typedef enum e_child	p_child;

enum	e_child { RIGHT, LEFT};

t_pars	*p_parser_parse(t_lex *lst);
t_pars	*p_pars_init(void);
t_pars	*p_put_op(t_pars *lst, t_lex *op);
t_lex	*p_find_op(t_lex *lst);

#endif
