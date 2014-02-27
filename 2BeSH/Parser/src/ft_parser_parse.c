#include "ft_parser_private.h"
#include "common.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	p_parser_parse(char *str)
{
	int		i;
	char	*tmp;
	char	*dup;

	tmp = str;
	while ((i = ft_findfirstof(tmp, ";|&")) != -1)
	{
		if (tmp[i] == ';' || tmp[i] == '|' || tmp[i + 1] == tmp[i])
		{
			dup = ft_strndup(str, (i + (tmp - str)));
			printf("dup = %s\n", dup);
			free(dup);
			if (tmp[i] != ';')
				++i;
			str = tmp + i + 1;
		}
		tmp = tmp + i + 1;
	}
	dup = ft_strdup(str, (i + (tmp - str)));
	printf("dup = %s\n", dup);
}
