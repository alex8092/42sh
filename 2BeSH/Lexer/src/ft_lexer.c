/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 18:45:11 by amerle            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2014/02/24 04:13:16 by amerle           ###   ########.fr       */
=======
/*   Updated: 2014/02/24 04:17:09 by triviere         ###   ########.fr       */
>>>>>>> cade3c487cf7f9bb6ae75caf4e0ec7cd6cfbf190
/*                                                                            */
/* ************************************************************************** */

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
			if (ft_isprint(c[0]))
				write(1, &c, 1);
			else
				event_singleton()->doEvent(c);
			if (c[0] == '\n')
				lexer_singleton()->m_event_complete();
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

t_lexer				*lexer_singleton()
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

