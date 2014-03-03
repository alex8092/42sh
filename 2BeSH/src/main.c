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
	//* TEST TRIVIERE START 
	printf("--------- TEST TRIVIERE START ---------\n");


	printf("---------  TEST TRIVIERE END  ---------\n\n");
	// TEST TRIVIERE END */



	/* TEST AMERLE BEGIN
	printf("--------- TEST AMERLE START ---------\n");
	printf("PATH : %s\n", env_singleton()->get("PATH"));
	printf("\"cd\" buildins ? : %d\n", buildins_singleton()->is_buildin("cd"));
	printf("\"echo\" buildins ? : %d\n", buildins_singleton()->is_buildin("echo"));
	printf("\"exit\" buildins ? : %d\n", buildins_singleton()->is_buildin("exit"));
	printf("\"tamere\" buildins ? : %d\n", buildins_singleton()->is_buildin("tamere"));
	display_singleton()->set_out(2)->writec('O')->writec('K')->writec('\n')->set_out(1);
	t_operation	*op = (t_operation *)ft_memalloc(sizeof(t_operation));
	op->str = "tamere";
	resolver_singleton()->start(op);
	printf("--------- TEST AMERLE START ---------\n");
	// TEST AMERLE END */



	/* TEST THRIVIER START
	printf("--------- TEST THRIVIER START ---------\n");
	printf("--------- TEST THRIVIER START ---------\n");
	 // TEST THRIVIER END */



	/* TEST TUARDOUI START
	printf("--------- TEST TUARDOUI START ---------\n");
	printf("--------- TEST TUARDOUI START ---------\n");
	// TEST TUARDOUI END */



	security_singleton()->activeRaw(true);
	lexer_singleton()->onComplete(parser_singleton()->start)->start();
	(void)ac;
	(void)av;
	security_singleton()->activeRaw(false);
	return (0);
}
