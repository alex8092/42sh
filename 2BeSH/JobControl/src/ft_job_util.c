/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_job_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:59 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:42:59 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_jobcontrol.h"
#include "ft_security.h"
#include <sys/stat.h>
#include <signal.h>

void	p_job_exit(int status)
{
	t_jobitem	*cur;

	cur = job_singleton()->begin;
	while (cur)
	{
		kill(-getpgid(cur->pid), SIGKILL);
		cur = cur->next;
	}
	security_singleton()->active_raw(false);
	tcsetattr(0, TCSADRAIN, &job_singleton()->shell_modes);
	_exit(status);
}
