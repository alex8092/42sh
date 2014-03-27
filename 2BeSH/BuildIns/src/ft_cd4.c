/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:22:26 by thrivier          #+#    #+#             */
/*   Updated: 2014/03/27 17:22:31 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_environment.h"
#include <stdlib.h>

char			*ft_get_pwd(char *s)
{
	char	*str;

	if ((str = ft_strdup(env_singleton()->get(s))))
		return (str);
	return (NULL);
}

char			*ft_cd_error(char **str, int i)
{
	if (!*str)
		ft_putstr_fd(2, ".: cd :. : Bad Adress\n");
	else
	{
		if (i == 0)
			ft_putstr_fd(2, ".: cd :. : No file or Directory : ");
		else if (i == 1)
			ft_putstr_fd(2, ".: cd :. Symbolic link error ");
		else if (i == 2)
			ft_putstr_fd(2, ".: cd :. Not a directory ");
		else if (i == 3)
			ft_putstr_fd(2, ".: cd : Symbolic link : ");
		ft_putstr_fd(2, *str);
		ft_putchar_fd(2, '\n');
	}
	ft_strdel(str);
	return (NULL);
}
