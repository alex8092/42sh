#ifndef FT_LEXER_PRIVATE_H
# define FT_LEXER_PRIVATE_H

# include "ft_lexer.h"

struct					s_lex_reg
{
	char				*pattern;
	t_lex_op			op;
	t_lex_reg			*next;
};

t_lex	*ft_lexer_lex_str(char *str);
void	p_lexer_template_init(t_lexer *lexer);

#endif
