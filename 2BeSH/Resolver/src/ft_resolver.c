#include "ft_resolver.h"
#include "common.h"
#include "ft_executor.h"
#include <stdio.h>

static void	resolver_start(t_operation *ops)
{
	static t_resolver	*rv = NULL;
	t_operation			*cur;
	char				**tmp;

	if (!rv)
		rv = resolver_singleton();
	cur = ops;
	while (cur)
	{
		printf("resolv op : %s\n", cur->str);
		tmp = ft_strsplit(cur->str, '\"', true);
		while (*tmp)
		{
			printf("resolv op[part] : %s\n", *tmp);
			++tmp;
		}
		cur = cur->next;
	}
	exec_singleton()->start(ops);
	(void)ops;
}

static void	resolver_init(t_resolver *rv)
{
	rv->start = resolver_start;
}

t_resolver	*resolver_singleton()
{
	static t_resolver	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_resolver*)ft_memalloc(sizeof(t_resolver));
		if (!singleton)
			_exit(1);
		resolver_init(singleton);
	}
	return (singleton);
}

