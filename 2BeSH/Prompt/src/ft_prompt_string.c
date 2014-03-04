#include "ft_prompt.h"
#include "common.h"

char	*p_prompt_string(void)
{
	char	*prompt;

	prompt = ft_strdup("[#] : ");
	return (prompt);
}
