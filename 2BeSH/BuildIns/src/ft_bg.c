/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:31 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:46:34 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_jobcontrol.h"

int		p_buildins_bg(char **argv)
{
	pid_t	pid;

	pid = -1;
	if (!argv[1])
		pid = job_singleton()->get_bg();
	if (pid != -1)
		job_singleton()->set_bg(pid);
	return (0);
}
