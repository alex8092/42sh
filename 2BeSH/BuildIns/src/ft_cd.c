/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:57 by amerle            #+#    #+#             */
/*   Updated: 2014/03/27 17:40:29 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include "ft_environment.h"
#include "ft_resolver.h"
#include <ft/flagger.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

static void			ft_execute_cd(char **chemin)
{
	int	ret;

	ret = chdir(*chemin);
	(void)ret;
	ft_actualisation(*chemin);
}

static t_flagger	*create_flagger(char *name)
{
	t_flagger	*flagger;
	char		*str;

	str = resolver_singleton()->resolv_path("~/.2BeSH/conf/cd.conf");
	flagger = ft_flagger_create(str, name);
	free(str);
	return (flagger);
}

int					begin_cd(t_flagger **flagger, char **argv)
{
	char	*chemin;

	chemin = NULL;
	if (!argv[0])
		chemin = ft_get_pwd("HOME");
	else if (!argv[1])
		chemin = find_pwd(argv[0], *flagger, -1);
	else if (!argv[2])
		chemin = remplace_in_pwd(argv[0], argv[1], *flagger);
	else
	{
		ft_putstr_fd(2, ".: cd :. error too few arguments\n");
		return (1);
	}
	(*flagger)->free(flagger);
	if (chemin)
	{
		ft_execute_cd(&chemin);
		free(chemin);
	}
	else
		return (1);
	return (0);
}

int					p_buildins_cd(char **argv)
{
	t_flagger	*flagger;

	flagger = create_flagger(argv[0]);
	++argv;
	flagger->m_stop_single_tiret = true;
	if (flagger->parse(flagger, &argv))
		return (begin_cd(&flagger, argv));
	flagger->print_help(flagger);
	flagger->free(&flagger);
	return (1);
}
