/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:56 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:42:56 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"
#include <sys/wait.h>

void	p_exec_wait_current_job(void)
{
	int	status;

	if (exec_singleton()->m_current != 0)
	{
		waitpid(exec_singleton()->m_current, &status, 0);
	}
}
