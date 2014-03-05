#include "ft_development.h"
#include "common.h"
#include "ft_lexer.h"

static char		*dev_start(char *base)
{

	return (base);
}

static void		ft_dev_init(t_development *dev)
{
	dev->start = dev_start;
	(void)dev;
}

t_development	*dev_singleton()
{
	static t_development	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_development*)ft_memalloc(sizeof(t_development));
		ft_dev_init(singleton);
	}
	return (singleton);
}
