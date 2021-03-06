/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagger.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:12 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:12 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGGER_H
# define FT_FLAGGER_H

# include <ft/common.h>
# include <ft/astr.h>

typedef struct s_flagger	t_flagger;
typedef struct s_flag		t_flag;

struct		s_flagger
{
	t_flag	*m_begin;
	t_flag	*m_end;
	t_bool	m_error;
	t_bool	m_stop_single_tiret;
	char	*prog_name;
	t_bool	(*parse)(t_flagger *, char ***);
	t_bool	(*is_active)(t_flagger *, char *flag);
	t_astr	*(*get_args)(t_flagger *, char *flag);
	void	(*print_help)(t_flagger *);
	void	(*free)(t_flagger **);
};

t_flagger	*ft_flagger_create(char *conffile, char *prog_name);

#endif
