#include "common.h"
#include <unistd.h>
#include <stdlib.h>

char	**ft_tabstradd(char **tab, char *str)
{
	char			**newtab;
	size_t			size_tab;

	size_tab = (tab) ? ft_tabstrlen(tab) : 0;
	if (tab)
	{
		newtab = (char **)ft_memalloc(sizeof(char *) * (size_tab + 2));
		ft_memcpy(newtab, tab, sizeof(char *) * size_tab);
	}
	else
		newtab = (char **)ft_memalloc(sizeof(char *) * 2);
	newtab[size_tab] = str;
	free(tab);
	return (newtab);
}
