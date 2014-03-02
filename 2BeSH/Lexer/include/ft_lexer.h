#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "common.h"
# include "ft_event.h"

typedef struct s_lexer	t_lexer;
typedef struct s_lex	t_lex;

struct s_lex
{
	int		op;
	char	*str;
	t_lex	*next;
};

struct	s_lexer
{
	void	(*m_event_complete)();
	t_lexer	*(*start)();
	t_lexer	*(*onComplete)(void (*)());
};

t_lexer	*lexer_singleton(void);

#endif
