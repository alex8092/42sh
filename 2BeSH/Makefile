CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c89
DEBUG = true
ifeq ($(DEBUG),true)
	CFLAGS += -ggdb3
else
	CFLAGS += -O2
endif
LDFLAGS = -ltermcap -std=c89
INCLUDEDIRCOMMON = Common/include
INCLUDEDIROPERATION = Operation/include
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
INCLUDEDIRBUILDINS = BuildIns/include
INCLUDEDIRHISTORY = History/include
INCLUDEDIRREGEX = Regex/include
INCLUDEDIRDEBUG = Debugger/include
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
SRCDIRBUILDINS = BuildIns/src
SRCDIROPERATION = Operation/src
SRCDIRHISTORY = History/src
SRCDIRREGEX = Regex/src
SRCDIRDEBUG = Debugger/src
SRCDIR = src

OBJDIRCOMMON = Common/obj
OBJDIROPERATION = Operation/obj
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
OBJDIRBUILDINS = BuildIns/obj
OBJDIRHISTORY = History/obj
OBJDIRREGEX = Regex/obj
OBJDIRDEBUG = Debugger/obj
OBJDIR = obj

CFLAGS += -I$(INCLUDEDIRCOMMON) -I$(INCLUDEDIREVENT) -I$(INCLUDEDIREXECUTOR)
CFLAGS += -I$(INCLUDEDIRLEXER) -I$(INCLUDEDIRPARSER) -I$(INCLUDEDIRRESOLVER)
CFLAGS += -I$(INCLUDEDIRVALIDATOR) -I$(INCLUDEDIRSECURITY) -I$(INCLUDEDIR)
CFLAGS += -I$(INCLUDEDIRDISPLAY) -I$(INCLUDEDIRSTOCKER) -I$(INCLUDEDIRHISTORY)
CFLAGS += -I$(INCLUDEDIRBUILDINS) -I$(INCLUDEDIROPERATION) -I$(INCLUDEDIRENV)
CFLAGS += -I$(INCLUDEDIRREGEX) -I$(INCLUDEDIRDEBUG)

SRCSCOMMON = ft_isprint.c \
			 ft_isinarray.c \
			 ft_isprint.c \
			 ft_findfirstof.c \
			 ft_strndup.c \
			 ft_tabstrlen.c \
			 ft_bzero.c \
			 ft_memalloc.c \
			 ft_strncmp.c \
			 ft_strlen.c \
			 ft_strcmp.c \
			 ft_strdup.c \
			 ft_tabstradd.c \
			 ft_memcpy.c \
			 ft_strsplit.c \
			 ft_strjoin.c \
			 ft_strchr.c \
			 ft_strsub.c \
			 ft_strncpy.c \
			 ft_atoi.c \
			 ft_strtrim.c

SRCSEVENT = ft_event.c \
			ft_event_item.c

SRCSEXECUTOR = ft_executor.c

SRCSOPERATION = ft_operation.c

SRCSLEXER = ft_lexer.c

SRCSPARSER = ft_parser.c \
			 ft_parser_parse.c

SRCSRESOLVER = ft_resolver.c

SRCSVALIDATOR = ft_validator.c

SRCSSECURITY = ft_security.c

SRCSDISPLAY = ft_display.c

SRCSSTOCKER = ft_stocker.c \
			  ft_stocker_lst.c \
			  ft_stocker_push_lst.c \
			  ft_stocker_other.c \
			  ft_stocker_init.c \
			  ft_stocker_remove_lst.c \
			  ft_stocker_mv_current.c

SRCSENV = ft_environment.c

SRCSBUILDINS = ft_buildins.c \
			   ft_cd.c \
			   ft_buildins_util.c \
			   ft_echo.c \
			   ft_env.c \
			   ft_exit.c \
			   ft_setenv.c \
			   ft_unsetenv.c

SRCSHISTORY = ft_history.c \
			  ft_history_init.c \
			  ft_history_other.c \
			  ft_history_push.c

