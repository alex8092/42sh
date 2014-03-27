# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/22 05:49:21 by amerle            #+#    #+#              #
#    Updated: 2014/03/22 05:49:21 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDEDIR) -fPIC

DEBUG = true
ifeq ($(DEBUG),true)
	CFLAGS += -ggdb3
else
	CFLAGS += -O3
endif

OS = $(shell uname -s)
ifeq ($(OS),Darwin)
	SHORTNAME = libftcommon.dylib
	LDFLAGS = -dynamiclib -install_name @rpath/$(SHORTNAME)
else
	SHORTNAME = libftcommon.so
	LDFLAGS = -shared
endif

OBJDIR = obj
SRCDIR = src
INCLUDEDIR = include/ft
LIBDIR = lib

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_findfirstof.c \
		ft_isinarray.c \
		ft_isprint.c \
		ft_memalloc.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strsplit.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tabstradd.c \
		ft_tabstrlen.c \
		ft_memdel.c \
		ft_strdel.c \
		ft_putstr_fd.c \
		ft_tabstrdel.c \
		ft_match.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c

OBJS_BASE = $(SRCS:.c=.o)

OBJS = $(addprefix $(OBJDIR)/, $(OBJS_BASE))

NAME = $(LIBDIR)/$(SHORTNAME)

RED = \033[0;31m
GREEN = \033[0;32m
NO = \033[0m

all: start print_error

print_begin:
	@rm -f .make_errors
	@echo "Compiling ..."

print_error:
	@if [ -e .make_errors ]; then cat .make_errors; fi
	@rm -f .make_errors

start: print_begin $(OBJS) print_error $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(LIBDIR)
	@$(CC) -o $@ $(OBJS) $(LDFLAGS)

install:
	@chmod +x install.sh
	@./install.sh $(NAME) $(INCLUDEDIR) $(LIBDIR)

uninstall:
	@chmod +x install.sh
	@./install.sh $(NAME) $(INCLUDEDIR) $(LIBDIR) uninstall

$(OBJDIR)/ft_atoi.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_bzero.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_findfirstof.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_isinarray.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_isprint.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_memalloc.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_memcpy.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strchr.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strcmp.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strdup.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strjoin.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strlen.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strncpy.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strndup.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strsplit.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strsub.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strtrim.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_tabstradd.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_tabstrlen.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_memdel.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_strdel.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_putstr_fd.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_tabstrdel.o: $(INCLUDEDIR)/common.h
$(OBJDIR)/ft_match.o: $(INCLUDEDIR)/common.h

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors\
	  && echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

clean:
	@echo "Clean objects ..."
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Clean library ..."
	@rm -rf $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re install uninstall
