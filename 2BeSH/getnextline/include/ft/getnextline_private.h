/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:12 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:43:12 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETNEXTLINE_PRIVATE_H
# define FT_GETNEXTLINE_PRIVATE_H

# include "getnextline.h"
# include <ft/astr.h>
# include <unistd.h>

# define BUFF_SIZE 1024

typedef struct s_fd		t_fd;
typedef struct s_nexl	t_nexl;

struct		s_fd
{
	int		fd;
	char	*save;
	t_fd	*next;
	t_astr	*tab;
};

struct		s_nexl
{
	t_fd	*begin;
	char	*save;
	char	*buff;
	ssize_t	ret;
};

#endif
