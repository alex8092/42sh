/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_development.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:11 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:11 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEVELOPMENT_H
# define FT_DEVELOPMENT_H

# include "ft_lexer.h"
# include <ft/common.h>

typedef struct s_development	t_development;
typedef struct dirent			t_file;
typedef struct s_dir			t_dir;

struct			s_dir
{
	char		*name;
	t_bool		delname;
	t_dir		*next;
};

struct			s_development
{
	t_lex		*(*start)(t_lex *base);
};

t_development	*dev_singleton();

#endif
