/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_terms_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triviere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:36:34 by triviere          #+#    #+#             */
/*   Updated: 2014/03/22 05:46:50 by triviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_private.h"
#include "ft_event.h"
#include "ft_stocker.h"
#include "ft_prompt.h"
#include <term.h>
#include <unistd.h>
#include <stdlib.h>

int			p_display_width(void)
{
	int		width;

	width = tgetnum("co");
	if (!width)
		width = 0;
	return (width);
}

int			p_display_height(void)
{
	int		height;

	height = tgetnum("li");
	if (!height)
		height = 0;
	return (height);
}

int			p_display_get_column(void)
{
	t_display		*display;
	t_stocker		*stocker;
	t_prompt		*prompt;
	int				pos;

	display = display_singleton();
	stocker = stocker_singleton();
	prompt = prompt_singleton();
	pos = stocker->m_pos;
	if (pos >= (display->width() - prompt->size()))
		pos = ((pos + prompt->size()) % display->width());
	else
		pos += prompt->size();
	return (++pos);
}

void		p_display_resize(int signal)
{
	int		i;

	i = stocker_singleton()->size();
	display_singleton()->puts("cl");
	display_singleton()->putstr(prompt_singleton()->to_string());
	display_singleton()->putstr(stocker_singleton()->to_string());
	event_singleton()->init_terms();
	while (i-- > stocker_singleton()->current_pos())
		display_singleton()->mv_prev();
	(void)signal;
}
