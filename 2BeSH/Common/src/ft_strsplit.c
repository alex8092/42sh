#include "common.h"

char	**ft_strsplit(char *str, char separator, t_bool escape)
{
	char	**tab;
	size_t	index;
	char	*tmp;

	tmp = str;
	index = 0;
	tab = NULL;
	while (str[index])
	{
		if (str[index] == separator
			&& ((escape && index > 0 && str[index - 1] != '\\') || !escape))
		{
			tab = ft_tabstradd(tab, ft_strndup(str, index));
			str += index + 1;
			index = -1;
		}
		++index;
	}
	tab = (index != 0) ? ft_tabstradd(tab, ft_strndup(str, index)) : tab;
	tab = ft_tabstradd(tab, NULL);
	return (tab);
}

