# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 17:20:03 by rclanget          #+#    #+#              #
#    Updated: 2016/12/07 17:20:04 by rclanget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libglob.a

INCS := includes
SRCS := srcs
OBJS := objs

SHELL := /bin/bash

INCLUDES := -I$(INCS) -I$(INCS)/private

# Search source files
C_FILES := $(shell find $(SRCS) -type f)
C_DIRS := $(shell find $(SRCS) -depth -type d)
C_FLAGS += -MMD -std=c99 -g -Wall -Wextra -Werror

# Build .o list
O_DIRS := $(addprefix $(OBJS)/,$(C_DIRS))
O_FILES_TMP := $(C_FILES:%.c=$(OBJS)/%.o)
O_FILES := $(O_FILES_TMP:%.s=$(OBJS)/%.o)

DEPS := $(O_FILES:.o=.d)

# Create OBJS and childs
$(shell mkdir -p $(O_DIRS) $(OBJS))

# Print
ACTUAL = $(words $(COUNT))
TOTAL = $(words $(filter %.c,$(C_FILES)))
INCREMENT = $(eval COUNT+=1)

PRINTINC = $(INCREMENT) $(PRINT)
PRINT = printf "\r \033[31;1m%3s%%\033[0m\t -->>\t\033[31;1m%-65s\033[0m\r" "$(shell echo $(ACTUAL)\*100\/$(TOTAL) | bc)" "$^"
PRINTDONE = printf "\r \033[32;1m%3s%%\033[0m\t -->>\t\033[32;1m%-65s\033[0m\r" "$(shell echo $(ACTUAL)\*100\/$(TOTAL) | bc)" "$@"

all:
	@make $(NAME)

$(NAME): $(O_FILES)
	@ar rcs $@ $^ && $(PRINTDONE) && echo || exit

$(OBJS)/%.o: %.c
	@clang $(C_FLAGS) $(INCLUDES) -o $@ -c $< && $(PRINTINC) || exit

clean:
	@rm -rf $(O_FILES) $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
