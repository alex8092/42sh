/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:13 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:47:12 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_jobcontrol.h"
#include <sys/types.h>
#include <signal.h>

int		p_buildins_fg(char **argv)
{
	pid_t	pid;

	pid = -1;
	if (!argv[1])
		pid = job_singleton()->get(job_singleton()->m_size - 1);
	else if (argv[1][0] == '%')
		pid = job_singleton()->get(ft_atoi(argv[1] + 1) + 1);
	if (pid != -1)
		job_singleton()->set_fg(pid);
	return (0);
}
