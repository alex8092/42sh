#include "ft_stocker_private.h"
#include <stdlib.h>

int				p_stocker_size(void)
{
	return (stocker_singleton()->length);
}
