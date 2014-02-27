#include "ft_lexer.h"
#include "ft_parser.h"
#include "ft_security.h"
#include "ft_stocker.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	/* TEST TRIVIERE */
		printf("%d : \n", stocker_singleton()->add_back('H')->add_back('e')->add_back('l')->add_back('l')->add_back('o')->add_back(' ')->add_back('W')->add_back('o')->add_back('r')->add_back('d')->size());
	/* END TEST TRIVIERE */
	security_singleton()->activeRaw(true);
	lexer_singleton()->onComplete(parser_singleton()->start)->start();
	(void)ac;
	(void)av;
	security_singleton()->activeRaw(false);
	return (0);
}
