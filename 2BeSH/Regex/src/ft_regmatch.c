#include "ft_regex.h"

char	*ft_regmatch(char *str, char *regex, size_t *len_match)
{
	t_reg	reg;

	if (str && regex)
	{
		ft_bzero((void *)&reg, sizeof(t_reg));
		reg.s_base = str;
		reg.len_b = ft_strlen(str) + 1;
		reg.s_reg = regex;
		reg.len_r = ft_strlen(regex);
		ft_reg_parse(&reg);
		ft_reg_matcher(&reg);
		(*len_match) = (reg.match) ? (reg.s_base + reg.pos) - reg.p_match : 0;
		return ((reg.match) ? reg.p_match : 0);
	}
	return (0);
}
