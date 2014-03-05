#include "ft_display_private.h"
#include "common.h"
#include <term.h>
#include <unistd.h>
#include <stdlib.h>

void		p_display_puts(char *cmd)
{
	char		*result;

	result = tgetstr(cmd, NULL);
	if (result)
		write(1, result, ft_strlen(result));
}
