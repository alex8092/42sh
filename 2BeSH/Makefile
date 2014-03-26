# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/22 05:49:22 by amerle            #+#    #+#              #
#    Updated: 2014/03/26 16:49:54 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC						=	cc

CFLAGS					=	-Wall -Wextra -Werror -I$(HOME)/.ft/include

STRIP					=

DEBUG					=	true
ifeq ($(DEBUG),true)
	CFLAGS				+=	-ggdb3
else
	CFLAGS				+=	-O3
	STRIP				=	strip $(NAME)
endif

RED						=	\033[0;31m
GREEN					=	\033[0;32m
BLUE					=	\033[0;34m
NO						=	\033[0m

LDFLAGS					=	-ltermcap -std=c89
DIRFT					=	$(HOME)/.ft/lib
LDFLAGS					+=	-Wl,-rpath,$(DIRFT) -L$(DIRFT)
LDFLAGS					+=	-lftcommon -lftgetnextline -lftflagger -lftregex

INCLUDEDIROPERATION		=	Operation/include
INCLUDEDIREVENT			=	Event/include
INCLUDEDIREXECUTOR		=	Executor/include
INCLUDEDIRLEXER			=	Lexer/include
INCLUDEDIRPARSER		=	Parser/include
INCLUDEDIRRESOLVER		=	Resolver/include
INCLUDEDIRVALIDATOR		=	Validator/include
INCLUDEDIRSECURITY		=	Security/include
INCLUDEDIRDISPLAY		=	Display/include
INCLUDEDIRSTOCKER		=	Stocker/include
INCLUDEDIRENV			=	Environment/include
INCLUDEDIRBUILDINS		=	BuildIns/include
INCLUDEDIRHISTORY		=	History/include
INCLUDEDIRDEBUG			=	Debugger/include
INCLUDEDIRDEV			=	Development/include
INCLUDEDIRPROMPT		=	Prompt/include
INCLUDEDIRJOB			=	JobControl/include
INCLUDEDIR				=	include

SRCDIREVENT				=	Event/src
SRCDIREXECUTOR			=	Executor/src
SRCDIRLEXER				=	Lexer/src
SRCDIRPARSER			=	Parser/src
SRCDIRRESOLVER			=	Resolver/src
SRCDIRVALIDATOR			=	Validator/src
SRCDIRSECURITY			=	Security/src
SRCDIRDISPLAY			=	Display/src
SRCDIRSTOCKER			=	Stocker/src
SRCDIRENV				=	Environment/src
SRCDIRBUILDINS			=	BuildIns/src
SRCDIROPERATION			=	Operation/src
SRCDIRHISTORY			=	History/src
SRCDIRDEBUG				=	Debugger/src
SRCDIRDEV				=	Development/src
SRCDIRPROMPT			=	Prompt/src
SRCDIRJOB				=	JobControl/src
SRCDIR					=	src

OBJDIROPERATION			=	Operation/obj
OBJDIREVENT				=	Event/obj
OBJDIREXECUTOR			=	Executor/obj
OBJDIRLEXER				=	Lexer/obj
OBJDIRPARSER			=	Parser/obj
OBJDIRRESOLVER			=	Resolver/obj
OBJDIRVALIDATOR			=	Validator/obj
OBJDIRSECURITY			=	Security/obj
OBJDIRDISPLAY			=	Display/obj
OBJDIRSTOCKER			=	Stocker/obj
OBJDIRENV				=	Environment/obj
OBJDIRBUILDINS			=	BuildIns/obj
OBJDIRHISTORY			=	History/obj
OBJDIRDEBUG				=	Debugger/obj
OBJDIRDEV				=	Development/obj
OBJDIRPROMPT			=	Prompt/obj
OBJDIRJOB				=	JobControl/obj
OBJDIR					=	obj

CFLAGS					+= -I$(INCLUDEDIREVENT)		-I$(INCLUDEDIREXECUTOR)
CFLAGS					+= -I$(INCLUDEDIRLEXER)		-I$(INCLUDEDIRPARSER)
CFLAGS					+= -I$(INCLUDEDIRRESOLVER)	-I$(INCLUDEDIRVALIDATOR)
CFLAGS					+= -I$(INCLUDEDIRSECURITY)	-I$(INCLUDEDIR)
CFLAGS					+= -I$(INCLUDEDIRDISPLAY)	-I$(INCLUDEDIRSTOCKER)
CFLAGS					+= -I$(INCLUDEDIRHISTORY)	-I$(INCLUDEDIRBUILDINS)
CFLAGS					+= -I$(INCLUDEDIROPERATION)	-I$(INCLUDEDIRENV)
CFLAGS					+= -I$(INCLUDEDIRDEBUG)		-I$(INCLUDEDIRDEV)
CFLAGS					+= -I$(INCLUDEDIRPROMPT)		-I$(INCLUDEDIRJOB)

SRCSPROMPT				=	ft_prompt.c \
							ft_prompt_init.c \
							ft_prompt_size.c \
							ft_prompt_string.c

SRCSEVENT				=	ft_event.c					\
							ft_event_init.c				\
							ft_event_map_mv.c			\
							ft_event_map_rm.c			\
							ft_event_map_key.c			\
							ft_event_other.c			\
							ft_event_item.c				\
							ft_event_terms.c			\
							ft_event_history.c

SRCSEXECUTOR			=	ft_executor.c				\
							ft_exec_pipes.c				\
							ft_get_current_job.c		\
							ft_wait_job.c				\
							ft_exec_utils.c				\
							ft_exec_buildins.c

SRCSOPERATION			=	ft_operation.c

SRCSLEXER				=	ft_lexer.c					\
							ft_lexer_lex.c				\
							ft_lexem_template.c			\
							ft_lexer_free.c

SRCSPARSER				=	ft_parser.c					\
							ft_parser_parse.c			\
							ft_init_pars.c				\
							ft_pars_find_op.c			\
							ft_pars_put.c

SRCSRESOLVER			=	ft_resolver.c				\
							ft_resolv_redirects.c		\
							ft_resolv_path.c			\
							ft_resolv_path2.c			\
							ft_resolv_parse.c			\
							ft_resolv_parse2.c			\
							ft_resolv_format.c

SRCSVALIDATOR			=	ft_validator.c				\
							ft_valid_redirects.c

SRCSSECURITY			=	ft_security.c				\
							ft_security_init.c			\
							ft_security_exit.c			\
							ft_security_other.c

SRCSDISPLAY				=	ft_display.c				\
							ft_display_init.c			\
							ft_display_write.c			\
							ft_display_other.c			\
							ft_display_mv.c				\
							ft_display_rm.c				\
							ft_display_terms_size.c		\
							ft_display_save.c

SRCSSTOCKER				=	ft_stocker.c				\
							ft_stocker_lst.c			\
							ft_stocker_push_lst.c		\
							ft_stocker_other.c			\
							ft_stocker_init.c			\
							ft_stocker_remove_lst.c		\
							ft_stocker_mv_current.c		\
							ft_stocker_infos.c

SRCSENV					=	ft_environment.c			\
							ft_unsetenv.c				\
							ft_retrieve_path.c			\
							ft_env_retrieve.c

SRCSBUILDINS			=	ft_buildins.c				\
							ft_cd.c						\
							ft_buildins_util.c			\
							ft_echo.c					\
							ft_exit.c					\
							ft_setenv.c					\
							ft_unsetenv.c				\
							ft_test_amerle.c			\
							ft_cd2.c					\
							ft_fg.c						\
							ft_bg.c						\
							ft_jobs.c					\
							ft_build_history.c			\
							ft_false.c					\
							ft_true.c

SRCSHISTORY				=	ft_history.c				\
							ft_history_init.c			\
							ft_history_other.c			\
							ft_history_push.c			\
							ft_history_mv.c

SRCSDEV					=	ft_development.c			\
							ft_private_developement.c	\
							ft_fct_dir.c 				\
							ft_meth_lex.c

SRCSDEBUG				=	ft_debug.c

SRCSJOB					=	ft_jobcontrol.c 			\
							ft_job_controls.c 			\
							ft_job_bg.c 				\
							ft_job_util.c

SRCS					=	main.c

OBJSBASEPROMPT			=	$(SRCSPROMPT:.c=.o)
OBJSBASEEVENT			=	$(SRCSEVENT:.c=.o)
OBJSBASEEXECUTOR		=	$(SRCSEXECUTOR:.c=.o)
OBJSBASELEXER			=	$(SRCSLEXER:.c=.o)
OBJSBASEOPERATION		=	$(SRCSOPERATION:.c=.o)
OBJSBASEPARSER			=	$(SRCSPARSER:.c=.o)
OBJSBASERESOLVER		=	$(SRCSRESOLVER:.c=.o)
OBJSBASEVALIDATOR		=	$(SRCSVALIDATOR:.c=.o)
OBJSBASESECURITY		=	$(SRCSSECURITY:.c=.o)
OBJSBASEDISPLAY			=	$(SRCSDISPLAY:.c=.o)
OBJSBASESTOCKER			=	$(SRCSSTOCKER:.c=.o)
OBJSBASEENV				=	$(SRCSENV:.c=.o)
OBJSBASEBUILDINS		=	$(SRCSBUILDINS:.c=.o)
OBJSBASEHISTORY			=	$(SRCSHISTORY:.c=.o)
OBJSBASEDEBUG			=	$(SRCSDEBUG:.c=.o)
OBJSBASEDEV				=	$(SRCSDEV:.c=.o)
OBJSBASEJOB				=	$(SRCSJOB:.c=.o)
OBJSBASE				=	$(SRCS:.c=.o)

OBJS_PROMPT				=	$(addprefix $(OBJDIRPROMPT)/, $(OBJSBASEPROMPT))
OBJS_EVENT				=	$(addprefix $(OBJDIREVENT)/, $(OBJSBASEEVENT))
OBJS_EXECUTOR			=	$(addprefix $(OBJDIREXECUTOR)/, $(OBJSBASEEXECUTOR))
OBJS_LEXER				=	$(addprefix $(OBJDIRLEXER)/, $(OBJSBASELEXER))
OBJS_OPERATION			=	$(addprefix $(OBJDIROPERATION)/, $(OBJSBASEOPERATION))
OBJS_PARSER				=	$(addprefix $(OBJDIRPARSER)/, $(OBJSBASEPARSER))
OBJS_RESOLVER			=	$(addprefix $(OBJDIRRESOLVER)/, $(OBJSBASERESOLVER))
OBJS_VALIDATOR			=	$(addprefix $(OBJDIRVALIDATOR)/, $(OBJSBASEVALIDATOR))
OBJS_SECURITY			=	$(addprefix $(OBJDIRSECURITY)/, $(OBJSBASESECURITY))
OBJS_DISPLAY			=	$(addprefix $(OBJDIRDISPLAY)/, $(OBJSBASEDISPLAY))
OBJS_STOCKER			=	$(addprefix $(OBJDIRSTOCKER)/, $(OBJSBASESTOCKER))
OBJS_ENV				=	$(addprefix $(OBJDIRENV)/, $(OBJSBASEENV))
OBJS_BUILDINS			=	$(addprefix $(OBJDIRBUILDINS)/, $(OBJSBASEBUILDINS))
OBJS_HISTORY			=	$(addprefix $(OBJDIRHISTORY)/, $(OBJSBASEHISTORY))
OBJS_DEBUG				=	$(addprefix $(OBJDIRDEBUG)/, $(OBJSBASEDEBUG))
OBJS_DEV				=	$(addprefix $(OBJDIRDEV)/, $(OBJSBASEDEV))
OBJS_JOB				=	$(addprefix $(OBJDIRJOB)/, $(OBJSBASEJOB))
OBJS					=	$(addprefix $(OBJDIR)/, $(OBJSBASE))

COMMONDIR				=	common
ASTRDIR					=	astr
GETNEXTLINEDIR			=	getnextline
FLAGGERDIR				=	flagger
REGEXDIR				=	regex

NAME					=	42sh

SHELL_DIR				=	$(HOME)/.2BeSH

all:	common_make		astr_make		getnextine_make		\
		flagger_make	regex_make		begin_name			\
		start			conf_files

print_begin:
	@rm -f .make_errors
	@echo "Compiling ..."

print_error:
	@if [ -e .make_errors ]; then cat .make_errors; fi
	@rm -f .make_errors

start:	print_begin			$(OBJS_EVENT)		$(OBJS_EXECUTOR)		\
		$(OBJS_LEXER)		$(OBJS_PARSER)		$(OBJS_RESOLVER)		\
		$(OBJS_VALIDATOR)	$(OBJS_SECURITY)	$(OBJS)					\
		$(OBJS_DISPLAY)		$(OBJS_STOCKER)		$(OBJS_ENV)				\
		$(OBJS_BUILDINS)	$(OBJS_OPERATION)	$(OBJS_HISTORY)			\
		$(OBJS_DEBUG)		$(OBJS_DEV)			$(OBJS_PROMPT)			\
		$(OBJS_JOB)			print_error			$(NAME)

conf_files:
	@mkdir -p $(SHELL_DIR)/conf
#	building echo.conf
	@echo 'e: empty\nE: empty\nn: empty' > $(SHELL_DIR)/conf/echo.conf
#	end
#	building cd.conf
	@echo 'L: empty\ns: empty' > $(SHELL_DIR)/conf/cd.conf
#	end

common_make:
	@echo "\t${BLUE}[Common]${NO}"
	@make --no-print-directory -C $(COMMONDIR)
	@make --no-print-directory -C $(COMMONDIR) install

astr_make:
	@echo "\t${BLUE}[Astr]${NO}"
	@make --no-print-directory -C $(ASTRDIR)
	@make --no-print-directory -C $(ASTRDIR) install

getnextine_make:
	@echo "\t${BLUE}[Getnextline]${NO}"
	@make --no-print-directory -C $(GETNEXTLINEDIR)
	@make --no-print-directory -C $(GETNEXTLINEDIR) install

flagger_make:
	@echo "\t${BLUE}[Flagger]${NO}"
	@make --no-print-directory -C $(FLAGGERDIR)
	@make --no-print-directory -C $(FLAGGERDIR) install

regex_make:
	@echo "\t${BLUE}[Regex]${NO}"
	@make --no-print-directory -C $(REGEXDIR)
	@make --no-print-directory -C $(REGEXDIR) install


begin_name:
	@echo "\t${BLUE}[42sh]${NO}"

$(NAME):	$(OBJS_EVENT)		$(OBJS_EXECUTOR)		$(OBJS_LEXER)		\
			$(OBJS_PARSER)		$(OBJS_RESOLVER)		$(OBJS_VALIDATOR)	\
			$(OBJS_SECURITY)	$(OBJS) $(OBJS_DISPLAY)	$(OBJS_STOCKER)		\
			$(OBJS_ENV)			$(OBJS_BUILDINS)		$(OBJS_OPERATION)	\
			$(OBJS_HISTORY)		$(OBJS_DEBUG)			$(OBJS_DEV)			\
			$(OBJS_PROMPT)		$(OBJS_JOB)
	@$(CC) -o $(NAME) $^ $(LDFLAGS)
	$(STRIP)

prompt_h				=	$(OBJS_PROMPT) \
							$(OBJDIRDISPLAY)/ft_display_terms_size.o \
							$(OBJDIRDISPLAY)/ft_display_write.o \
							$(OBJDIREVENT)/ft_event_map_key.o \
prompt_private_h		=	$(OBJS_PROMPT)

environment_h			=	$(OBJS_ENV) \
							$(OBJDIRPROMPT)/ft_prompt_string.o \
							$(OBJDIREVENT)/ft_event_terms.o \
							$(OBJDIREXECUTOR)/ft_executor.o \
							$(OBJDIRRESOLVER)/ft_resolv_path.o \
							$(OBJDIRVALIDATOR)/ft_validator.o \
							$(OBJDIRBUILDINS)/ft_cd.o \
							$(OBJDIRBUILDINS)/ft_cd2.o \
							$(OBJDIRBUILDINS)/ft_setenv.o \
							$(OBJDIRBUILDINS)/ft_unsetenv.o \
							$(OBJDIRDEV)/ft_private_developement.o

event_h					=	$(OBJS_EVENT) \
							$(OBJDIRLEXER)/ft_lexer.o \
							$(OBJDIRDISPLAY)/ft_display_terms_size.o
event_private_h			=	$(OBJS_EVENT)

history_h				=	$(OBJS_HISTORY) \
							$(OBJDIREVENT)/ft_event_history.o \
							$(OBJDIREVENT)/ft_event_map_rm.o \
							$(OBJDIREVENT)/ft_event_other.o \
							$(OBJDIRBUILDINS)/ft_build_history.o

display_h				=	$(OBJS_DISPLAY) \
							$(OBJDIREVENT)/ft_event_init.o \
							$(OBJDIREVENT)/ft_event_map_mv.o \
							$(OBJDIREVENT)/ft_event_map_rm.o \
							$(OBJDIREVENT)/ft_event_other.o \
							$(OBJDIREVENT)/ft_event_terms.o \
							$(OBJDIREXECUTOR)/ft_executor.o \
							$(OBJDIRLEXER)/ft_lexer.o \
							$(OBJDIRVALIDATOR)/ft_validator.o \
							$(OBJDIRSECURITY)/ft_security_init.o \
							$(OBJDIREVENT)/ft_event_map_key.o
display_private_h		=	$(OBJS_DISPLAY)

stocker_h				=	$(OBJS_STOCKER) \
							$(OBJDIREVENT)/ft_event_map_mv.o \
							$(OBJDIREVENT)/ft_event_map_rm.o \
							$(OBJDIREVENT)/ft_event_other.o \
							$(OBJDIREVENT)/ft_event_terms.o \
							$(OBJDIRLEXER)/ft_lexer.o \
							$(OBJDIRDISPLAY)/ft_display_terms_size.o \
							$(OBJDIRHISTORY)/ft_history_other.o \
							$(OBJDIRHISTORY)/ft_history_mv.o \
							$(OBJDIREVENT)/ft_event_map_key.o
stocker_private_h		=	$(OBJS_STOCKER)

operation_h				=	$(OBJS_EXECUTOR) $(OBJS_OPERATION) \
							$(OBJS_RESOLVER) $(OBJS_VALIDATOR)

executor_h				=	$(OBJS_EXECUTOR) \
							$(OBJDIREXECUTOR)/ft_executor.o \
							$(OBJDIRRESOLVER)/ft_resolv_parse.o \
							$(OBJDIRRESOLVER)/ft_resolver.o

buildin_h				=	$(OBJS_BUILDINS) \
							$(OBJDIREXECUTOR)/ft_exec_buildins.o
buildin_private_h		=	$(OBJS_BUILDINS)

validator_h				=	$(OBJS_VALIDATOR) \
							$(OBJDIREXECUTOR)/ft_executor.o

jobcontrol_h			=	$(OBJS_JOB) \
							$(OBJDIREXECUTOR)/ft_executor.o \
							$(OBJDIRLEXER)/ft_lexer.o \
							$(OBJDIRSECURITY)/ft_security_init.o \
							$(OBJDIRBUILDINS)/ft_bg.o \
							$(OBJDIRBUILDINS)/ft_exit.o \
							$(OBJDIRBUILDINS)/ft_fg.o \
							$(OBJDIRBUILDINS)/ft_jobs.o

security_h				=	$(OBJS_SECURITY) \
							$(OBJDIREXECUTOR)/ft_excutor.o \
							$(OBJDIRLEXER)/ft_lexem_template.o \
							$(OBJDIRLEXER)/ft_lexer.o \
							$(OBJDIRRESOLVER)/ft_resolver.o \
							$(OBJDIR)/main.o \
							$(OBJDIRJOB)/ft_job_controls.o \
							$(OBJDIRJOB)/ft_job_util.o
security_private_h		=	$(OBJS_SECURITY)

lexer_h					=	$(OBJS_LEXER) $(OBJS_PARSER) $(OBJS_DEV) \
							$(OBJDIROPERATION)/ft_operation.o \
							$(OBJDIRPARSER)/ft_pars_find_op.o \
							$(OBJDIRRESOLVER)/ft_resolver.o \
							$(OBJDIR)/main.o
lexer_private_h			=	$(OBJS_LEXER)

parser_h				=	$(OBJS_PARSER) $(OBJS_RESOLVER) \
							$(OBJDIR)/main.o
parser_private_h		=	$(OBJS_PARSER)

resolver_h				=	$(OBJS_RESOLVER) \
							$(OBJDIRPARSER)/ft_parser.o \
							$(OBJDIRBUILDINS)/ft_cd.o \
							$(OBJDIRBUILDINS)/ft_echo.o \
							$(OBJDIRHISTORY)/ft_history_init.o \
							$(OBJDIRDEV)/ft_private_developement.o

dev_h					=	$(OBJS_DEV) \
							$(OBJDIRRESOLVER)/ft_resolv_parse.o
dev_private_h			=	$(OBJS_DEV)

history_h				=	$(OBJS_HISTORY) \
							$(OBJDIR)/main.o
history_private_h		=	$(OBJS_HISTORY)

debug_h					=	$(OBJS_DEBUG)

$(prompt_h)				:	$(INCLUDEDIRPROMPT)/ft_prompt.h
$(prompt_private_h)		:	$(INCLUDEDIRPROMPT)/ft_prompt_private.h
$(environment_h)		:	$(INCLUDEDIRENV)/ft_environment.h
$(event_h)				:	$(INCLUDEDIREVENT)/ft_event.h
$(event_private_h)		:	$(INCLUDEDIREVENT)/ft_event_private.h
$(history_h)			:	$(INCLUDEDIRHISTORY)/ft_history.h
$(display_h)			:	$(INCLUDEDIRDISPLAY)/ft_display.h
$(display_private_h)	:	$(INCLUDEDIRDISPLAY)/ft_display_private.h
$(stocker_h)			:	$(INCLUDEDIRSTOCKER)/ft_stocker.h
$(stocker_private_h)	:	$(INCLUDEDIRSTOCKER)/ft_stocker_private.h
$(operation_h)			:	$(INCLUDEDIROPERATION)/ft_operation.h
$(executor_h)			:	$(INCLUDEDIREXECUTOR)/ft_executor.h
$(buildin_h)			:	$(INCLUDEDIRBUILDINS)/ft_buildins.h
$(validator_h)			:	$(INCLUDEDIRVALIDATOR)/ft_validator.h
$(jobcontrol_h)			:	$(INCLUDEDIRJOB)/ft_jobcontrol.h
$(security_h)			:	$(INCLUDEDIRSECURITY)/ft_security.h
$(security_private_h)	:	$(INCLUDEDIRSECURITY)/ft_security_private.h
$(lexer_h)				:	$(INCLUDEDIRLEXER)/ft_lexer.h
$(lexer_private_h)		:	$(INCLUDEDIRLEXER)/ft_lexer_private.h
$(parser_h)				:	$(INCLUDEDIRPARSER)/ft_parser.h
$(parser_private_h)		:	$(INCLUDEDIRPARSER)/ft_parser_private.h
$(resolver_h)			:	$(INCLUDEDIRRESOLVER)/ft_resolver.h
$(dev_h)				:	$(INCLUDEDIRDEV)/ft_development.h
$(dev_private_h)		:	$(INCLUDEDIRDEV)/ft_private_developement.h
$(history_h)			:	$(INCLUDEDIRHISTORY)/ft_history.h
$(history_private_h)	:	$(INCLUDEDIRHISTORY)/ft_history_private.h
$(debug_h)				:	$(INCLUDEDIRDEBUG)/ft_debug.h

$(OBJDIRPROMPT)/%.o: $(SRCDIRPROMPT)/%.c
	@mkdir -p $(OBJDIRPROMPT)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors\
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIREVENT)/%.o: $(SRCDIREVENT)/%.c
	@mkdir -p $(OBJDIREVENT)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIREXECUTOR)/%.o: $(SRCDIREXECUTOR)/%.c
	@mkdir -p $(OBJDIREXECUTOR)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRLEXER)/%.o: $(SRCDIRLEXER)/%.c
	@mkdir -p $(OBJDIRLEXER)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIROPERATION)/%.o: $(SRCDIROPERATION)/%.c
	@mkdir -p $(OBJDIROPERATION)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRPARSER)/%.o: $(SRCDIRPARSER)/%.c
	@mkdir -p $(OBJDIRPARSER)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRRESOLVER)/%.o: $(SRCDIRRESOLVER)/%.c
	@mkdir -p $(OBJDIRRESOLVER)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRVALIDATOR)/%.o: $(SRCDIRVALIDATOR)/%.c
	@mkdir -p $(OBJDIRVALIDATOR)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRSECURITY)/%.o: $(SRCDIRSECURITY)/%.c
	@mkdir -p $(OBJDIRSECURITY)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRDISPLAY)/%.o: $(SRCDIRDISPLAY)/%.c
	@mkdir -p $(OBJDIRDISPLAY)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRSTOCKER)/%.o: $(SRCDIRSTOCKER)/%.c
	@mkdir -p $(OBJDIRSTOCKER)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRENV)/%.o: $(SRCDIRENV)/%.c
	@mkdir -p $(OBJDIRENV)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRBUILDINS)/%.o: $(SRCDIRBUILDINS)/%.c
	@mkdir -p $(OBJDIRBUILDINS)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRHISTORY)/%.o: $(SRCDIRHISTORY)/%.c
	@mkdir -p $(OBJDIRHISTORY)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRDEBUG)/%.o: $(SRCDIRDEBUG)/%.c
	@mkdir -p $(OBJDIRDEBUG)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRDEV)/%.o: $(SRCDIRDEV)/%.c
	@mkdir -p $(OBJDIRDEV)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

