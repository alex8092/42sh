#include "ft_prompt.h"
#include "common.h"
#include "ft_regex.h"
#include "ft_environment.h"

char	*p_prompt_string(void)
{
	static t_regex	*reg = NULL;
	static t_regex	*reg2 = NULL;
	char			*str;

	if (!reg)
		reg = ft_regex("\\\\u");
	if (!reg2)
		reg2 = ft_regex("\\\\w");
	/*reg3 = ft_regex(env_singleton()->get("HOME"));*/
	str = prompt_singleton()->m_prompt;
	str = ft_regmatch_replace(str, reg, env_singleton()->get("USER"));
	/*str = ft_regmatch_replace(str, reg2, env_singleton()->get("PWD"));
	str = ft_regmatch_replace_all(str, reg3, "~");*/
	prompt_singleton()->m_size = ft_strlen(str);
	return (str);
}
