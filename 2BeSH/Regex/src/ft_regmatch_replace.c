/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regmatch_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <amerle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 23:15:28 by amerle            #+#    #+#             */
/*   Updated: 2014/03/01 23:27:41 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_regex.h"
#include <stdlib.h>

static char	*ft_regmatch_replace_new(char *s, char *m, char *rep, size_t len)
{
	size_t	len_rep;
	size_t	len_s;
	char	*new;
	char	*tmp;

	len_rep = ft_strlen(rep);
	len_s = ft_strlen(s);
	new = (char *)ft_memalloc((m - s) + len_rep + len_s - (m - s) + len + 1);
	tmp = new;
	ft_memcpy(tmp, s, m - s);
	tmp += (m - s);
	ft_memcpy(tmp, rep, len_rep);
	tmp += len_rep;
	ft_memcpy(tmp, m + len, len_s - (m - s) + len);
	new[(m - s) + len_rep + len_s - (m - s) + len] = 0;
	return (new);
}

char		*ft_regmatch_replace(char *str, char *pattern, char *repl)
{
	size_t	len;
	char	*match;
	char	*new;
	char	*tmp;

	new = NULL;
	match = ft_regmatch(str, pattern, &len);
	if (match)
	{
		tmp = ft_regmatch_replace_new(str, match, repl, len);
		new = tmp;
	}
	return (new);
}

char		*ft_regmatch_replace_all(char *str, char *pattern, char *repl)
{
	size_t	len;
	char	*match;
	char	*new;
	char	*tmp;

	str = ft_strdup(str);
	new = str;
	while ((match = ft_regmatch(str, pattern, &len)))
	{
		tmp = ft_regmatch_replace_new(new, match, repl, len);
		if (new)
			free(new);
		str = tmp + (match - new) + ft_strlen(repl);
		new = tmp;
	}
	return (new);
}