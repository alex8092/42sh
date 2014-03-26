/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:27 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:47:31 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_environment.h"

int		p_buildins_unsetenv(char **argv)
{
	size_t	size;
	char	*name;
	size_t	i;

	i = 1;
	if (argv[i])
	{
		while (argv[i])
		{
			size = ft_strlen(argv[i]);
			name = env_singleton()->get(argv[i]);
			if (name && ft_strcmp(argv[i], "PATH")
				&& ft_strcmp(argv[i], "USER")
				&& ft_strcmp(argv[i], "PWD") && ft_strcmp(argv[i], "OLDPWD"))
				env_singleton()->unset(name, size);
			i++;
		}
		return (0);
	}
	else
		ft_putstr_fd(2, "unsetenv: Too few arguments\n");
	return (1);
}
