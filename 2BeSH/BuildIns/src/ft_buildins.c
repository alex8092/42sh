#include "ft_buildins_private.h"
#include "common.h"
#include <unistd.h>

static t_buildin	*buildins_get(char *name)
{
	static t_buildin	refs[] = 
	{
		{ "cd", p_buildins_cd }
	};
	size_t				index;

	index = 0;
	while (index < sizeof(refs) / sizeof(t_buildin))
	{
		if (!ft_strcmp(refs[index].name, name))
			return (&refs[index]);
		++index;
	}
	return (NULL);
}

static t_bool	buildins_isbuildins(char *name)
{
	t_buildin	*find;

	find = buildins_get(name);
	if (find)
		return (true);
	return (false);
}

static void		buildins_init(t_buildins *bi)
{
	bi->is_buildin = buildins_isbuildins;
}

t_buildins		*buildins_singleton(void)
{
	static t_buildins	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_buildins*)ft_memalloc(sizeof(t_buildins));
		if (!singleton)
			_exit(1);
		buildins_init(singleton);
	}
	return (singleton);
}
