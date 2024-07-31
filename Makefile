# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 03:25:21 by gicomlan          #+#    #+#              #
#    Updated: 2024/07/29 04:57:46 by gicomlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ VARIABLES ------------------------------

GCC			= gcc -Wall -Wextra -Werror -g

#GCC			+= -fsanitize=address

NAME		=	so_long

LIB_PATH	=	./lib/small_lib

LIB_NAME	=	lib_so_long.a

MAC_PATH	=	./mlx_mac

LINUX_PATH 	=	./mlx_linux

BONUS_PATH	=	./bonus

BONUS_NAME	=	so_long_bonus

FRAME_WORK	=	-framework OpenGL -framework AppKit

LINUX_FLAGS = 	-L $(LINUX_PATH) -lmlx -lXext -lX11 -lm -lz

MAC_FLAGS 	=	-L $(MAC_PATH) -lmlx $(FRAME_WORK)

RM			=	rm -f

OS			:=	$(shell uname)

# ------------------------------ SRC ------------------------------

SRCS_MAC		=		main_mac.c \
						./src_mac/input_mac.c \
						./src_mac/map_mac.c \
						./src_mac/so_long_mac.c \
						./src_mac/sprite_mac.c \
						./src_mac/tools_mac.c \
						./src_mac/check_map_format_mac.c

SRCS_LINUX		=		main_linux.c \
						./src_linux/input_linux.c \
						./src_linux/map_linux.c \
						./src_linux/so_long_linux.c \
						./src_linux/sprite_linux.c \
						./src_linux/tools_linux.c \
						./src_linux/check_map_format_linux.c \
						./src_linux/check_map_finishable.c \
						./src_linux/ft_utils_map_finishable.c \
						./src_linux/ft_debug.c

SRCS_MAC_BONUS		=   ./bonus_mac/main_mac.c \
						./bonus_mac/src/input_bonus_mac.c \
						./bonus_mac/src/map_bonus_mac.c \
						./bonus_mac/src/so_long_bonus_mac.c \
						./bonus_mac/src/sprite_bonus_mac.c \
						./bonus_mac/src/tools_bonus_mac.c \
						./bonus_mac/src/animation_bonus_mac.c \
						./bonus_mac/src/other_tools_bonus_mac.c \
						./bonus_mac/src/load_sprite_bonus_mac.c \
						./bonus_mac/src/load_player_sprite_bonus_mac.c \
						./bonus_mac/src/load_door_sprite_bonus_mac.c \
						./bonus_mac/src/life_management_mac.c \
						./bonus_mac/src/input_fct_bonus_mac.c \
						./bonus_mac/src/map_sprite_bonus_mac.c \
						./bonus_mac/src/player_sprite_direction_bonus_mac.c \
						./bonus_mac/src/check_map_format_mac.c \
						./bonus_mac/src/lava_movement_mac.c

SRCS_LINUX_BONUS	=	./bonus_linux/main_linux.c \
						./bonus_linux/src/input_bonus_linux.c \
						./bonus_linux/src/map_bonus_linux.c \
						./bonus_linux/src/so_long_bonus_linux.c \
						./bonus_linux/src/sprite_bonus_linux.c \
						./bonus_linux/src/tools_bonus_linux.c \
						./bonus_linux/src/animation_bonus_linux.c \
						./bonus_linux/src/other_tools_bonus_linux.c \
						./bonus_linux/src/load_sprite_bonus_linux.c \
						./bonus_linux/src/load_player_sprite_bonus_linux.c \
						./bonus_linux/src/load_door_sprite_bonus_linux.c \
						./bonus_linux/src/life_management_linux.c \
						./bonus_linux/src/input_fct_bonus_linux.c \
						./bonus_linux/src/map_sprite_bonus_linux.c \
						./bonus_linux/src/player_sprite_direction_bonus_linux.c \
						./bonus_linux/src/check_map_format_linux.c \
						./bonus_linux/src/lava_movement_linux.c \
						./bonus_linux/src/free_all.c \
						./bonus_linux/src/ft_free_all_one.c \
						./bonus_linux/src/check_map_finishable.c \
						./bonus_linux/src/ft_utils_map_finishable.c \
						./bonus_linux/src/ft_debug.c \
						./bonus_linux/src/ft_error_managements.c \
						./bonus_linux/src/ft_camera_bonus_linux.c \
						./bonus_linux/src/ft_create_map_with_border_bonus.c

SRCS_MAC_OBJS		=	$(SRCS_MAC:.c=.o)

SRCS_LINUX_OBJS		=	$(SRCS_LINUX:.c=.o)

OBJS_MAC_BONUS		=	$(SRCS_MAC_BONUS:.c=.o)

OBJS_LINUX_BONUS	=	$(SRCS_LINUX_BONUS:.c=.o)

ifeq ($(OS),Darwin)
	MLX_NAME	=	libmlx.a
	MLX_PATH = $(MAC_PATH)
	MLX_FLAGS = $(MAC_FLAGS)
	SRC = $(SRCS_MAC)
	SRCS_BONUS = $(SRCS_MAC_BONUS)
else ifeq ($(OS),Linux)
	MLX_NAME	=	libmlx_Linux.a
	MLX_PATH = $(LINUX_PATH)
	MLX_FLAGS = $(LINUX_FLAGS)
	SRC = $(SRCS_LINUX)
	SRCS_BONUS = $(SRCS_LINUX_BONUS)
