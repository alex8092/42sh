/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:07 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:47:05 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_jobcontrol.h"
#include "ft_history.h"
#include <signal.h>

int		p_buildins_exit(char **argv)
{
	int	status;

	status = 0;
	if (argv && *argv && *(argv + 1))
		status = ft_atoi(*(argv + 1));
	history_singleton()->unload();
	job_singleton()->exit(status);
	return (1);
}
