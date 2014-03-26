/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagger_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:57 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:42:57 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flagger_private.h"

#define HACK_NORME_STR(X, Y) char	X[] = Y

t_bool	ft_flagger_usage_single(t_flagger *flag, char c)
{
	HACK_NORME_STR(str, "usage: invalid flag [");
	write(2, str, sizeof(str) - 1);
	write(2, &c, 1);
	write(2, "]\n", 2);
	flag->m_error = true;
	return (false);
}

t_bool	ft_flagger_usage_mult(t_flagger *flag, char *str)
{
	HACK_NORME_STR(strb, "usage: invalid flag[");
	write(2, strb, sizeof(strb) - 1);
	write(2, str, ft_strlen(str));
	write(2, "]\n", 2);
	flag->m_error = true;
	return (false);
}

t_bool	ft_flagger_usage_few_args(t_flagger *flag, char c)
{
	HACK_NORME_STR(str, "usage: to few arguments to flag [");
	write(2, str, sizeof(str) - 1);
	write(2, &c, 1);
	write(2, "]\n", 2);
	flag->m_error = true;
	return (false);
}

t_bool	ft_flagger_usage_few_args_str(t_flagger *flag, char *str)
{
	HACK_NORME_STR(strb, "usage: to few arguments to flag[");
	write(2, strb, sizeof(strb) - 1);
	write(2, str, ft_strlen(str));
	write(2, "]\n", 2);
	flag->m_error = true;
	return (false);
}
