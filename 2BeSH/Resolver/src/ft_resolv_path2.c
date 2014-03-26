/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_path2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:36:40 by amerle            #+#    #+#             */
/*   Updated: 2014/03/26 19:36:43 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_resolver.h"
#include "ft_environment.h"

char			*ft_resolv_path(char *str)
{
	return (ft_resolv_bis(str, env_singleton()->get("PWD"), true));
}

char			*ft_resolv_path_force(char *str, char *pwd, t_bool first)
{
	return (ft_resolv_bis(str, pwd, first));
}