SRCSREGEX = ft_reg_create.c \
			ft_reg_isinarray.c \
			ft_reg_match_begend.c \
			ft_reg_match_pipe.c \
			ft_reg_match_rep.c \
			ft_reg_match_sub.c \
			ft_reg_matcher.c \
			ft_regmatch.c \
			ft_regmatch_parser.c \
			ft_regmatch_replace.c \
			ft_regmatch_sub.c \
			ft_match_any.c

SRCSDEBUG = ft_debug.c

SRCS = main.c

OBJSBASECOMMON = $(SRCSCOMMON:.c=.o)
OBJSBASEEVENT = $(SRCSEVENT:.c=.o)
OBJSBASEEXECUTOR = $(SRCSEXECUTOR:.c=.o)
OBJSBASELEXER = $(SRCSLEXER:.c=.o)
OBJSBASEOPERATION = $(SRCSOPERATION:.c=.o)
OBJSBASEPARSER = $(SRCSPARSER:.c=.o)
OBJSBASERESOLVER = $(SRCSRESOLVER:.c=.o)
OBJSBASEVALIDATOR = $(SRCSVALIDATOR:.c=.o)
OBJSBASESECURITY = $(SRCSSECURITY:.c=.o)
OBJSBASEDISPLAY = $(SRCSDISPLAY:.c=.o)
OBJSBASESTOCKER = $(SRCSSTOCKER:.c=.o)
OBJSBASEENV = $(SRCSENV:.c=.o)
OBJSBASEBUILDINS = $(SRCSBUILDINS:.c=.o)
OBJSBASEHISTORY = $(SRCSHISTORY:.c=.o)
OBJSBASEREGEX = $(SRCSREGEX:.c=.o)
OBJSBASEDEBUG = $(SRCSDEBUG:.c=.o)
OBJSBASE = $(SRCS:.c=.o)

OBJS_COMMON = $(addprefix $(OBJDIRCOMMON)/, $(OBJSBASECOMMON))
OBJS_EVENT = $(addprefix $(OBJDIREVENT)/, $(OBJSBASEEVENT))
OBJS_EXECUTOR = $(addprefix $(OBJDIREXECUTOR)/, $(OBJSBASEEXECUTOR))
OBJS_LEXER = $(addprefix $(OBJDIRLEXER)/, $(OBJSBASELEXER))
OBJS_OPERATION = $(addprefix $(OBJDIROPERATION)/, $(OBJSBASEOPERATION))
OBJS_PARSER = $(addprefix $(OBJDIRPARSER)/, $(OBJSBASEPARSER))
OBJS_RESOLVER = $(addprefix $(OBJDIRRESOLVER)/, $(OBJSBASERESOLVER))
OBJS_VALIDATOR = $(addprefix $(OBJDIRVALIDATOR)/, $(OBJSBASEVALIDATOR))
OBJS_SECURITY = $(addprefix $(OBJDIRSECURITY)/, $(OBJSBASESECURITY))
OBJS_DISPLAY = $(addprefix $(OBJDIRDISPLAY)/, $(OBJSBASEDISPLAY))
OBJS_STOCKER = $(addprefix $(OBJDIRSTOCKER)/, $(OBJSBASESTOCKER))
OBJS_ENV = $(addprefix $(OBJDIRENV)/, $(OBJSBASEENV))
OBJS_BUILDINS = $(addprefix $(OBJDIRBUILDINS)/, $(OBJSBASEBUILDINS))
OBJS_HISTORY = $(addprefix $(OBJDIRHISTORY)/, $(OBJSBASEHISTORY))
OBJS_REGEX = $(addprefix $(OBJDIRREGEX)/, $(OBJSBASEREGEX))
OBJS_DEBUG = $(addprefix $(OBJDIRDEBUG)/, $(OBJSBASEDEBUG))
OBJS = $(addprefix $(OBJDIR)/, $(OBJSBASE))

NAME = 42sh

all: $(NAME)

$(NAME): $(OBJS_COMMON) $(OBJS_EVENT) $(OBJS_EXECUTOR) $(OBJS_LEXER) \
	$(OBJS_PARSER) $(OBJS_RESOLVER) $(OBJS_VALIDATOR) $(OBJS_SECURITY) \
	$(OBJS) $(OBJS_DISPLAY) $(OBJS_STOCKER) $(OBJS_ENV) $(OBJS_BUILDINS) \
	$(OBJS_OPERATION) $(OBJS_HISTORY) $(OBJS_REGEX) $(OBJS_DEBUG)
	$(CC) -o $(NAME) $^ $(LDFLAGS)

