#include "common.h"

int	ft_findfirstof(char *str, char *ref)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (ft_isinarray(str[index], ref))
			return (index);
		++index;
	}
	return (-1);
}
