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
		LEX_OP_NO = 0,
		LEX_OP_WORD = 1,
		LEX_OP_STR = 2,
		LEX_UNKNOW = 3,
		LEX_STAR = 4,
		LEX_OP_REDIRECT_OUT = 10,
		LEX_OP_APPEND_OUT = 11,
		LEX_OP_REDIRECT_IN = 12,
		LEX_OP_SUBCOMMAND = 21,
		LEX_OP_PIPE = 100,
		LEX_OP_AND = 110,
		LEX_OP_OR = 111,
		LEX_OP_SEPARATOR = 121,
		LEX_OP_BACK = 121,
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

t_lex	*ft_lexer_lex_str(char *str);
t_lexer	*lexer_singleton(void);

#endif
