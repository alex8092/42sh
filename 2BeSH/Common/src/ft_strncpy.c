#include "common.h"
#include <unistd.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		lim;
	long int	*dest2;
	long int	*src2;

	i = 0;
	if (dest && src && n > 0)
	{
		lim = n / sizeof(long int);
		dest2 = (long int *)dest;
		src2 = (long int *)src;
		while (i < lim)
		{
			dest2[i] = src2[i];
			++i;
		}
		i *= sizeof(long int);
		while (i < n)
		{
			dest[i] = src[i];
			++i;
		}
	}
	return (dest);
}
