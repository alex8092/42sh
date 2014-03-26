/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:59 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 07:32:05 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer_private.h"
#include "ft_stocker.h"
#include "ft_display.h"
#include "ft_jobcontrol.h"
#include "ft_security.h"
#include "ft_event.h"
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

static void			rotate(char *c)
{
	stocker_singleton()->clean();
	if (c[1] != '\n')
	{
		display_singleton()->prompt();
		c[0] = c[1];
		c[1] = c[2];
		c[2] = c[3];
		c[3] = 0;
	}
}

static t_lexer		*lexer_start(void)
{
	ssize_t			ret;
	char			*str;

	VAR_C(c);
	while (42)
	{
		display_singleton()->prompt();
		while (c[0] != '\n' && (ret = read(0, &c, 4)) > 0)
		{
			while (c[0])
			{
				security_singleton()->active_raw(true);
				event_singleton()->read(c);
				if (c[0] == '\n')
				{
					str = stocker_singleton()->to_string();
					lexer_singleton()->m_event_complete(ft_lexer_lex_str(str));
					free(str);
					rotate(c);
				}
			}
		}
	}
	return (lexer_singleton());
}

static t_lexer		*lexer_on_complete(void (*f)())
{
	lexer_singleton()->m_event_complete = f;
	return (lexer_singleton());
}

static void			lexer_init(t_lexer *lexer)
{
	lexer->start = lexer_start;
	lexer->on_complete = lexer_on_complete;
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
