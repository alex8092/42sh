/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildins_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:54 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:46:49 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buildins_private.h"
#include <unistd.h>

t_buildin	*p_buildins_new(t_buildin *p, char *name, int (*f)(char **argv))
{
	t_buildin	*new_build;

	new_build = (t_buildin*)ft_memalloc(sizeof(t_buildin));
	if (!new_build)
		_exit(1);
	new_build->name = name;
	new_build->exec = f;
	if (p)
		p->next = new_build;
	return (new_build);
}

void		p_buildins_init_builds(t_buildins *bi)
{
	t_buildin	*cur;

	cur = p_buildins_new(NULL, "cd", p_buildins_cd);
	bi->m_begin = cur;
	cur = p_buildins_new(cur, "echo", p_buildins_echo);
	cur = p_buildins_new(cur, "exit", p_buildins_exit);
	cur = p_buildins_new(cur, "setenv", p_buildins_setenv);
	cur = p_buildins_new(cur, "unsetenv", p_buildins_unsetenv);
	cur = p_buildins_new(cur, "history", p_buildins_history);
	cur = p_buildins_new(cur, "false", p_buildins_false);
	cur = p_buildins_new(cur, "true", p_buildins_true);
	cur = p_buildins_new(cur, "test_amerle", p_buildins_test_amerle);
}
