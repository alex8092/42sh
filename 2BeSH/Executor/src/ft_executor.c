#include "ft_executor.h"
#include "common.h"
#include "ft_buildins.h"
#include "ft_debug.h"
#include <unistd.h>
#include <stdio.h>

static void	executor_start(t_operation *op)
{
	t_operation	*cur;
	const t_buildins	*bi = buildins_singleton();

	cur = op;
	while (cur)
	{
		debug(3, "exec op : ", cur->lex->str, "\n");
		if (bi->is_buildin(cur->lex->str))
			bi->exec(cur->lex->str, NULL);
		cur = cur->next;
	}
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

