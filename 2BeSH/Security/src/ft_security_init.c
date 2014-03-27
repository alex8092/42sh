/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:05 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 07:42:35 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_security_private.h"
#include "ft_jobcontrol.h"
#include "ft_display.h"
#include "ft_executor.h"
#include <sys/types.h>
#include <signal.h>

static void	do_nothing(int sig)
{
	(void)sig;
	if (sig == SIGTSTP && exec_singleton()->m_current != -1)
		kill(exec_singleton()->m_current, SIGCONT);
	else if ((sig == SIGQUIT || sig == SIGINT)
			&& exec_singleton()->m_current != -1)
		kill(exec_singleton()->m_current, sig);
}

static void	active_shell(void)
{
	pid_t	sh_pid;

	if (isatty(0))
	{
		while (tcgetpgrp(0) != (sh_pid = getpgrp()))
			kill(-sh_pid, SIGTTIN);
		sh_pid = getpid();
		if (setpgid(sh_pid, sh_pid) >= 0)
		{
			tcsetpgrp(0, sh_pid);
			job_singleton()->shell_pgid = sh_pid;
			tcgetattr(0, &job_singleton()->shell_modes);
			return ;
		}
		else
			ft_putstr_fd(2, "Error : unknow");
	}
	else
		ft_putstr_fd(2, "Error : Non interactive terminal");
	_exit(1);
}

void		p_security_init_attributes(t_security *security)
{
	(void)security;
	signal(SIGINT, do_nothing);
	signal(SIGQUIT, do_nothing);
	signal(SIGTSTP, do_nothing);
	signal(SIGTTIN, do_nothing);
	signal(SIGTTOU, do_nothing);
	signal(SIGCHLD, do_nothing);
}

void		p_security_init_methodes(t_security *security)
{
	security->active_raw = p_security_active_raw;
	security->critical = p_security_exit_critical;
}

void		p_security_init_signal(void)
{
	signal(SIGWINCH, display_singleton()->resize);
	active_shell();
}
