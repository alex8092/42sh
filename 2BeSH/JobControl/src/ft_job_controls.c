/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_job_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:59 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:42:59 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_jobcontrol.h"
#include "ft_security.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

t_bool	ft_job_is_active(void)
{
	t_jobitem	*cur;
	int			status;

	cur = job_singleton()->begin;
	while (cur)
	{
		if (!waitpid(cur->pid, &status, WNOHANG))
			return (true);
		cur = cur->next;
	}
	return (false);
}

void	ft_job_remove(pid_t pid)
{
	t_jobitem	*cur;
	t_jobitem	*last;

	last = NULL;
	cur = job_singleton()->begin;
	while (cur)
	{
		if (cur->pid == pid)
		{
			if (cur->stat == JS_STOP)
				kill(cur->pid, SIGKILL);
			if (last)
				last->next = cur->next;
			else
				job_singleton()->begin = cur->next;
			if (!cur->next)
				job_singleton()->end = last;
			if (!job_singleton()->end)
				job_singleton()->begin = NULL;
			--job_singleton()->m_size;
			break ;
		}
		last = cur;
		cur = cur->next;
	}
}

int		ft_job_wait(pid_t pid)
{
	int			status;
	t_jobitem	*item;

	item = job_singleton()->begin;
	while (item && item->pid != pid)
		item = item->next;
	if (item && pid == waitpid(pid, &status, WUNTRACED))
	{
		security_singleton()->active_raw(true);
		if (!WIFSTOPPED(status))
		{
			ft_job_remove(pid);
			ft_putchar_fd(1, '\n');
			return (WEXITSTATUS(status));
		}
		else
		{
			if (item)
				item->stat = JS_STOP;
			ft_job_remove(pid);
			ft_putchar_fd(1, '\n');
			return (1);
		}
	}
	return (-1);
}

pid_t	ft_job_get(int index)
{
	t_jobitem	*cur;
	int			i;

	cur = job_singleton()->begin;
	i = 0;
	while (cur && i < index)
	{
		++i;
		cur = cur->next;
	}
	if (cur && i == index)
		return (cur->pid);
	return (-1);
}
