/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_job_bg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:58 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:42:58 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_jobcontrol.h"
#include "ft_security.h"
#include <signal.h>
#include <sys/ptrace.h>

pid_t	p_job_get_bg(void)
{
	pid_t		pid;
	t_jobitem	*job;
	t_jobitem	*cur;

	pid = -1;
	job = NULL;
	cur = job_singleton()->begin;
	while (cur)
	{
		if (cur->stat == JS_STOP)
			job = cur;
		cur = cur->next;
	}
	if (job)
		pid = job->pid;
	return (pid);
}

void	p_job_set_bg(pid_t pid)
{
	t_jobitem	*cur;

	cur = job_singleton()->begin;
	while (cur)
	{
		if (cur->pid == pid)
		{
			if (cur->stat == JS_STOP)
			{
				if (kill(-getpgid(cur->pid), SIGCONT) < 0)
					return ;
			}
			cur->stat = JS_BG;
			break ;
		}
		cur = cur->next;
	}
}

void	p_job_set_fg(pid_t pid)
{
	t_jobitem	*cur;

	cur = job_singleton()->begin;
	while (cur)
	{
		if (cur->pid == pid)
		{
			if (cur->stat == JS_STOP)
			{
				security_singleton()->active_raw(false);
				if (kill(-getpgid(cur->pid), SIGCONT) < 0)
				{
					ft_putstr_fd(2, "error");
					return ;
				}
			}
			cur->stat = JS_RUN;
			job_singleton()->wait(cur->pid);
			break ;
		}
		cur = cur->next;
	}
}

void	p_job_print_jobs(void)
{
	t_jobitem	*cur;
	int			index;

	cur = job_singleton()->begin;
	index = 1;
	while (cur)
	{
		if (cur->stat != JS_RUN)
			++index;
		cur = cur->next;
	}
}

pid_t	p_job_get_fg(void)
{
	t_jobitem	*cur;

	cur = job_singleton()->begin;
	while (cur)
	{
		if (cur->stat == JS_RUN)
			return (cur->pid);
		cur = cur->next;
	}
	return (-1);
}
