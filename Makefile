# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 16:15:58 by pfaria-d          #+#    #+#              #
#    Updated: 2023/03/06 16:38:05 by pfaria-d         ###   ########.fr        #
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
			  ft_printf_parsing.c \
			  ft_addchar.c \
			  ft_itoa_base.c \
			  ft_ptoa.c \
			  ft_strdup2.c \

SRCBONUS	= ft_printf.c \
			  ft_printf_parsing.c \
			  ft_addchar.c \
			  ft_itoa_base.c \
			  ft_ptoa.c \
			  ft_strdup2.c \

OBJS 		= $(SRC:.c=.o)

OBJSBONUS 	= $(SRCBONUS:.c=.o)

GCC 		= gcc

FLAGS		= -Wall -Wextra -Werror

RM  = rm -f

NAME = libftprintf.a

ifdef 	MAKEBONUS
    OBJS = $(OBJSBONUS)
endif

NORM = $(shell norminette | grep Error: | wc -l | awk '{print $1}' | xargs)

NORMINETTE = 0

ifeq (${NORM}, ${NORMINETTE})
	NORMINETTE = "${WHITE}NORM : ${GREEN}OK${NOCOLOR}\n"
else
	NORMINETTE = "${WHITE}NORM : ${RED}${NORM} errors${NOCOLOR}\n"
endif

all: 		$(NAME)

.c.o:
			@printf "${CLEAR}🌂 ${LIGHTPURPLE}%s ${LIGHTGRAY}compiling...${NOCOLOR}" ${notdir $<}
			@$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)


$(NAME):	$(OBJS)
			@make -C ./Libft
			@printf "${CLEAR}☂️  ${LIGHTPURPLE}Printf ${LIGHTGRAY}compiled\n${NOCOLOR}"
			@cp ./Libft/libft.a ${NAME}
			@$(GCC) $(FLAGS)  -c -I ./ ${SRC}
			@ar rcs $(NAME) $(OBJS)
			@echo ${NORMINETTE}

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
