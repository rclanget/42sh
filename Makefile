# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 18:39:36 by ulefebvr          #+#    #+#              #
#    Updated: 2016/11/14 17:41:55 by gdeguign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_PATH		=	./obj/
INC_PATH		=	./includes/ ./libft/includes/
NAME			=	./21sh
CC				=	gcc -g
CFLAGS			=	-Wall -Werror -Wextra

SRC_ALIAS		=	./srcs/alias/
SRCN_ALIAS		=	add_alias.c check_alias.c free_alias.c remove_alias.c \
					search_alias.c update_alias.c len_alias.c apply_alias.c \
					apply_alias_get.c
OBJ_ALIAS		=	$(SRCN_ALIAS:.c=.o)
SRCS_ALIAS		=	$(addprefix $(SRC_ALIAS),$(SRCN_ALIAS))

SRC_ENV			=	./srcs/env/
SRCN_ENV		=	env_add_var.c env_lst_tab.c env_remove_var.c \
					env_update_var.c ft_init_env.c search_env_var.c \
					update_path.c
OBJ_ENV			=	$(SRCN_ENV:.c=.o)
SRCS_ENV		=	$(addprefix $(SRC_ENV),$(SRCN_ENV))

SRC_EXEC		=	./srcs/execution/
SRCN_EXEC		=	builtin_alias.c builtin_setenv.c execution_builtin.c \
					operator_comma.c redirection_get_fd.c  \
					builtin_cd.c builtin_unalias.c execution_command.c \
					execution_status.c operator_or.c  \
					builtin_echo.c builtin_unsetenv.c execution_motor.c \
					operator_and.c operator_pipe.c  \
					builtin_env.c redirection_all.c process_subshell.c \
					redirection_dleft.c process_magicquote_fn.c \
					process_magicquote.c builtin_history.c \
					builtin_history_optps.c builtin_history_optcd.c \
					builtin_history_optanrw.c builtin_exit.c \
					redirection_agreg.c redirection_agreg_fn.c \
					redirection_dleft_fn.c
OBJ_EXEC		=	$(SRCN_EXEC:.c=.o)
SRCS_EXEC		=	$(addprefix $(SRC_EXEC),$(SRCN_EXEC))

SRC_HASH		=	./srcs/hashmap/
SRCN_HASH		=	hashmap.c hashmap_2.c hashmap_free.c
OBJ_HASH		=	$(SRCN_HASH:.c=.o)
SRCS_HASH		=	$(addprefix $(SRC_HASH),$(SRCN_HASH))

SRC_TOOLS		=	./srcs/tools/
SRCN_TOOLS		=	ft_strjoinb.c ft_strjoinc.c ft_strndup.c \
					ft_tabjoin.c ft_tablen.c ft_strjoin_tool.c strsplitcustom.c \
					clean_backslash.c ft_strerror.c signal.c ft_isalnum_or_dot.c \
					ft_strdup_spe.c
OBJ_TOOLS		=	$(SRCN_TOOLS:.c=.o)
SRCS_TOOLS		=	$(addprefix $(SRC_TOOLS),$(SRCN_TOOLS))

SRC_MAIN		=	./srcs/main/
SRCN_MAIN		=	main.c
OBJ_MAIN		=	$(SRCN_MAIN:.c=.o)
SRCS_MAIN		=	$(addprefix $(SRC_MAIN),$(SRCN_MAIN))

SRC_TERM		=	./srcs/termcaps_readline/
SRCN_TERM		=	ft_getenv.c keyboard_ccp.c keyboard_clear.c \
					keyboard_del_sup.c keyboard_line_updown.c \
					keyboard_move_cursor.c keyboard_move_word.c \
					keyboard_start_end.c parser_check_highest.c parser_free.c \
					parser_main.c parser_op_andor.c parser_op_comma.c \
					parser_op_left.c parser_op_parentheses.c parser_op_pipe.c \
					parser_op_right.c parser_op_rightfd.c \
					termcap_capinit.c termcap_winsz.c termcaps_activation.c \
					termcaps_available.c termcaps_handle_keyboard.c \
					termcaps_loop.c termcaps_print.c termcaps_readline.c \
					termcaps_save.c parser_op_logical.c parser_op_redir.c \
					parser_definition_code.c parser_definition_code_get.c \
					parser_clean_parentheses.c keyboard_updown.c \
					keyboard_ccp_fn.c keyboard_reverse_search.c \
					parser_history_substitute.c auto_completion.c auto_completion_2.c\
					auto_completion_3.c auto_completion_4.c
OBJ_TERM		=	$(SRCN_TERM:.c=.o)
SRCS_TERM		=	$(addprefix $(SRC_TERM),$(SRCN_TERM))

SRC_SYNTAX		=	./srcs/syntax/
SRCN_SYNTAX		=	syntax_analyse.c
OBJ_SYNTAX		=	$(SRCN_SYNTAX:.c=.o)
SRCS_SYNTAX		=	$(addprefix $(SRC_SYNTAX),$(SRCN_SYNTAX))

SRC_HISTORY		=	./srcs/history/
SRCN_HISTORY	=	add_history.c free_history.c copy_history.c
OBJ_HISTORY		=	$(SRCN_HISTORY:.c=.o)
SRCS_HISTORY	=	$(addprefix $(SRC_HISTORY),$(SRCN_HISTORY))

SRC_NAME		=	$(SRCN_ALIAS) $(SRCN_ENV) $(SRCN_EXEC) \
					$(SRCN_TOOLS) $(SRCN_TERM) $(SRCN_MAIN) \
					$(SRCN_HASH) $(SRCN_SYNTAX) $(SRCN_HISTORY)
OBJ_NAME		=	$(SRC_NAME:.c=.o)
SRC				=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ				=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC				=	$(addprefix -I,$(INC_PATH))
LDFLAGS			=	-L libft -l ft -l termcap

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) $(LDFLAGS) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_ALIAS)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_ENV)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_EXEC)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_TOOLS)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_MAIN)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_TERM)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_HASH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_SYNTAX)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_HISTORY)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	make clean -C libft
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	make fclean -C libft
	rm -fv $(NAME)

re: fclean all

norme:
	norminette srcs
	norminette $(INC_PATH)*.h
