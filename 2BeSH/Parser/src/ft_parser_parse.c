#include "ft_parser_private.h"
#include "common.h"
#include <unistd.h>
#include <stdlib.h>
#include <ft_stocker.h>

t_pars		*p_parser_parse(t_lex *lst)
{
	t_pars		*parseur;

	parseur = NULL;
	parseur = p_put_op(parseur , lst);
	return (parseur);
}
