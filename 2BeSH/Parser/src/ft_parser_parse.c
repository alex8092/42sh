#include "ft_parser_private.h"
#include "common.h"
#include <stdio.h>
#include <unistd.h>

void	p_parser_parse(char *str)
{
	int		index;
	char	*tmp;

	tmp = str;
	while ((index = ft_findfirstof(tmp, ";|&")) != -1)
	{
		if (tmp[index] == ';' || tmp[index + 1] == tmp[index])
		{
			write(1, str, index + (tmp - str));
			write(1, "\n", 1);
			if (tmp[index] != ';')
				++index;
			str = tmp + index + 1;
		}
		tmp = tmp + index + 1;
	}
}
