#include "ft_prompt_private.h"

void	p_prompt_init_attributes(t_prompt *prompt)
{
	(void)prompt;
}

void	p_prompt_init_methodes(t_prompt *prompt)
{
	prompt->size = p_prompt_size;
	prompt->to_string = p_prompt_string;
}