else
$(error Incompatable OS Detected Linux and Mac os only)
endif

# ------------------------------ Colors ------------------------------

BLACK			=	\e[0;30m
RED				=	\e[0;31m
GREEN			=	\e[0;32m
ORANGE			=	\e[0;33m
BLUE			=	\e[0;34m
PURPLE			=	\e[0;35m
CYAN			=	\e[0;36m
LIGHT_GRAY		=	\e[0;37m
DARK_GRAY		=	\e[1;30m
LIGHT_RED		=	\e[1;31m
LIGHT_GREEN		=	\e[1;32m
YELLOW			=	\e[1;33m
LIGHT_BLUE		=	\e[1;34m
LIGHT_PURPLE	=	\e[1;35m
LIGHT_CYAN		=	\e[1;36m
WHITE			=	\e[1;37m
NO_COLOR		=	\e[0m

# Définir les séquences d'échappement ANSI

BOLD 			= \e[1m
DIM 			= \e[2m
ITALIC			= \e[3m
UNDERLINE 		= \e[4m
BLINK			= \e[5m
REVERSE			= \e[7m
HIDDEN			= \e[8m
STRIKE			= \e[9m
RESET 			= \e[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(PURPLE)Make: $(NO_COLOR)Starting the compilation...\n"

SO_LONG_COMP	=	echo "\n🚧 $(YELLOW) $(NAME): $(NO_COLOR)Starting the compilation...\n"

SO_LONG_READY	=	echo "\n🧮 $(RED) $(NAME) $(NO_COLOR)ready!\n"

BONUS_READY	=	echo "\n🎯 Bonus: $(CYAN) $(BONUS_NAME) $(NO_COLOR)ready!\n"

CLEANED		=	echo "\n💧 $(GREEN)Clean: $(NO_COLOR)$(UNDERLINE)Removed$(RESET) all the \".o\" files 🗑\\n"

FCLEANED	=	echo "\n🧼 $(GREEN)Fclean: $(NO_COLOR)$(UNDERLINE)Removed$(RESET) the executables 🗑\\n"

NEW_LINE	=	echo "\n"

# ------------------------------ Rules ---------------------------------

all : $(NAME)

bonus : ${BONUS_NAME}

$(NAME):
	make -C $(LIB_PATH)
	cp $(LIB_PATH)/$(LIB_NAME) .
	@$(SO_LONG_COMP)
	make --no-print-directory -C $(MLX_PATH)
	cp $(MLX_PATH)/$(MLX_NAME) .
	$(GCC) -o $(NAME) $(SRC) $(MLX_FLAGS) -L. $(MLX_NAME) -L. $(LIB_NAME)
	@echo "$$ASCII_MANDATORY"
	@$(SO_LONG_READY)

${BONUS_NAME} : ${OBJS_BONUS}
	make -C $(LIB_PATH)
	cp $(LIB_PATH)/$(LIB_NAME) .
	make --no-print-directory -C $(MLX_PATH)
	cp $(MLX_PATH)/$(MLX_NAME) .
	$(GCC) -o $(BONUS_NAME) $(SRCS_BONUS) $(MLX_FLAGS)  -L. $(MLX_NAME) -L. $(LIB_NAME)
	@echo "$$ASCII_BONUS"
	@$(BONUS_READY)

clean :
	$(RM) *.o
	$(RM) *~
	$(RM) *#
	$(RM) $(BONUS_PATH)/src/*.o
	$(RM) $(BONUS_PATH)/*.o
	make -C $(LIB_PATH) clean
	make -C $(MLX_PATH) clean
	@$(CLEANED)

fclean : clean
	$(RM) $(NAME)
	make -C $(LIB_PATH) fclean
	$(RM) $(LIB_NAME)
	$(RM) $(BONUS_NAME)
	$(RM) $(MLX_NAME)
	@$(FCLEANED)

re : fclean all

coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'

# ------------------------------ Ascii ---------------------------------

info: ascii

define ASCII_MANDATORY
$(RED)                       ,         $(NO_COLOR)
$(RED)       ❤            .:/          $(NO_COLOR)
$(RED)         o      ,,///;,   ,;/    $(NO_COLOR)
$(RED)           o   o)::::::;;///     $(NO_COLOR)
$(RED)              >::::::::;;\\\     $(NO_COLOR)
$(RED)                ''\\\\\'" ';\    $(NO_COLOR)
$(RED)                   ';\           $(NO_COLOR)
endef
export ASCII_MANDATORY

define ASCII_BONUS
$(CYAN) o									$(NO_COLOR)
$(CYAN)o      ______/~/~/~/__           /((	$(NO_COLOR)
$(CYAN)  o  // __            ====__    /_((	$(NO_COLOR)
$(CYAN) o  //  @))       ))))      ===/__((	$(NO_COLOR)
$(CYAN)    ))           )))))))        __((	$(NO_COLOR)
$(CYAN)    \\     \)     ))))    __===\ _((	$(NO_COLOR)
$(CYAN)     \\_______________====      \_((	$(NO_COLOR)
$(CYAN)                                 \((	$(NO_COLOR)
endef
export ASCII_BONUS

.PHONY: all clean fclean re bonus coffee
