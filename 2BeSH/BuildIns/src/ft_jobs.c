/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jobs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:16 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:47:16 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_jobcontrol.h"

int		p_buildins_jobs(char **argv)
{
	(void)argv;
	job_singleton()->print_jobs();
	return (0);
}
