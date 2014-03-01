#include "common.h"

t_bool	ft_isinarray(char c, char *ref)
{
	int		i;

	i = 0;
	while (ref[i])
	{
		if (ref[i] == c)
			return (true);
		++i;
	}
	return (false);
}
