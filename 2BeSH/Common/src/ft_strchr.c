#include "common.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)s;
	if (tmp)
	{
		i = 0;
		while (tmp[i] && tmp[i] != (char)c)
			++i;
		if (tmp[i] == (char)c)
			return (tmp + i);
	}
	return (0);
}
