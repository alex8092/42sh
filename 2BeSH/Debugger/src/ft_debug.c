#include "ft_debug.h"
#include "common.h"

#ifdef BESH_DEBUG
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

void	debug(int n, ...)
{
	va_list	list;
	int		i;

	va_start(list, n);
	i = 0;
	while (i < n)
	{
		debug_write(va_arg(list, char *));
		++i;
	}
}

void	debug_write(char *str)
{
	char	tmp[2048];
	ssize_t	ret;
	size_t	i;

	ret = sprintf(tmp, "echo \"%s\" | tr -d '\\n' >> .tmp_debug", str);
	tmp[ret] = 0;
	system(tmp);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			system("echo "" >> .tmp_debug");
			system("nc localhost 4242 < .tmp_debug");
			system("rm .tmp_debug");
		}
		++i;
	}
}

# else

void	debug(int n, ...)
{
	(void)n;
}

void	debug_write(char *str)
{
	(void)str;
}

#endif

