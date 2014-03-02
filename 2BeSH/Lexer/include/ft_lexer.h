#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "common.h"
# include "ft_event.h"

typedef struct s_lexer		t_lexer;
typedef struct s_lex		t_lex;
typedef enum e_lex_op		t_lex_op;
typedef struct s_lex_reg	t_lex_reg;

enum	e_lex_op
{
		LEX_OP_WORD = 1,
		LEX_OP_STR = 2,
		LEX_OP_AND = 10,
		LEX_OP_OR = 11,
		LEX_OP_PIPE = 20,
		LEX_OP_SEPARATOR = 30,
		LEX_OP_BACK = 31,
		LEX_UNKNOW = 10000
};

struct			s_lex
{
	t_lex_op	op;
	char		*str;
	t_lex		*next;
};

struct	s_lexer
{
	t_lex_reg	*m_reg_begin;
	void		(*m_event_complete)(t_lex *);
	t_lexer		*(*start)();
	t_lexer		*(*onComplete)(void (*)(t_lex *));
};

t_lexer	*lexer_singleton(void);

#endif
