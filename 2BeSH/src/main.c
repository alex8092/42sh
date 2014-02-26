#include "ft_lexer.h"
#include "ft_security.h"
#include <stdio.h>

void	end(void)
{
	return ;
}

int		main(int ac, char **av)
{
	security_singleton()->activeRaw(true);
	lexer_singleton()->onComplete(end)->start();
	(void)ac;
	(void)av;
	security_singleton()->activeRaw(false);
	return (0);
}
