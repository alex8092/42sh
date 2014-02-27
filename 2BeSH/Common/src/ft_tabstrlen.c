#include "common.h"

int	ft_tabstrlen(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		++size;
	return (size);
}
