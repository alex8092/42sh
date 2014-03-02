#include "ft_display_private.h"
#include <stdlib.h>
#include <unistd.h>

static void			display_init(t_display *display)
{
	p_display_init_attributes(display);
	p_display_init_methodes(display);
}

t_display			*display_singleton(void)
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

