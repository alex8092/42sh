#include "ft_security_private.h"

void		p_security_exit_critical(char *error)
{
	write(2, error, ft_strlen(error));
	_exit(1);
}
