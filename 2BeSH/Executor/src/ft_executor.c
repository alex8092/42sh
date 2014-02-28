#include "ft_executor.h"
#include "common.h"
#include "ft_buildins.h"
#include <unistd.h>
#include <stdio.h>

static void	executor_start(t_operation *ops)
{
	t_operation	*cur;
	const t_buildins	*bi = buildins_singleton();

	cur = ops;
	while (cur)
	{
		printf("exec op : %s\n", cur->str);
		if (bi->is_buildin(cur->str))
			bi->exec(cur->str, NULL);
		cur = cur->next;
	}
	(void)ops;
}

static void	executor_init(t_executor *exec)
{
	exec->start = executor_start;
}

t_executor	*exec_singleton()
{
	static t_executor	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_executor*)ft_memalloc(sizeof(t_executor));
		if (!singleton)
			_exit(1);
		executor_init(singleton);
	}
	return (singleton);
}

