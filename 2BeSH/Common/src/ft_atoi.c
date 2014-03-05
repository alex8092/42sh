#include "common.h"
#include <stdlib.h>

int	ft_atoi(char const *number)
{
	int		res;
	char	c;
	char	neg;
	char	*tmp;

	neg = 0;
	if (number)
	{
		tmp = ft_strtrim(number);
		number = tmp;
		if ((*number == '-' || *number == '+') && (++number))
		{
			if (*(number - 1) == '-')
				neg = 1;
		}
		res = 0;
		while (number && (c = *number) && c >= '0' && c <= '9')
		{
			res = (res * 10) + (*number - '0');
			++number;
		}
		free(tmp);
		return ((neg) ? res * -1 : res);
	}
	return (0);
}
