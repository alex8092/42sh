# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: triviere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/27 17:34:39 by triviere          #+#    #+#              #
#    Updated: 2014/03/27 17:34:43 by triviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = useless

all: $(NAME)

$(NAME):
	make -C 2BeSH

re:
	make re -C 2BeSH

clean:
	make clean -C 2BeSH

fclean:
	make fclean -C 2BeSH

.PHONY: clean fclean all re
