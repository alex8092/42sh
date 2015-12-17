# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: triviere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/27 17:34:39 by triviere          #+#    #+#              #
#    Updated: 2015/12/17 15:33:27 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

all: $(NAME)

$(NAME):
	make -C 2BeSH
	mv 2BeSH/$(NAME) .

re:
	make re -C 2BeSH

clean:
	make clean -C 2BeSH

fclean:
	make fclean -C 2BeSH
	rm -f $(NAME)

.PHONY: clean fclean all re $(NAME)
