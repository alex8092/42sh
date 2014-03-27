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

t_bool		p_ex_build(t_operation *cur, char **tab, t_bool first, pid_t *son)
{
	const t_buildins	*bi = buildins_singleton();
	int					save[3];

	if (bi->is_buildin(cur->lex->str))
	{
		IF_UNI((!first), (*son = fork()));
		if ((!first && *son == 0) || first)
		{
			save2(save);
			IF_UNI((cur->fd_in != -1), (dup2(cur->fd_in, 0)));
			IF_UNI((cur->fd_out != 1), (dup2(cur->fd_out, 1)));
			IF_UNI((cur->fd_err != -1), (dup2(cur->fd_err, 2)));
			exec_singleton()->m_status = bi->exec(cur->lex->str, tab);
			IF_UNI((!first), (exit(exec_singleton()->m_status)));
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
