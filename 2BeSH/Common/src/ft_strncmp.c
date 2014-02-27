#include "common.h"

int	ft_strncmp(char *str, char *str2, size_t n)
{
	size_t	index;

	index = 0;
	while (str[index] && str2[index] && str[index] == str2[index] && index < n)
		++index;
	if (index == n)
		return (0);
	return (str2[index] - str[index]);
}
