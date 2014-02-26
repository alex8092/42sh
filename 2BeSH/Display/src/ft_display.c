#include "ft_display.h"
#include <stdlib.h>

static void	display_init(t_display *dis)
{
	(void)dis;
}

t_display	*display_singleton()
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