$(OBJDIRJOB)/%.o: $(SRCDIRJOB)/%.c
	@mkdir -p $(OBJDIRJOB)
	@($(CC) -o $@ -c $< $(CFLAGS) 2>> .make_errors \
	&& echo "${GREEN}[-]${NO} Compiling \"$@\"") \
	|| echo "${RED}[x]${NO} Compiling \"$@\""

common_clean:
	@echo "\t${BLUE}[Common]${NO}"
	@make --no-print-directory -C $(COMMONDIR) clean

astr_clean:
	@echo "\t${BLUE}[Astr]${NO}"
	@make --no-print-directory -C $(ASTRDIR) clean

getnextline_clean:
	@echo "\t${BLUE}[Getnextline]${NO}"
	@make --no-print-directory -C $(GETNEXTLINEDIR) clean

flagger_clean:
	@echo "\t${BLUE}[Flagger]${NO}"
	@make --no-print-directory -C $(FLAGGERDIR) clean

regex_clean:
	@echo "\t${BLUE}[Regex]${NO}"
	@make --no-print-directory -C $(REGEXDIR) clean

clean: common_clean astr_clean getnextline_clean flagger_clean regex_clean
	@echo "\t${BLUE}[42sh]${NO}"
	@echo "Cleaning objs ..."
	@rm -f $(OBJS_EVENT)	$(OBJS_EXECUTOR)	$(OBJS_LEXER)
	@rm -f $(OBJS_PARSER)	$(OBJS_RESOLVER)	$(OBJS_VALIDATOR)
	@rm -f $(OBJS)			$(OBJS_SECURITY)	$(OBJS_DISPLAY)
	@rm -f $(OBJS_BUILDINS)	$(OBJS_OPERATION)	$(OBJS_HISTORY)
	@rm -f $(OBJS_DEBUG)	$(OBJS_DEV)			$(OBJS_PROMPT) 
	@rm -f $(OBJS_JOB)		$(OBJS_STOCKER)		$(OBJS_ENV)

