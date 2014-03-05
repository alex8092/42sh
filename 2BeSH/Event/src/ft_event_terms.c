#include "ft_event_private.h"
#include "ft_security.h"
#include "ft_display.h"
#include "ft_environment.h"
#include <term.h>

#include <stdio.h>

t_event		*p_event_init_terms(void)
{
	char		*termtype;
	t_security	*security;
	static char	buffer[2048];

	security = security_singleton();
	termtype = env_singleton()->get("TERM");
	if (termtype)
	{
		if (tgetent(buffer, termtype) > 0)
			display_singleton()->set_active(true);
		else
			display_singleton()->set_active(false);
	}
	return (event_singleton());
}
