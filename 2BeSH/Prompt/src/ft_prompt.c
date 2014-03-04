#include "ft_prompt_private.h"
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
		singleton = (t_prompt*)malloc(sizeof(t_prompt));
		if (!singleton)
			exit(1);
		prompt_init(singleton);
	}
	return (singleton);
}
