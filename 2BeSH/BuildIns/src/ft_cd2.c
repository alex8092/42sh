/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:38:00 by amerle            #+#    #+#             */
/*   Updated: 2014/03/26 19:52:30 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_environment.h"
#include "ft_buildins_private.h"
#include <stdlib.h>
#include <ft/flagger.h>

static int	find_str(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		while (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return (i - j);
		i -= j;
		j = 0;
		i++;
	}
	return (0);
}

static int	count_slash(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '/')
			++count;
		++i;
	}
	return (count);
}

static char	*blabla(char **pwd, int i, int *count, char **s2)
{
	char	*tmp2;
	char	*tmp;

	tmp2 = NULL;
	tmp = NULL;
	tmp = ft_strndup(*pwd, i);
	*count = count_slash(tmp) - 1;
	tmp2 = ft_strjoin(tmp, *s2);
	free(tmp);
	return (tmp2);
}

char		*remplace_in_pwd(char *s1, char *s2, t_flagger *flag)
{
	int		i;
	char	*pwd;
	char	*tmp;
	int		count;
	char	*tmp2;

	i = 0;
	pwd = NULL;
	tmp = NULL;
	tmp2 = NULL;
	if ((pwd = env_singleton()->get("PWD")))
	{
		if ((i = find_str(pwd, s1)))
		{
			tmp2 = blabla(&pwd, i, &count, &s2);
			tmp = ft_strjoin(tmp2, (pwd + i + ft_strlen(s1)));
			if (!(tmp = find_pwd(tmp, flag, count)))
				ft_strdel(&tmp);
			return (tmp);
		}
		ft_putstr_fd(2, ".: cd :. String not in pwd : ");
		ft_putstr_fd(2, s1);
		ft_putchar_fd(2, '\n');
	}
	return (NULL);
}

void		ft_actualisation(char *chemin)
{
	char	*pwd;

	pwd = NULL;
	pwd = ft_strdup(env_singleton()->get("PWD"));
	env_singleton()->set("OLDPWD", pwd);
	free(pwd);
	env_singleton()->set("PWD", chemin);
}
