#include "ft_lexer.h"
#include "ft_parser.h"
#include "ft_security.h"
#include "ft_stocker.h"
#include "ft_environment.h"
#include "ft_buildins.h"
#include "ft_display.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	/* TEST TRIVIERE START 
	printf("--------- TEST TRIVIERE START ---------\n");
		t_stocker	*stocker;

		stocker = stocker_singleton();

		printf("# TEST RM STOCKER EMPTY FRONT #\n\n");
		stocker->rm_front()->rm_front()->rm_front();
		printf("-> Stocker [%d] : %s\n\n", stocker->size(), stocker->to_string());

		printf("# TEST RM STOCKER EMPTY BACK #\n");
		stocker->rm_back()->rm_back()->rm_back();
		printf("-> Stocker [%d] : %s\n\n", stocker->size(), stocker->to_string());

		printf("# TEST ADD STOCKER BACK #\n");
		stocker->push_back('W')->push_back('o')->push_back('r')->push_back('d');
		printf("-> Stocker [%d] : %s\n\n", stocker->size(), stocker->to_string());

		printf("# TEST ADD STOCKER FRONT #\n");
		stocker->push_front(' ')->push_front('o')->push_front('l')->push_front('l')->push_front('e')->push_front('H');
		printf("-> Stocker [%d] : %s\n\n", stocker->size(), stocker->to_string());

		printf("# TEST MULTIPLE [3] RM STOCKER FRONT #\n");
		stocker->push_front(' ')->push_front('>')->push_front('-');
		printf("-> Stocker [%d] : %s\n", stocker->size(), stocker->to_string());
		stocker->rm_front()->rm_front()->rm_front();
		printf("-> Stocker [%d] : %s\n\n", stocker->size(), stocker->to_string());

		printf("# TEST MULTIPLE [3] RM STOCKER BACK #\n");
		stocker->push_back(' ')->push_back('<')->push_back('-');
		printf("-> Stocker [%d] : %s\n", stocker->size(), stocker->to_string());
		stocker->rm_back()->rm_back()->rm_back();
		printf("-> Stocker [%d] : %s\n\n", stocker->size(), stocker->to_string());

	printf("--------- TEST TRIVIERE END ---------\n\n");
	// TEST TRIVIERE END */
	
	printf("PATH : %s\n", env_singleton()->get("PATH"));
	printf("\"cd\" buildins ? : %d\n", buildins_singleton()->is_buildin("cd"));
	printf("\"echo\" buildins ? : %d\n", buildins_singleton()->is_buildin("echo"));
	printf("\"exit\" buildins ? : %d\n", buildins_singleton()->is_buildin("exit"));
	printf("\"tamere\" buildins ? : %d\n", buildins_singleton()->is_buildin("tamere"));
	display_singleton()->set_out(2)->writec('O')->writec('K')->writec('\n')->set_out(1);
	security_singleton()->activeRaw(true);
	lexer_singleton()->onComplete(parser_singleton()->start)->start();
	/*
	 * THRIVIER
	 * */

	/*
	 *END
	 * */
	(void)ac;
	(void)av;
	security_singleton()->activeRaw(false);
	return (0);
}
