#include "common.h"
#include <stdlib.h>

void	*ft_memalloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		ft_bzero(ptr, size);
	return (ptr);
}
