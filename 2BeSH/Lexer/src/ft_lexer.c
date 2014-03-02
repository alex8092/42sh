#include "ft_lexer.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

static t_lexer		*lexer_start(void)
{
	ssize_t			ret;
	char			c[4];

	while (42)
	{
		write(1, "[#] : ", 6);
		c[0] = 0;
		while (c[0] != '\n' && (ret = read(0, &c, 4)) > 0)
		{
			event_singleton()->read(c);
			if (c[0] == '\n')
				lexer_singleton()->m_event_complete();
			c[1] = 0;
			c[2] = 0;
			c[3] = 0;
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
}

t_lexer				*lexer_singleton(void)
{
	static t_lexer	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_lexer*)malloc(sizeof(t_lexer));
		if (!singleton)
			exit(1);
		lexer_init(singleton);
	}
	return (singleton);
}

