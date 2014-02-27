#include "ft_executor.h"
#include "common.h"
#include <unistd.h>

static void	executor_start(t_operation *ops)
{
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

