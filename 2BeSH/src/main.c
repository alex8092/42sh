#include "ft_lexer.h"
#include "ft_parser.h"
#include "ft_security.h"
#include "ft_environment.h"
#include "ft_buildins.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	printf("PATH : %s\n", env_singleton()->get("PATH"));
	printf("\"cd\" buildins ? : %d\n", buildins_singleton()->is_buildin("cd"));
	printf("\"fake\" buildins ? : %d\n", buildins_singleton()->is_buildin("fake"));
	security_singleton()->activeRaw(true);
	lexer_singleton()->onComplete(parser_singleton()->start)->start();
	(void)ac;
	(void)av;
	security_singleton()->activeRaw(false);
	return (0);
}
