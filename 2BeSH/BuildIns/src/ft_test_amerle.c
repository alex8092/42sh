#include "ft_buildins_private.h"
#include "ft_resolver.h"
#include <stdio.h>

void	p_buildins_test_amerle(char **arg)
{
	char	*test;

	(void)arg;
	test = resolver_singleton()->resolv_path("~/projects/42sh/2BeSH");
	printf("path : %s (%s)\n", test, "~/projects/42sh/2BeSH/");
	test = resolver_singleton()->resolv_path("./Regex/include/../../../../src/..");
	printf("path : %s (%s)\n", test, "./Regex/include/../src");
}
