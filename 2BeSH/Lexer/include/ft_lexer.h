
#ifndef FT_LEXER_H
# define FT_LEXER_H

# include "common.h"
# include "ft_event.h"

typedef struct s_lexer	t_lexer;

struct	s_lexer
{
	void	(*m_event_complete)();
	t_lexer	*(*start)();
	t_lexer	*(*onComplete)(void (*)());
};

t_lexer	*lexer_singleton(void);

#endif
