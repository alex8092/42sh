#include "common.h"
#include <stdio.h>
char		*ft_strdup(char *str)
{
	int		index;
	char	*dup;

	index = 0;
	dup = ft_memalloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[index])
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}
