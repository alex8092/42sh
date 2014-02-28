#include "ft_display.h"
#include <stdlib.h>
#include <unistd.h>


static t_display	*display_char(char c)
{
	static t_display	*dis = NULL;

	if (!dis)
		dis = display_singleton();
	write(dis->m_out, &c, 1);
	return (dis);
}

static t_display	*display_on(int fd)
{
	static t_display	*dis = NULL;

	if (!dis)
		dis = display_singleton();
	dis->m_out = fd;
	return ((t_display *)dis);
}

static void			display_init(t_display *dis)
{
	dis->writec = display_char;
	dis->m_out = 1;
	dis->set_out = display_on;
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

