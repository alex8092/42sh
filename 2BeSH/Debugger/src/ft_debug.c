#include "ft_debug.h"
#include "common.h"
#include <stdlib.h>

void	debug_write(char *str)
{
#ifdef BESH_DEBUG
	system(ft_strjoin(ft_strjoin("echo \"", str), "\" > .tmp_debug"));
	system("nc localhost 4242 < .tmp_debug");
	system("rm .tmp_debug");
#endif
}

