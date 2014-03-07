#include "ft_security_private.h"
#include "ft_display.h"
#include <signal.h>

void		p_security_init_attributes(t_security *security)
{
	(void)security;
}

void		p_security_init_methodes(t_security *security)
{
	security->activeRaw = p_security_active_raw;
	security->critical = p_security_exit_critical;
}

void		p_security_init_signal(void)
{
	signal(SIGWINCH, display_singleton()->resize);
}
