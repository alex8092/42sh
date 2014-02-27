#include "common.h"
#include <stdlib.h>

char		*ft_strndup(char *str, int nb)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char*)ft_memalloc(sizeof(char) * nb + 1);
	if (!dup)
		exit (1);
	while (i < nb)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
