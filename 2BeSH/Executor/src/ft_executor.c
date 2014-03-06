#include "ft_executor.h"
#include "common.h"
#include "ft_buildins.h"
#include "ft_debug.h"
#include "ft_validator.h"
#include "ft_environment.h"
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
	int			status;
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
	printf("size : %d\n", ft_size_pipes(op));
	i = 0;
	while (cur)
	{
		lex = cur->lex;
		tab = NULL;
		while (lex)
		{
			printf("exec part[%s]\n", lex->str);
			tab = ft_tabstradd(tab, lex->str);
			lex = lex->next;
		}
		/*debug(3, "exec op : ", cur->lex->str, "\n");*/
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
				execve(cur->exec_file, tab, env_singleton()->m_env);
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
	waitpid(son, &status, 0);
}

static void	executor_init(t_executor *exec)
{
	exec->start = executor_start;
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

