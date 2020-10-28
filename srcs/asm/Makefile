# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/25 15:05:00 by lhitmonc          #+#    #+#              #
#    Updated: 2020/10/25 15:05:02 by lhitmonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLEAR			:= "\033[2K"
UP				:= "\033[A"
EOC				:= "\033[0;0m"
BLACK			:= "\033[0;30m"
RED				:= "\033[0;31m"
GREEN			:= "\033[0;32m"
YELLOW			:= "\033[0;33m"
BLUE			:= "\033[0;34m"
PURPLE			:= "\033[0;35m"
CYAN			:= "\033[0;36m"
WHITE			:= "\033[0;37m"

ASM				:= ../../asm

CC				:= gcc
FLAGS			:= -g -Wall -Wextra -Werror

ASM_SRCS_FILES		:=	op.c			\
						asm.c			\
						deasm.c			\
						asm_utils.c		\
						lexer.c			\
						label.c			\
						label_init.c	\
						label_utils.c	\
						parser.c		\
						parser_init.c	\
						parser_header.c	\
						scanner.c		\
						fixed_io.c		\
						deasm_manage.c

ASM_HEADERS_FILES	:=	op.h		\
						parser.h	\
						scanner.h	\
						lexer.h		\
						label.h		\
						asm.h		\
						fixed_io.h	\
						deasm.h

ASM_PATH		:= srcs/asm/

ASM_SRCS		:= $(addprefix $(ASM_PATH), $(ASM_SRCS_FILES))

OBJS_PATH			:= objs/

ASM_OBJS		:= $(addprefix $(OBJS_PATH), $(ASM_SRCS_FILES:.c=.o))

INCLUDES_PATH	:= includes/
INCLUDES		:= -I $(INCLUDES_PATH)
ASM_HEADERS		:= $(addprefix $(INCLUDES_PATH), $(ASM_HEADERS_FILES))


LIBFT_PATH		:= libft/
LIBFT_INCLUDES	:= -I libft/includes
LIBFT			:= -L $(LIBFT_PATH) -lft -lncurses -lpthread

.PHONY: all libft clean fclean re

all: obj libft $(ASM)

obj:
	@mkdir -p $(OBJS_PATH)

libft:
	@make -C $(LIBFT_PATH)

$(OBJS_PATH)%.o: $(ASM_PATH)%.c $(ASM_HEADERS) $(LIBFT_PATH)libft.a
	@$(CC) $(FLAGS) $(INCLUDES) $(LIBFT_INCLUDES) -o $@ -c $<

$(ASM): $(ASM_OBJS)
	@$(CC) $(FLAGS) $(LIBFT) $(ASM_OBJS) -o $@

clean:
	@make -C $(LIBFT_PATH) clean &> /dev/null
	@rm -fv $(ASM_OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	@make -C $(LIBFT_PATH) fclean &> /dev/null
	@rm -fv $(ASM)
	@rm -rf objs

re: fclean all
