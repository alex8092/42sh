/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 05:42:58 by amerle            #+#    #+#             */
/*   Updated: 2014/03/22 05:42:58 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("Makefile", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		free(line);
	close(fd);
	return (0);
}
