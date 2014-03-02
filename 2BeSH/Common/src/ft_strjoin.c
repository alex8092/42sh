#include "common.h"
#include <unistd.h>

char	*ft_strjoin(const char *str, const char *str2)
{
	const size_t	len_str1 = ft_strlen(str);
	const size_t	len_str2 = ft_strlen(str2);
	char			*res;
	size_t			i;
	size_t			j;

	res = (char *)ft_memalloc(sizeof(char) * (len_str1 + len_str2 + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		res[j] = str[i];
		++i;
		++j;
	}
	i = 0;
	while (str2[i])
	{
		res[j] = str[i];
		++i;
		++j;
	}
	return (res);
}
