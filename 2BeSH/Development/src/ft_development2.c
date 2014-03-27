/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_development2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 17:24:31 by thrivier          #+#    #+#             */
/*   Updated: 2014/03/27 17:24:39 by thrivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_private_developement.h"
#include <stdlib.h>

int					ft_next(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c == '_')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c >= '9')
		return (1);
	return (0);
}

int					ft_find_end_dollar(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_next(str[i]))
			i++;
		else
			break ;
	}
	return (i);
}

void				test(t_lex **begin, char *str, int y)
{
	char	*tmp2;

	tmp2 = NULL;
	if (y < (int)ft_strlen((*begin)->str))
	{
		tmp2 = ft_strjoin(str, (*begin)->str + y + 1);
		free((*begin)->str);
		(*begin)->str = ft_strdup(tmp2);
		free(tmp2);
	}
	else
	{
		free((*begin)->str);
		(*begin)->str = ft_strdup(str);
	}
}

void				test2(t_lex **begin, char *str, int y, int i)
{
	char	*tmp2;
	char	*tmp;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strndup((*begin)->str, i);
	tmp2 = ft_strjoin(tmp, str);
	free(tmp);
	tmp = ft_strdup((*begin)->str + y + i + 1);
	free((*begin)->str);
	(*begin)->str = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

int					test3(t_lex **begin, int i, int y)
{
	char	*tmp;
	char	*tmp2;

	if (i == 0)
	{
		i = ft_strlen((*begin)->str);
		if (i > (y + 2))
		{
			tmp = ft_strdup((*begin)->str + y + 1);
			free((*begin)->str);
			(*begin)->str = ft_strdup(tmp);
		}
		else
			return (0);
	}
	else
	{
		tmp = ft_strndup((*begin)->str, i);
		tmp2 = ft_strdup((*begin)->str + i + y + 1);
		free((*begin)->str);
		(*begin)->str = ft_strjoin(tmp, tmp2);
		free(tmp2);
	}
	free(tmp);
	return (1);
}
