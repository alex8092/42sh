#include "common.h"

void	ft_bzero(void *ptr, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		((char *)ptr)[index] = 0;
		++index;
	}
}
