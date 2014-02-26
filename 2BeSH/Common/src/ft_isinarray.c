#include "common.h"

t_bool	ft_isinarray(char c, char *ref)
{
	while (*ref)
	{
		if (*ref == c)
			return (true);
		++ref;
	}
	return (false);
}
