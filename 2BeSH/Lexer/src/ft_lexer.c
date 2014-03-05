#include "ft_lexer_private.h"
#include "ft_stocker.h"
#include "ft_display.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

static t_lexer		*lexer_start(void)
{
	ssize_t			ret;
	char			c[4] = { 0, 0, 0, 0 };
	t_lex			*begin;

	while (42)
	{
		display_singleton()->prompt();
		while (c[0] != '\n' && (ret = read(0, &c, 4)) > 0)
		{
			while (c[0])
			{
				event_singleton()->read(c);
				if (c[0] == '\n')
				{
					begin = ft_lexer_lex_str(stocker_singleton()->to_string());
					if (begin)
						lexer_singleton()->m_event_complete(begin);
					stocker_singleton()->clean();
					if (c[1] != '\n')
					{
						display_singleton()->prompt();
						c[0] = c[1];
						c[1] = c[2];
						c[2] = c[3];
						c[3] = 0;
						continue ;
					}
				}
			}
		}
	}
	return (lexer_singleton());
}

static t_lexer		*lexer_onComplete(void (*f)())
{
	lexer_singleton()->m_event_complete = f;
	return (lexer_singleton());
}

static void			lexer_init(t_lexer *lexer)
{
	lexer->start = lexer_start;
	lexer->onComplete = lexer_onComplete;
	p_lexer_template_init(lexer);
}

t_lexer				*lexer_singleton(void)
{
	static t_lexer	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_lexer*)ft_memalloc(sizeof(t_lexer));
		lexer_init(singleton);
	}
	return (singleton);
}