common_fclean:
	@echo "\t${BLUE}[Common]${NO}"
	@make --no-print-directory -C $(COMMONDIR) fclean
	@make --no-print-directory -C $(COMMONDIR) uninstall

astr_fclean:
	@echo "\t${BLUE}[Astr]${NO}"
	@make --no-print-directory -C $(ASTRDIR) fclean
	@make --no-print-directory -C $(ASTRDIR) uninstall

getnextline_fclean:
	@echo "\t${BLUE}[Getnextline]${NO}"
	@make --no-print-directory -C $(GETNEXTLINEDIR) fclean
	@make --no-print-directory -C $(GETNEXTLINEDIR) uninstall

flagger_fclean:
	@echo "\t${BLUE}[Flagger]${NO}"
	@make --no-print-directory -C $(FLAGGERDIR) fclean
	@make --no-print-directory -C $(FLAGGERDIR) uninstall

regex_fclean:
	@echo "\t${BLUE}[Regex]${NO}"
	@make --no-print-directory -C $(REGEXDIR) fclean
	@make --no-print-directory -C $(REGEXDIR) uninstall

fclean: clean common_fclean astr_fclean getnextline_fclean flagger_fclean \
		regex_fclean
	@echo "\t${BLUE}[42sh]${NO}"
	@echo "Cleaning binary ..."
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean common_clean common_fclean common_make all re \
		astr_clean astr_fclean astr_make \
		getnextine_make getnextline_clean getnextline_fclean \
		flagger_clean flagger_fclean flagger_make \
		regex_clean regex_fclean regex_make

