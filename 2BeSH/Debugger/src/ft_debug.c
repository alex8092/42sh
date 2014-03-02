#include "ft_debug.h"
#include "common.h"

#ifdef BESH_DEBUG
# include <stdlib.h>
# include <stdio.h>

void	debug_write(char *str)
{
	char	tmp[2048];
	ssize_t	ret;

	ret = sprintf(tmp, "echo \"%s\" > .tmp_debug", str);
	tmp[ret] = 0;
	system(tmp);
	system("nc localhost 4242 < .tmp_debug");
	system("rm .tmp_debug");
}

# else

void	debug_write(char *str)
{
}

#endif

