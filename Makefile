# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 16:15:58 by pfaria-d          #+#    #+#              #
#    Updated: 2023/02/16 21:45:21 by pfaria-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NOCOLOR			= \033[0m
WHITE			= \033[1;37m
RED				= \033[0;31m
LIGHTPURPLE		= \033[1;35m
CLEAR			= \r\033[K
LIGHTGRAY		= \033[0;37m
GREEN			= \033[0;32m

SRC 		= ft_printf.c \

SRCBONUS	=

OBJS 		= $(SRC:.c=.o)

OBJSBONUS 	= $(SRCBONUS:.c=.o)

GCC 		= gcc

FLAGS		= -Wall -Wextra -Werror

RM  = rm -f

HFILE = ft_printf.h

NAME = libftprintf.a

ifdef 	MAKEBONUS
    OBJS = $(OBJSBONUS)
endif

NORM = $(shell norminette | grep Error: | wc -l | awk '{print $1}')

NORMINETTE = $(shell ls | grep ewhjgewjhghewji | wc -l | awk '{print $1}')

ifeq (${NORM}, ${NORMINETTE})
	NORMINETTE = "${WHITE}NORM : ${GREEN}OK${NOCOLOR}\n"
else
	NORMINETTE = "${WHITE}NORM : ${RED}${NORM}errors${NOCOLOR}\n"
endif

all: 		$(NAME)

.c.o:
			@printf "${CLEAR}🌂 ${LIGHTPURPLE}%s ${LIGHTGRAY}compiling...${NOCOLOR}" ${notdir $<}
			@$(GCC) $(FLAGS) -I $(HFILE) -c $< -o $(<:.c=.o)


$(NAME):	$(OBJS)
			@make -C ./Libft
			@printf "${CLEAR}☂️  ${LIGHTPURPLE}Printf ${LIGHTGRAY}compiled\n${NOCOLOR}"
			@ar rcs $(NAME) $(OBJS)
			@echo	${NORMINETTE}

bonus:		fclean
			@make MAKEBONUS=1 all

clean:
			@make clean -C ./Libft
			@printf "${CLEAR}☂️  ${LIGHTPURPLE}.o files  ${LIGHTGRAY}cleaned\n${NOCOLOR}"
			@$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
			@make fclean -C ./Libft
			@printf "${CLEAR}☂️  ${LIGHTPURPLE}Printf ${LIGHTGRAY}cleaned\n${NOCOLOR}"
			@$(RM) $(NAME)

re:			fclean $(NAME)
