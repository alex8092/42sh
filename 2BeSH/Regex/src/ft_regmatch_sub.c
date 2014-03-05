#include "ft_regex.h"

char	*ft_regmatch_sub(char *str, char *pattern)
{
	char	*match;
	size_t	len;

	if (str && pattern)
	{
		match = ft_regmatch(str, pattern, &len);
		if (match)
		{
			match = ft_strsub(match, 0, len);
			return (match);
		}
	}
	return (NULL);
}