$(OBJDIRCOMMON)/%.o: $(SRCDIRCOMMON)/%.c
	mkdir -p $(OBJDIRCOMMON)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRCOMMON)/%.o: $(INCLUDEDIRCOMMON)/common.h

$(OBJDIREVENT)/%.o: $(SRCDIREVENT)/%.c
	mkdir -p $(OBJDIREVENT)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIREXECUTOR)/%.o: $(SRCDIREXECUTOR)/%.c
	mkdir -p $(OBJDIREXECUTOR)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRLEXER)/%.o: $(INCLUDEDIRLEXER)/ft_lexer.h

$(OBJDIRLEXER)/%.o: $(SRCDIRLEXER)/%.c
	mkdir -p $(OBJDIRLEXER)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIROPERATION)/%.o: $(SRCDIROPERATION)/%.c
	mkdir -p $(OBJDIROPERATION)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRPARSER)/%.o: $(INCLUDEDIRPARSER)/ft_parser.h

$(OBJDIRPARSER)/%.o: $(SRCDIRPARSER)/%.c
	mkdir -p $(OBJDIRPARSER)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRRESOLVER)/%.o: $(SRCDIRRESOLVER)/%.c
	mkdir -p $(OBJDIRRESOLVER)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRVALIDATOR)/ft_validator.o: $(INCLUDEDIRVALIDATOR)/ft_validator.h

$(OBJDIRVALIDATOR)/%.o: $(SRCDIRVALIDATOR)/%.c
	mkdir -p $(OBJDIRVALIDATOR)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRSECURITY)/%.o: $(SRCDIRSECURITY)/%.c
	mkdir -p $(OBJDIRSECURITY)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRDISPLAY)/%.o: $(INCLUDEDIRDISPLAY)/ft_display.h

$(OBJDIRDISPLAY)/%.o: $(SRCDIRDISPLAY)/%.c
	mkdir -p $(OBJDIRDISPLAY)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRSTOCKER)/%.o: $(SRCDIRSTOCKER)/%.c
	mkdir -p $(OBJDIRSTOCKER)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRSTOCKER)/%.o: $(INCLUDEDIRSTOCKER)/ft_stocker.h

$(OBJDIRENV)/%.o: $(SRCDIRENV)/%.c
	mkdir -p $(OBJDIRENV)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRENV)/%.o: $(INCLUDEDIRENV)/ft_environment.h

$(OBJDIRBUILDINS)/%.o: $(SRCDIRBUILDINS)/%.c
	mkdir -p $(OBJDIRBUILDINS)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRBUILDINS)/%.o: $(INCLUDEDIRBUILDINS)/ft_buildins.h

$(OBJDIRHISTORY)/%.o: $(SRCDIRHISTORY)/%.c
	mkdir -p $(OBJDIRHISTORY)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRHISTORY)/%.o: $(INCLUDEDIRHISTORY)/ft_history.h

$(OBJDIRREGEX)/%.o: $(SRCDIRREGEX)/%.c
	mkdir -p $(OBJDIRREGEX)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIRREGEX)/%.o: $(INCLUDEDIRREGEX)/ft_regex.h

$(OBJDIRDEBUG)/%.o: $(SRCDIRDEBUG)/%.c
	mkdir -p $(OBJDIRDEBUG)
	$(CC) -o $@ -c $< $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS_COMMON) $(OBJS_EVENT) $(OBJS_EXECUTOR) $(OBJS_LEXER)
	rm -f $(OBJS_PARSER) $(OBJS_RESOLVER) $(OBJS_VALIDATOR) $(OBJS)
	rm -f $(OBJS_SECURITY) $(OBJS_DISPLAY) $(OBJS_STOCKER) $(OBJS_ENV)
	rm -f $(OBJS_BUILDINS) $(OBJS_OPERATION) $(OBJS_HISTORY)
	rm -f $(OBJS_REGEX) $(OBJS_DEBUG)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

