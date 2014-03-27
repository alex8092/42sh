/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:18 by amerle            #+#    #+#             */
/*   Updated: 2014/03/27 17:43:15 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_environment.h"

int		p_buildins_setenv(char **ag)
{
	size_t	i;

	if (!ag[1])
	{
		i = 0;
		while (i < env_singleton()->size())
		{
			ft_putstr_fd(1, env_singleton()->m_env[i]);
			ft_putstr_fd(1, "\n");
			++i;
		}
	}
	else if (!ag[2] && ft_strcmp(ag[1], "PWD") && ft_strcmp(ag[1], "OLDPWD"))
		env_singleton()->set(ag[1], "");
	else if (!ag[3] && ft_strcmp(ag[1], "PWD") && ft_strcmp(ag[1], "OLDPWD"))
		env_singleton()->set(ag[1], ag[2]);
	else if (ft_strcmp(ag[1], "PWD") && ft_strcmp(ag[1], "OLDPWD"))
	{
		ft_putstr_fd(2, "setenv : Too many arguments.\n");
		return (1);
	}
	return (0);
}
