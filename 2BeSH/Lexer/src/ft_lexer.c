/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 18:45:11 by amerle            #+#    #+#             */
/*   Updated: 2014/02/23 20:02:03 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

static t_lexer	*lexer_start()
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
//			printf("[%d]-[%d]-[%d]-[%d]\n", c[0], c[1], c[2], c[3]);
		}
	}
	return lexer_singleton();
}

static t_lexer	*lexer_onComplete(void (*f)())
{
	lexer_singleton()->m_event_complete = f;
	return lexer_singleton();
}

static void	lexer_init(t_lexer *lexer)
{
	lexer->start = lexer_start;
	lexer->onComplete = lexer_onComplete;
}

t_lexer		*lexer_singleton()
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

