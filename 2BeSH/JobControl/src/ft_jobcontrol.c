/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jobcontrol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:59 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:42:59 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_jobcontrol.h"

static pid_t		job_current(void)
{
	if (job_singleton()->begin)
		return (job_singleton()->begin->pid);
	return (-1);
}

static t_jobitem	*add_job(t_jobitem *parent, pid_t pid, char *str)
{
	t_jobitem	*item;

	item = (t_jobitem*)ft_memalloc(sizeof(t_jobitem));
	item->pid = pid;
	item->stop = false;
	item->stat = JS_RUN;
	item->str = str;
	item->modes = job_singleton()->shell_modes;
	if (parent)
		parent->next = item;
	return (item);
}

static void			job_add(pid_t pid, char *str)
{
	static t_job	*job = NULL;

	if (!job)
		job = job_singleton();
	job->end = add_job(job->end, pid, str);
	if (!job->begin)
		job->begin = job->end;
	++job->m_size;
}

static void			job_init(t_job *job)
{
	job->m_size = 0;
	job->master = getpid();
	job->stop_master = false;
	job->add = job_add;
	job->current = job_current;
	job->is_active = ft_job_is_active;
	job->remove = ft_job_remove;
	job->wait = ft_job_wait;
	job->get = ft_job_get;
	job->get_bg = p_job_get_bg;
	job->get_fg = p_job_get_fg;
	job->set_bg = p_job_set_bg;
	job->set_fg = p_job_set_fg;
	job->print_jobs = p_job_print_jobs;
	job->exit = p_job_exit;
}

t_job				*job_singleton(void)
{
	static t_job	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_job*)ft_memalloc(sizeof(t_job));
		job_init(singleton);
	}
	return (singleton);
}
