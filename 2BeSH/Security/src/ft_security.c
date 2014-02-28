#include "ft_security.h"
#include <termios.h>
#include <stdlib.h>

static t_security	*secu_activeRaw(t_bool active)
{
	static struct termios	old;
	static struct termios	new;
	static t_bool			is_active = false;

	if (is_active != active)
	{
		if (active)
		{
			tcgetattr(0, &old);
			new = old;
			new.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(0, TCSANOW, &new);
		}
		else
			tcsetattr(0, TCSANOW, &old);
		is_active = active;
	}
	return (security_singleton());
}

static void	secu_init(t_security *secu)
{
	secu->activeRaw = secu_activeRaw;
}

t_security	*security_singleton(void)
{
	static t_security	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_security*)malloc(sizeof(t_security));
		secu_init(singleton);
	}
	return (singleton);
}
