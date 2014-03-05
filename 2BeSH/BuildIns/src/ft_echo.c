#include "ft_buildins_private.h"
#include "common.h"
#include "ft_display.h"

static t_bool	ft_echo_flag(char *str)
{
	int			i;

	if (!str)
		return (false);
	i = 1;
	if (str[0] == '-')
	{
		while (str[i] != '\0')
		{
			if (str[i] != 'n')
				return (false);
			i++;
		}
		if (i != 1)
			return (true);
	}
	return (false);
}

static void		ft_put_echo(char **tab, int i)
{
	while (tab[i])
	{
		display_singleton()->putstr(tab[i]);
		if (tab[i + 1])
			display_singleton()->putstr(" ");
		i++;
	}
}

void			p_buildins_echo(char **tab)
{
	int		flag;
	int		i;

	i = 1;
	flag = 0;
	while (ft_echo_flag(tab[i]))
	{
		flag = 1;
		i++;
	}
	if (tab[i] && !ft_strcmp(tab[i], "-"))
		i++;
	ft_put_echo(tab, i);
	if (!flag)
		display_singleton()->putstr("\n");
}
