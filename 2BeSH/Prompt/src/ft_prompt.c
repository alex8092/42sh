#include "ft_prompt_private.h"
#include "common.h"
#include <stdlib.h>

static void		prompt_init(t_prompt *prompt)
{
	p_prompt_init_attributes(prompt);
	p_prompt_init_methodes(prompt);
}

t_prompt	*prompt_singleton(void)
{
	static t_prompt		*singleton = NULL;

	if (!singleton)
	{
		singleton = (t_prompt*)ft_memalloc(sizeof(t_prompt));
		prompt_init(singleton);
	}
	return (singleton);
}
