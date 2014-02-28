#include "common.h"
#include <unistd.h>

void	ft_memcpy(void *dest, void * const src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((char *)dest)[i] = ((char *)src)[i];
		++i;
	}
}
