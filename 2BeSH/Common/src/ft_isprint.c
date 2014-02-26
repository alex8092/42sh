#include "common.h"

t_bool	ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
		return (true);
	return (false);
}
