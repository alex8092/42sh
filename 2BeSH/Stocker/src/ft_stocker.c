#include "ft_stocker.h"


static void	*stocker_init(t_stocker *stocker)
{
	(void)stocker;
}


t_stocker			*stocker_singleton()
{
	static t_stocker	*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_stocker*)malloc(sizeof(t_stocker));
		if (!singleton)
			exit(1);
		stocker_init(singleton);
	}
	return (singleton);
}
