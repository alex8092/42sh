/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:37 by triviere          #+#    #+#             */
/*   Updated: 2014/03/25 18:45:09 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_private.h"
#include "ft_prompt.h"
#include <term.h>
#include <unistd.h>
#include <stdlib.h>

static int		put(int c)
{
	ssize_t	ret;

	ret = write(1, &c, 1);
	(void)ret;
	return (c);
}

t_display		*p_display_putchar(char c)
{
	static t_display	*display = NULL;
	int					col;
	ssize_t				ret;

	if (!display)
		display = display_singleton();
	ret = write(display->m_fd, &c, 1);
	(void)ret;
	col = display->col();
	if (col == display->width())
	{
		display->puts("do");
		display->puts("cr");
	}
	return (display);
}

t_display		*p_display_putstr(char *str)
{
	static t_display	*display = NULL;
	ssize_t				ret;

	if (!display)
		display = display_singleton();
	ret = write(display->m_fd, str, ft_strlen(str));
	(void)ret;
	return (display);
}

t_display		*p_display_write_prompt(void)
{
	char	*str;

	str = prompt_singleton()->to_string();
	ft_putstr_fd(1, str);
	free(str);
	return (display_singleton());
}

t_display		*p_display_termcaps_puts(char *cmd)
{
	char		*result;

	result = tgetstr(cmd, NULL);
	if (result)
		tputs(result, 1, put);
	return (display_singleton());
}
