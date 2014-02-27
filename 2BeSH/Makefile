CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = true
ifeq ($(DEBUG),true)
	CFLAGS += -ggdb3
else
	CFLAGS += -O2
endif
LDFLAGS = -ltermcap
INCLUDEDIRCOMMON = Common/include
INCLUDEDIREVENT = Event/include
INCLUDEDIREXECUTOR = Executor/include
INCLUDEDIRLEXER = Lexer/include
INCLUDEDIRPARSER = Parser/include
INCLUDEDIRRESOLVER = Resolver/include
INCLUDEDIRVALIDATOR = Validator/include
INCLUDEDIRSECURITY = Security/include
INCLUDEDIRDISPLAY = Display/include
INCLUDEDIRSTOCKER = Stocker/include
INCLUDEDIRENV = Environment/include
INCLUDEDIR = include
SRCDIRCOMMON = Common/src
SRCDIREVENT = Event/src
SRCDIREXECUTOR = Executor/src
SRCDIRLEXER = Lexer/src
SRCDIRPARSER = Parser/src
SRCDIRRESOLVER = Resolver/src
SRCDIRVALIDATOR = Validator/src
SRCDIRSECURITY = Security/src
SRCDIRDISPLAY = Display/src
SRCDIRSTOCKER = Stocker/src
SRCDIRENV = Environment/src
SRCDIR = src
OBJDIRCOMMON = Common/obj
OBJDIREVENT = Event/obj
OBJDIREXECUTOR = Executor/obj
OBJDIRLEXER = Lexer/obj
OBJDIRPARSER = Parser/obj
OBJDIRRESOLVER = Resolver/obj
OBJDIRVALIDATOR = Validator/obj
OBJDIRSECURITY = Security/obj
OBJDIRDISPLAY = Display/obj
OBJDIRSTOCKER = Stocker/obj
OBJDIRENV = Environment/obj
OBJDIR = obj

CFLAGS += -I$(INCLUDEDIRCOMMON) -I$(INCLUDEDIREVENT) -I$(INCLUDEDIREXECUTOR)
CFLAGS += -I$(INCLUDEDIRLEXER) -I$(INCLUDEDIRPARSER) -I$(INCLUDEDIRRESOLVER)
CFLAGS += -I$(INCLUDEDIRVALIDATOR) -I$(INCLUDEDIRSECURITY) -I$(INCLUDEDIR)
CFLAGS += -I$(INCLUDEDIRDISPLAY) -I$(INCLUDEDIRSTOCKER) -I$(INCLUDEDIRENV)

SRCSCOMMON = ft_isprint.c \
			 ft_isinarray.c \
			 ft_isprint.c \
			 ft_findfirstof.c \
			 ft_tabstrlen.c \
			 ft_bzero.c \
			 ft_memalloc.c

SRCSEVENT = ft_event.c

SRCSEXECUTOR =

SRCSLEXER = ft_lexer.c

SRCSPARSER = ft_parser.c \
			 ft_parser_parse.c

SRCSRESOLVER = 

SRCSVALIDATOR =

SRCSSECURITY = ft_security.c

SRCSDISPLAY = ft_display.c

SRCSSTOCKER = ft_stocker.c \
			  ft_list_stocker.c

SRCSENV = ft_environment.c

SRCS = main.c

OBJSBASECOMMON = $(SRCSCOMMON:.c=.o)
OBJSBASEEVENT = $(SRCSEVENT:.c=.o)
OBJSBASEEXECUTOR = $(SRCSEXECUTOR:.c=.o)
OBJSBASELEXER = $(SRCSLEXER:.c=.o)
OBJSBASEPARSER = $(SRCSPARSER:.c=.o)
OBJSBASERESOLVER = $(SRCSRESOLVER:.c=.o)
OBJSBASEVALIDATOR = $(SRCSVALIDATOR:.c=.o)
OBJSBASESECURITY = $(SRCSSECURITY:.c=.o)
OBJSBASEDISPLAY = $(SRCSDISPLAY:.c=.o)
OBJSBASESTOCKER = $(SRCSSTOCKER:.c=.o)
OBJSBASEENV = $(SRCSENV:.c=.o)
OBJSBASE = $(SRCS:.c=.o)

OBJS_COMMON = $(addprefix $(OBJDIRCOMMON)/, $(OBJSBASECOMMON))
OBJS_EVENT = $(addprefix $(OBJDIREVENT)/, $(OBJSBASEEVENT))
OBJS_EXECUTOR = $(addprefix $(OBJDIREXECUTOR)/, $(OBJSBASEEXECUTOR))
OBJS_LEXER = $(addprefix $(OBJDIRLEXER)/, $(OBJSBASELEXER))
OBJS_PARSER = $(addprefix $(OBJDIRPARSER)/, $(OBJSBASEPARSER))
OBJS_RESOLVER = $(addprefix $(OBJDIRRESOLVER)/, $(OBJSBASERESOLVER))
OBJS_VALIDATOR = $(addprefix $(OBJDIRVALIDATOR)/, $(OBJSBASEVALIDATOR))
OBJS_SECURITY = $(addprefix $(OBJDIRSECURITY)/, $(OBJSBASESECURITY))
OBJS_DISPLAY = $(addprefix $(OBJDIRDISPLAY)/, $(OBJSBASEDISPLAY))
OBJS_STOCKER = $(addprefix $(OBJDIRSTOCKER)/, $(OBJSBASESTOCKER))
OBJS_ENV = $(addprefix $(OBJDIRENV)/, $(OBJSBASEENV))
OBJS = $(addprefix $(OBJDIR)/, $(OBJSBASE))

NAME = 42sh

all: $(NAME)

$(NAME): $(OBJS_COMMON) $(OBJS_EVENT) $(OBJS_EXECUTOR) $(OBJS_LEXER) \
	$(OBJS_PARSER) $(OBJS_RESOLVER) $(OBJS_VALIDATOR) $(OBJS_SECURITY) \
	$(OBJS) $(OBJS_DISPLAY) $(OBJS_STOCKER) $(OBJS_ENV)
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

$(OBJDIRPARSER)/ft_parser.o: $(INCLUDEDIRPARSER)/ft_parser.h

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

$(OBJDIRDISPLAY)/ft_display.o: $(INCLUDEDIRDISPLAY)/ft_display.h

$(OBJDIRDISPLAY)/%.o: $(SRCDIRDISPLAY)/%.c
	mkdir -p $(OBJDIRDISPLAY)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRSTOCKER)/ft_stocker.o: $(INCLUDEDIRSTOCKER)/ft_stocker.h

$(OBJDIRSTOCKER)/%.o: $(SRCDIRSTOCKER)/%.c
	mkdir -p $(OBJDIRSTOCKER)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRENV)/ft_environment.o: $(INCLUDEDIRENV)/ft_environment.h

$(OBJDIRENV)/%.o: $(SRCDIRENV)/%.c
	mkdir -p $(OBJDIRENV)
	$(CC) -o $@ -c $< $(CFLAGS)


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS_COMMON) $(OBJS_EVENT) $(OBJS_EXECUTOR) $(OBJS_LEXER)
	rm -f $(OBJS_PARSER) $(OBJS_RESOLVER) $(OBJS_VALIDATOR) $(OBJS)
	rm -f $(OBJS_SECURITY) $(OBJS_DISPLAY) $(OBJS_STOCKER) $(OBJS_ENV)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

