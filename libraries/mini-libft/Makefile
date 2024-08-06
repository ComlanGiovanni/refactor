# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 03:31:05 by gicomlan          #+#    #+#              #
#    Updated: 2024/08/06 12:52:34 by gicomlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib_so_long.a

CC = cc -Wall -Wextra -Werror

SRC = 	ft_strlen.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_calloc.c \
		../get_next_line/get_next_line.c \
		../get_next_line/get_next_line_utils.c \
		../ft_printf/ft_printf.c \
		../ft_printf/ft_printf_hexa.c \
		../ft_printf/ft_printf_ptr.c \
		../ft_printf/ft_printf_unsign.c \
		../ft_printf/ft_printf_nbr.c \
		../ft_printf/ft_printf_str.c

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

BOLD 					= \e[1m
DIM 					= \e[2m
ITALIC					= \e[3m
UNDERLINE 				= \e[4m
BLINK					= \e[5m
REVERSE					= \e[7m
HIDDEN					= \e[8m
STRIKE					= \e[9m
RESET 					= \e[0m

COMP_START	=	echo "\n🚧 $(BOLD)Making of $(RESET)$(PURPLE)$(NAME)$(NO_COLOR): Starting the compilation of *.o...\n"

CLEANED		=	echo "\n💧 $(BOLD)Cleanning of $(RESET)$(GREEN)$(ITALIC)$(UNDERLINE)$(NAME)$(RESET)$(NO_COLOR): $(DIM)Removed$(RESET) all the $(STRIKE)\".o\"$(RESET) files 🗑\\n"

FCLEANED	=	echo "\n🧼 $(BOLD)Fcleanning of $(RESET)$(GREEN)$(ITALIC)$(UNDERLINE)$(NAME)$(RESET)$(NO_COLOR): $(DIM)Removed$(RESET) the $(STRIKE)executables$(RESET) 🗑\\n"

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(COMP_START)
	@ar rc $(NAME) $(OBJS) > /dev/null 2>&1
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@ > /dev/null 2>&1

clean :
	@rm -f $(OBJS)
	$(CLEANED)

fclean : clean
	@rm -f $(NAME)
	$(FCLEANED)

re : fclean all

.PHONY : all clean fclean re
