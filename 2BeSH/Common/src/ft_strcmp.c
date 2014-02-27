#include "common.h"

int	ft_strcmp(char *str, char *str2)
{
	int	index;

	index = 0;
	while (str[index] && str2[index] && str[index] == str2[index])
		++index;
	return (str2[index] - str[index]);
}
