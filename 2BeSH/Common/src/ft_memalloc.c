#include "common.h"
#include "ft_security.h"
#include <stdlib.h>

void	*ft_memalloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		ft_bzero(ptr, size);
	else
		security_singleton()->critical("malloc");
	return (ptr);
}
