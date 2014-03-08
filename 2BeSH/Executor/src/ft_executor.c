#include "ft_executor.h"
#include "common.h"
#include "ft_buildins.h"
#include "ft_debug.h"
#include "ft_validator.h"
#include "ft_environment.h"
#include "ft_security.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

static void	executor_start(t_operation *op)
{
	t_operation	*cur;
	const t_buildins	*bi = buildins_singleton();
	t_lex		*lex;
	char		**tab;
	pid_t		son;
	int			pipes[2 * ft_size_pipes(op)];
	int			i;
	int			size;

	cur = op;
	i = 0;
	size = ft_size_pipes(op);
	while (size > 1 && i < size)
	{
		pipe(pipes + i * 2);
		++i;
	}
	i = 0;
	while (cur)
	{
		lex = cur->lex;
		tab = NULL;
		while (lex)
		{
			tab = ft_tabstradd(tab, lex->str);
			lex = lex->next;
		}
		if (bi->is_buildin(cur->lex->str))
			bi->exec(cur->lex->str, tab);
		else if (validator_singleton()->is_valid(cur))
		{
			son = fork();
			if (son == 0)
			{
				if (cur->next)
				{
					dup2(pipes[i + 1], 1);
				}
				if (i != 0)
				{
					dup2(pipes[i - 2], 0);
				}
				if (execve(cur->exec_file, tab, env_singleton()->m_env) == -1)
					_exit(-1);
			}
			else if (son != -1)
			{
				if (cur->next)
					close(pipes[i + 1]);
			}
		}
		i += 2;
		cur = cur->next;
		(void)pipes;
	}
	exec_singleton()->m_current = son;
	exec_singleton()->wait_current_job();
	security_singleton()->activeRaw(true);
}

static void	executor_init(t_executor *exec)
{
	exec->m_current = 0;
	exec->start = executor_start;
	exec->get_current_job = p_exec_get_current_job;
	exec->wait_current_job = p_exec_wait_current_job;
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

