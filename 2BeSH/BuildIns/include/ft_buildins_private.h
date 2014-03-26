/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildins_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:28 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:46:29 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILDINS_PRIVATE_H
# define FT_BUILDINS_PRIVATE_H

# include "ft_buildins.h"
# include <ft/flagger.h>

struct			s_buildin
{
	char		*name;
	int			(*exec)(char **argv);
	t_buildin	*next;
};

int				p_buildins_cd(char **argv);
int				p_buildins_echo(char **argv);
int				p_buildins_exit(char **argv);
int				p_buildins_setenv(char **argv);
int				p_buildins_unsetenv(char **argv);
int				p_buildins_test_amerle(char **argv);
int				p_buildins_fg(char **argv);
int				p_buildins_bg(char **argv);
int				p_buildins_jobs(char **argv);
int				p_buildins_history(char **argv);
int				p_buildins_false(char **argv);
int				p_buildins_true(char **argv);

char			*remplace_in_pwd(char *s1, char *s2, t_flagger *flag);

void			ft_actualisation(char *chemin);
void			p_buildins_init_builds(t_buildins *bi);

char			*find_pwd(char *str, t_flagger *flag, int offset);

t_buildin		*p_buildins_new(t_buildin *p, char *name,
int (*f)(char **argv));

#endif
