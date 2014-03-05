#include "common.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s && len > 0)
	{
		str = (char *)ft_memalloc(sizeof(char) * (len + 1));
		ft_strncpy(str, s + start, len);
		str[len] = 0;
		return (str);
	}
	return (ft_strdup(""));
}
