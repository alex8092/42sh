#include "ft_security_private.h"
#include "ft_display.h"
#include "ft_executor.h"
#include <signal.h>

static void	ft_catch_sig(int sig)
{
	kill(exec_singleton()->get_current_job(), sig);
}

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
	signal(SIGQUIT, ft_catch_sig);
	signal(SIGKILL, ft_catch_sig);
	signal(SIGINT, ft_catch_sig);
	signal(SIGTSTP, ft_catch_sig);
}
