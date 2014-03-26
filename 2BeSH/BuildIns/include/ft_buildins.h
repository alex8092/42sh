/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:37:25 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:46:25 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILDINS_H
# define FT_BUILDINS_H

# include <ft/common.h>

typedef struct s_buildins	t_buildins;
typedef struct s_buildin	t_buildin;

struct			s_buildins
{
	t_buildin	*m_begin;
	t_bool		(*is_buildin)(char *);
	int			(*exec)(char *, char **);
};

t_buildins		*buildins_singleton(void);

#endif
