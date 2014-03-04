#ifndef FT_PROMPT_H
# define FT_PROMPT_H

typedef struct s_prompt	t_prompt;

struct			s_prompt
{
	char	*(*to_string)(void);
	int		(*size)(void);
};

t_prompt	*prompt_singleton(void);

#endif
