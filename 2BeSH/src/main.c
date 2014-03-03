#include "ft_lexer.h"
#include "ft_parser.h"
#include "ft_security.h"
#include "ft_stocker.h"
#include "ft_environment.h"
#include "ft_buildins.h"
#include "ft_display.h"
#include "ft_resolver.h"
#include "ft_debug.h"

#include <stdio.h>

int		main(int ac, char **av)
{
	security_singleton()->activeRaw(true);
	lexer_singleton()->onComplete(parser_singleton()->start)->start();
	(void)ac;
	(void)av;
	security_singleton()->activeRaw(false);
	return (0);
}
