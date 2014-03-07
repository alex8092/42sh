#include "ft_display_private.h"
#include "common.h"
#include <term.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int			p_display_width(void)
{
	return (tgetnum("co"));
}

int			p_display_height(void)
{
	return (tgetnum("li"));
}

void		p_display_resize(int signal)
{
	t_display		*display;

	display = display_singleton();
	(void)signal;
	printf("\nWidth : %d | Height : %d\n", display->width(), display->height());
}
