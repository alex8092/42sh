#include "ft_regex.h"
#include <stdlib.h>

static t_bool	ft_reg_isinbetween(char c, char beg, char end)
{
	return (c >= beg && c <= end);
}

static t_bool	ft_reg_cmp(char c, char *group)
{
	char	*groups[] =
	{
		":alnum:", ":alpha:", ":blank:", ":cntrl:", ":digit:",
		":graph:", ":lower:", ":print:", ":punct:"
	};
	char	*groups_str[] =
	{
		"A-Za-z0-9", "A-Za-z", " \t", "\x00-\x1F\x7F", "0-9", "\x21-\x7E",
		"a-z", "\x20-\x7E", "][!\"#$%&'()*+,./:;<=>?@\\^_`{|}~-"
	};
	size_t	i;

	i = 0;
	while (i < sizeof(groups))
	{
		if (!ft_strcmp(group, groups[i]))
			return (ft_reg_isinarray(c, groups_str[i]));
		++i;
	}
	return (false);
}

static t_bool	ft_reg_isinarray_extended(char c, char *array, size_t *i)
{
	t_bool	res;
	char	*end;
	char	*group;

	res = false;
	end = ft_strchr(array, ']');
	if (end)
	{
		group = ft_strsub(array, 1, end - array - 1);
		res = ft_reg_cmp(c, group);
		free(group);
		i += (end - array);
	}
	return (res);
}

t_bool			ft_reg_isinarray(char c, char *array)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(array);
	while (i < len)
	{
		if (array[i] == '[' && array[i + 1] == ':')
		{
			if (ft_reg_isinarray_extended(c, array + i, &i))
			{
				return (true);
			}
		}
		else if (array[i] && array[i + 1] == '-' && array[i + 2])
		{
			if (ft_reg_isinbetween(c, array[i], array[i + 2]))
				return (true);
			i += 2;
		}
		else if (array[i] == c)
			return (true);
		++i;
	}
	return (false);
}
