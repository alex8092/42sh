#include "ft_prompt_private.h"
#include "common.h"

void	p_prompt_init_attributes(t_prompt *prompt)
{
	prompt->m_prompt = ft_strdup(".: 2BeShell :. ~> ");
	prompt->m_size = ft_strlen(prompt->m_prompt);
}

void	p_prompt_init_methodes(t_prompt *prompt)
{
	prompt->size = p_prompt_size;
	prompt->to_string = p_prompt_string;
}
