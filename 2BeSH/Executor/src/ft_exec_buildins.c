/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_buildins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:55 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 06:42:16 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"
#include "ft_buildins.h"
#include <stdlib.h>

static void	save2(int *save)
{
	save[0] = dup(0);
	save[1] = dup(1);
	save[2] = dup(2);
}

static void	mydup(t_bool cond, int fd, int fd2)
{
	if (cond)
		dup2(fd, fd2);
}

t_bool		p_ex_build(t_operation *cur, char **tab, t_bool first, pid_t *son)
{
	const t_buildins	*bi = buildins_singleton();
	int					save[3];

	if (bi->is_buildin(cur->lex->str))
	{
		*son = (!first) ? fork() : *son;
		if ((!first && *son == 0) || first)
		{
			save2(save);
			mydup(cur->fd_in != -1, cur->fd_in, 0);
			mydup(cur->fd_out != 1, cur->fd_out, 1);
			mydup(cur->fd_err != -1, cur->fd_err, 2);
			exec_singleton()->m_status = bi->exec(cur->lex->str, tab);
			if (!first)
				exit(exec_singleton()->m_status);
		}
		if (first)
		{
			dup2(save[0], 0);
			dup2(save[1], 1);
			dup2(save[2], 2);
		}
		return (true);
	}
	return (false);
}
