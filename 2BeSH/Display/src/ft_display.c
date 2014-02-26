#include "ft_display.h"
#include <stdlib.h>
#include <unistd.h>


static t_display	*display_char(char c)
{
	write(1, &c, 1);
	return (display_singleton());
}

static void			display_init(t_display *dis)
{
	dis->display_char = display_char;
	(void)dis;
}

t_display			*display_singleton()
{
	static t_display	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_display*)malloc(sizeof(t_display));
		if (!singleton)
			exit(1);
		display_init(singleton);
	}
	return (singleton);
}

