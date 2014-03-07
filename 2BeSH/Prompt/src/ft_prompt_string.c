#include "ft_prompt.h"
#include "common.h"

char	*p_prompt_string(void)
{
	return (prompt_singleton()->m_prompt);
}
