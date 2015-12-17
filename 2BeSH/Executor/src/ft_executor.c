/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:55 by amerle            #+#    #+#             */
/*   Updated: 2014/03/26 16:50:17 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"
#include "ft_buildins.h"
#include "ft_validator.h"
#include "ft_environment.h"
#include "ft_jobcontrol.h"
#include "ft_security.h"
#include "ft_display.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

static int	exec_cmd(t_operation *cur, int i, pid_t *son, int *pipes)
{
	t_lex	*l;
	char	**tab;

	l = NULL;
	tab = NULL;
	while ((!l && ft_assi_lex(&l, cur->lex)) || (l && ft_assi_lex(&l, l->next)))
		tab = ft_tabstradd(tab, ft_strdup(l->str));
	if (!p_ex_build(cur, tab, i == 0 && !cur->next, son))
	{
		if (!validator_singleton()->is_valid(cur))
			return (0);
		security_singleton()->active_raw(false);
		if ((*son = fork()) == 0)
		{
			ft_apply_dup(cur);
			if (execve(cur->exec_file, tab, env_singleton()->m_env) == -1)
				_exit(-1);
		}
	}
	if (*son != -1 && cur->next)
		close(pipes[i + 1]);
	ft_tabstrdel(tab);
	return (1);
}

static void	final_exec(t_operation *op, pid_t son)
{
	int	status;

	if (son > 0)
	{
		exec_singleton()->m_current = son;
		while (1)
		{
			waitpid(son, &status, 0);
			if (WIFEXITED(status) || WIFSIGNALED(status))
			{
				exec_singleton()->m_status = WEXITSTATUS(status);
				if (WIFSIGNALED(status))
					ft_putstr_fd(1, "\n");
				break ;
			}
			else
				kill(son, SIGCONT);
		}
		exec_singleton()->m_current = -1;
		security_singleton()->active_raw(true);
	}
	free(op->full_str);
	exec_singleton()->m_first = false;
}

static void	executor_start(t_operation *op)
{
	t_operation			*cur;
	pid_t				son;
	int					pipes[2 * ft_size_pipes(op)];
	int					i;

	cur = op;
	exec_singleton()->m_status = 1;
	ft_create_pipes(cur, ft_size_pipes(op), pipes);
	son = -1;
	i = 0;
	while (cur)
	{
		if (!validator_singleton()->valid_redirects(cur))
		{
			exec_singleton()->m_first = false;
			exec_singleton()->m_status = 1;
			return ;
		}
		if (!exec_cmd(cur, i, &son, pipes))
			return ;
		i += 2;
		cur = cur->next;
	}
	ft_close_pipes(ft_size_pipes(op), pipes);
	final_exec(op, son);
}

static void	executor_init(t_executor *exec)
{
	exec->m_current = -1;
	exec->start = executor_start;
	exec->get_current_job = p_exec_get_current_job;
	exec->wait_current_job = p_exec_wait_current_job;
	exec->get_status = p_exec_get_status;
}

t_executor	*exec_singleton(void)
{
	static t_executor	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_executor*)ft_memalloc(sizeof(t_executor));
		executor_init(singleton);
	}
	return (singleton);
}
