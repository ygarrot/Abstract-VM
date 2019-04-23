# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 12:06:15 by ygarrot           #+#    #+#              #
#    Updated: 2019/04/23 16:47:38 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all $(NAME) clean fclean re
.SUFFIXES:

NAME = vm

CC = clang++
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g3 -std=c++1z
CFLAGS += -fsanitize=address,undefined

SRCDIR = src
OBJDIR = obj
INCDIR =  \
		  src/Exceptions\
		  src/Lexer\
		  src/Operand\
		  src/Parser\
		  src/Vm\

SRC = \
	  Exceptions/Exceptions.cpp\
	  Lexer/Lexer.cpp\
	  main.cpp\
	  Operand/Int8.cpp\
	  Operand/Int16.cpp\
	  Operand/Int32.cpp\
	  Operand/Float.cpp\
	  Operand/Double.cpp\
	  Parser/Parser.cpp\
	  Vm/Computor.cpp

	   # Exceptions/Exceptions.cpp\
#Colors

_RED=$(shell tput setaf 1)
_GREEN=$(shell tput setaf 2)
_YELLOW=$(shell tput setaf 3)
_BLUE=$(shell tput setaf 4)
_PURPLE=$(shell tput setaf 5)
_CYAN=$(shell tput setaf 6)
_WHITE=$(shell tput setaf 7)
_END=$(shell tput sgr0)

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
ALL_OBJ_DIR = $(sort $(dir $(OBJS)))
INCS = $(addprefix -I, $(addsuffix /, $(INCDIR)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCS)
	@echo "$(_CYAN)\nCompiling library $(NAME)... $(_GREEN)DONE$(_END)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	@mkdir -p $(ALL_OBJ_DIR) || true
	@printf "                                                          \r"
	@printf "$(_CYAN)Compiling $@$(_END)\r"
	@$(CC) -o $@ -c $(CFLAGS) $< $(INCS)

clean:
	@echo "$(_RED)Removed objects (.o) files.$(_END)"
	@/bin/rm -rf obj

fclean: clean
	@echo "$(_RED)Removed ($(NAME)).$(_END)"
	@/bin/rm -f $(NAME)

re:
	@make fclean
	@make all
