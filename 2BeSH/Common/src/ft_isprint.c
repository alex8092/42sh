#include "common.h"

t_bool	ft_isprint(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (true);
	return (false);
}
