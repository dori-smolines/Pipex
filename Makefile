# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smolines <smolines@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 09:42:50 by smolines          #+#    #+#              #
#    Updated: 2024/08/01 14:01:37 by smolines         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex

BONUS			= pipex_bonus

CC          	= cc

CFLAGS      	= -Wall -Wextra -Werror -g3

HEADER_FILES	= pipex.h

HEADER			= -I./include

SRC_PATH		= src/

OBJ_PATH		= obj/

RM 				= rm -rf

SRCS = ft_strjoin.c \
	free.c \
	freesuite.c \
	pipex.c \
	ft_strdup.c \
	ft_split.c \
	error.c \
	ft_strncmp.c \
	cmd.c \
	ft_strrchr.c \
	ft_substr.c \
	
SRCS_BONUS = 

SRCS_ALL = ${SRCS_BONUS} ${SRCS} 

OBJS = $(addprefix ${OBJ_PATH}, ${SRCS:.c=.o})

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

OBJS_ALL = ${SRCS_ALL:.c=.o}

all: $(NAME)

bonus: ${BONUS}

$(NAME) : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}  ${HEADER}

${OBJ_PATH}%.o:	${SRC_PATH}%.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} ${HEADER} -c $< -o $@

clean:
	rm -rf ${OBJ_PATH}

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette $(SRC_PATH)/ include/ | awk '/'Error'/ {print; found=1} END {if (!found) print "\033[0;35mNorm O.K.\033[0m"}'
	