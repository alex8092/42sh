# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <amerle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/17 18:45:29 by amerle            #+#    #+#              #
#    Updated: 2014/02/17 20:17:58 by thrivier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = true
ifeq ($(DEBUG),true)
	CFLAGS += -ggdb3
else
	CFLAGS += -O2
endif
LDFLAGS =
INCLUDEDIRCOMMON = Common/include
INCLUDEDIREVENT = Event/include
INCLUDEDIREXECUTOR = Executor/include
INCLUDEDIRLEXER = Lexer/include
INCLUDEDIRPARSER = Parser/include
INCLUDEDIRRESOLVER = Resolver/include
INCLUDEDIRVALIDATOR = Validator/include
INCLUDEDIRSECURITY = Security/include
INCLUDEDIR = include
SRCDIRCOMMON = Common/src
SRCDIREVENT = Event/src
SRCDIREXECUTOR = Executor/src
SRCDIRLEXER = Lexer/src
SRCDIRPARSER = Parser/src
SRCDIRRESOLVER = Resolver/src
SRCDIRVALIDATOR = Validator/src
SRCDIRSECURITY = Security/src
SRCDIR = src
OBJDIRCOMMON = Common/obj
OBJDIREVENT = Event/obj
OBJDIREXECUTOR = Executor/obj
OBJDIRLEXER = Lexer/obj
OBJDIRPARSER = Parser/obj
OBJDIRRESOLVER = Resolver/obj
OBJDIRVALIDATOR = Validator/obj
OBJDIRSECURITY = Security/obj
OBJDIR = obj

CFLAGS += -I$(INCLUDEDIRCOMMON) -I$(INCLUDEDIREVENT) -I$(INCLUDEDIREXECUTOR)
CFLAGS += -I$(INCLUDEDIRLEXER) -I$(INCLUDEDIRPARSER) -I$(INCLUDEDIRRESOLVER)
CFLAGS += -I$(INCLUDEDIRVALIDATOR) -I$(INCLUDEDIRSECURITY) -I$(INCLUDEDIR)

SRCSCOMMON = ft_isprint.c

SRCSEVENT = ft_event.c

SRCSEXECUTOR =

SRCSLEXER = ft_lexer.c

SRCSPARSER = 

SRCSRESOLVER = 

SRCSVALIDATOR =

SRCSSECURITY = ft_security.c

SRCS = main.c

OBJSBASECOMMON = $(SRCSCOMMON:.c=.o)
OBJSBASEEVENT = $(SRCSEVENT:.c=.o)
OBJSBASEEXECUTOR = $(SRCSEXECUTOR:.c=.o)
OBJSBASELEXER = $(SRCSLEXER:.c=.o)
OBJSBASEPARSER = $(SRCSPARSER:.c=.o)
OBJSBASERESOLVER = $(SRCSRESOLVER:.c=.o)
OBJSBASEVALIDATOR = $(SRCSVALIDATOR:.c=.o)
OBJSBASESECURITY = $(SRCSSECURITY:.c=.o)
OBJSBASE = $(SRCS:.c=.o)

OBJS_COMMON = $(addprefix $(OBJDIRCOMMON)/, $(OBJSBASECOMMON))
OBJS_EVENT = $(addprefix $(OBJDIREVENT)/, $(OBJSBASEEVENT))
OBJS_EXECUTOR = $(addprefix $(OBJDIREXECUTOR)/, $(OBJSBASEEXECUTOR))
OBJS_LEXER = $(addprefix $(OBJDIRLEXER)/, $(OBJSBASELEXER))
OBJS_PARSER = $(addprefix $(OBJDIRPARSER)/, $(OBJSBASEPARSER))
OBJS_RESOLVER = $(addprefix $(OBJDIRRESOLVER)/, $(OBJSBASERESOLVER))
OBJS_VALIDATOR = $(addprefix $(OBJDIRVALIDATOR)/, $(OBJSBASEVALIDATOR))
OBJS_SECURITY = $(addprefix $(OBJDIRSECURITY)/, $(OBJSBASESECURITY))
OBJS = $(addprefix $(OBJDIR)/, $(OBJSBASE))

NAME = 42sh

all: $(NAME)

$(NAME): $(OBJS_COMMON) $(OBJS_EVENT) $(OBJS_EXECUTOR) $(OBJS_LEXER) \
	$(OBJS_PARSER) $(OBJS_RESOLVER) $(OBJS_VALIDATOR) $(OBJS_SECURITY) $(OBJS)
	$(CC) -o $(NAME) $^ $(LDFLAGS)

$(OBJDIRCOMMON)/%.o: $(SRCDIRCOMMON)/%.c
	mkdir -p $(OBJDIRCOMMON)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRCOMMON)/ft_isprint.o: $(INCLUDEDIRCOMMON)/common.h

$(OBJDIREVENT)/%.o: $(SRCDIREVENT)/%.c
	mkdir -p $(OBJDIREVENT)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIREXECUTOR)/%.o: $(SRCDIREXECUTOR)/%.c
	mkdir -p $(OBJDIREXECUTOR)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRLEXER)/ft_lexer.o: $(INCLUDEDIRLEXER)/ft_lexer.h

$(OBJDIRLEXER)/%.o: $(SRCDIRLEXER)/%.c
	mkdir -p $(OBJDIRLEXER)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRPARSER)/%.o: $(SRCDIRPARSER)/%.c
	mkdir -p $(OBJDIRPARSER)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRRESOLVER)/%.o: $(SRCDIRRESOLVER)/%.c
	mkdir -p $(OBJDIRRESOLVER)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRVALIDATOR)/%.o: $(SRCDIRVALIDATOR)/%.c
	mkdir -p $(OBJDIRVALIDATOR)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRSECURITY)/%.o: $(SRCDIRSECURITY)/%.c
	mkdir -p $(OBJDIRSECURITY)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS_COMMON) $(OBJS_EVENT) $(OBJS_EXECUTOR) $(OBJS_LEXER)
	rm -f $(OBJS_PARSER) $(OBJS_RESOLVER) $(OBJS_VALIDATOR) $(OBJS)
	rm -f $(OBJS_SECURITY)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
