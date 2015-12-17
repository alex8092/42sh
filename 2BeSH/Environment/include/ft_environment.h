/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:43:11 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 06:32:12 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVIRONMENT_H
# define FT_ENVIRONMENT_H

# include <unistd.h>
# include <ft/common.h>

typedef struct s_env	t_env;

struct		s_env
{
	char	**m_env;
	char	*m_execdir;
	char	*(*get)(char *name);
	t_env	*(*set)(char *name, char *value);
	t_env	*(*unset)(char *name, size_t size);
	size_t	(*size)(void);
};

t_env		*env_singleton(void);
t_env		*env_unset(char *name, size_t size);
void		p_env_retrieve_path(void);
void		p_env_retrieve(void);

#endif
