# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 03:25:21 by gicomlan          #+#    #+#              #
#    Updated: 2024/08/06 09:52:46 by gicomlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#‧₊˚✩ {  } •. 。　.
# 																  (Library name)
MANDATORY_NAME			= so_long
BONUS_NAME				= so_long_bonus
LIB_SO_LONG_NAME		= lib_so_long.a
MLX_NAME				= libmlx.a
# ---------------------------------------------------------------- [ DIRECTORY ]
#												 (Directory for inclusion files)
INCLUDES_DIR			= includes/
# 													(Directory for object files)
OBJS_DIR				= objects/
MANDATORY_OBJS_DIR      = $(OBJS_DIR)mandatory/sources/
BONUS_OBJS_DIR          = $(OBJS_DIR)bonus/sources/
# 												(Directory for dependency files)
DEPS_DIR 				= dependencies/
MANDATORY_DEPS_DIR 		= $(DEPS_DIR)mandatory/sources/
BONUS_DEPS_DIR			= $(DEPS_DIR)bonus/sources/
# 											   	   (Directory for sources files)
SRCS_DIR				= sources/
MANDATORY_DIR			= mandatory/
BONUS_DIR				= bonus/
MANDATORY_PATH 			= $(MANDATORY_DIR)$(SRCS_DIR)
BONUS_PATH	 			= $(BONUS_DIR)$(SRCS_DIR)
# 														 	   	  (Paths to lib)
LIBS_DIR				= libraries/
MINI_LIB_DIR			= mini-libft/
MLX_DIR					= mlx/
MLX_PATH				= $(LIBS_DIR)$(MLX_DIR)
MINI_LIB_PATH			= $(LIBS_DIR)$(MINI_LIB_DIR)
# 									     	   	  (Paths to subdir sources files)
BONUS_SUBDIRS			+= animation
BONUS_SUBDIRS			+= check
BONUS_SUBDIRS			+= display
BONUS_SUBDIRS			+= gameplay
BONUS_SUBDIRS			+= init
BONUS_SUBDIRS			+= load
BONUS_SUBDIRS			+= parsing
BONUS_SUBDIRS			+= printing
BONUS_SUBDIRS			+= camera
BONUS_SUBDIRS			+= debug
BONUS_SUBDIRS			+= free
BONUS_SUBDIRS			+= hud
BONUS_SUBDIRS			+= input
BONUS_SUBDIRS			+= mlx
BONUS_SUBDIRS			+= path-founding
BONUS_SUBDIRS			+= update

# -------------------------------------------------------------------------- []
# 							   (Calculation of the total number of source files)
#TOTAL_SRCS_FILES 	:= $(words $(BONUS_SRCS_FILES))----------------------------
# 										            (Full paths to source files)
# Fichiers objets correspondants
MANDATORY_SRCS_FILES	+= $(shell find $(MANDATORY_PATH) -name '*.c')
BONUS_SRCS_FILES		= $(foreach dir,$(BONUS_SUBDIRS),$(shell find $(BONUS_PATH)$(dir) -name '*.c'))
# ---------------------------------------------------------------- [ OBJECTS ]
OBJS_MANDATORY			= $(patsubst $(MANDATORY_PATH)%.c,$(MANDATORY_OBJS_DIR)%.o,$(MANDATORY_SRCS_FILES))
OBJS_BONUS				= $(patsubst $(BONUS_PATH)%.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS_FILES))

# ---------------------------------------------------------------- [ DEPENDENCIES ]
DEPS_BONUS				= $(patsubst $(BONUS_PATH)%.c,$(BONUS_DEPS_DIR)%.d,$(BONUS_SRCS_FILES))
DEPS_MANDATORY			= $(patsubst $(MANDATORY_PATH)%.c,$(MANDATORY_DEPS_DIR)%.d,$(MANDATORY_SRCS_FILES))
# ----------------------------------------------------------- ---------- [VPATH]
# 																  (virtual path)
vpath %.c $(MANDATORY_DIR)$(BONUS_DIR)
vpath %.o $(OBJS_DIR)
vpath %.d $(DEPS_DIR)
vpath %.h $(INCLUDES_DIR)
# ============================================================== [ COMPILATION ]
# 					   (Definition of variables and flags for compilation tools)
CC						:= cc
CFLAGS 					+= -Werror
CFLAGS 					+= -Wextra
CFLAGS 					+= -Wall
#CFLAGS 				+= -fPIE
#CFLAGS 					+= -MMD
#CFLAGS 					+= -g
CFLAGS 					+= -I $(INCLUDES_DIR)
#CFLAGS 				+= -lbsd
#CFLAGS 				+= -fsanitize=address
#CFLAGS 				+= -fsanitize=undefined
#CFLAGS 					+= -MP -MF $(DEPS_DIR)/$*.define
#CFLAGS 					+= -MP
MLX_FLAGS				+= -L $(MLX_PATH)
MLX_FLAGS				+= -lmlx
MLX_FLAGS				+= -lXext
MLX_FLAGS				+= -lX11
MLX_FLAGS				+= -lm
MLX_FLAGS				+= -lz
# ------------------------------------------ [ Patterns of files to be removed ]
# ------------------------------------------- (Temporary,Objs,dependency files)
USELESS_FILES 			:= *~ *\# *.o *.d
DEPS_FILES				= $(DIR_DEPS)/*.d
# ----------------------------------------------------- (Defautl gcc executable)
ASSEMBLER_OUTPUT		:= a.out
# ==================================================================== [ TOOLS ]
# 								   		  (Tool for creating the static library)
ARFLAGS 				= rcs
# 														(Tool for file deletion)
RM						:= /bin/rm
RMFLAGS					:= -f
RMFLAGS					+= -r
# 												   (Tool for directory creation)
# Outil pour la création de répertoires
COPY					:= /bin/cp
MKDIR					:= mkdir
MKDIRFLAGS				:= -p
NULL_FILE				:= /dev/null
# =================================================================== [ COLORS ]
# 														   (Colors for messages)
BLACK					=	\e[0;30m
RED						=	\e[0;31m
GREEN					=	\e[0;32m
ORANGE					=	\e[0;33m
BLUE					=	\e[0;34m
PURPLE					=	\e[0;35m
CYAN					=	\e[0;36m
LIGHT_GRAY				=	\e[0;37m
DARK_GRAY				=	\e[1;30m
LIGHT_RED				=	\e[1;31m
LIGHT_GREEN				=	\e[1;32m
YELLOW					=	\e[1;33m
LIGHT_BLUE				=	\e[1;34m
LIGHT_PURPLE			=	\e[1;35m
LIGHT_CYAN				=	\e[1;36m
WHITE					=	\e[1;37m
NO_COLOR				=	\e[0m
# =================================================================== [  ANSI  ]
# 		en angalis	 (Définir les séquences d'échappement ANSI)
BOLD 					= \e[1m
DIM 					= \e[2m
ITALIC					= \e[3m
UNDERLINE 				= \e[4m
BLINK					= \e[5m
REVERSE					= \e[7m
HIDDEN					= \e[8m
STRIKE					= \e[9m
RESET 					= \e[0m
# ================================================================= [ Messages ]
#												 (Colored display + emoji etc..)
COMP_START				=	echo "\n🚧 $(PURPLE)Make: $(NO_COLOR)Starting the compilation...\n"
SO_LONG_COMP			=	echo "\n🚧 $(YELLOW) $(NAME): $(NO_COLOR)Starting the compilation...\n"
SO_LONG_READY			=	echo "\n🧮 $(RED) $(NAME) $(NO_COLOR)ready!\n"
BONUS_READY				=	echo "\n🎯 Bonus: $(CYAN) $(BONUS_NAME) $(NO_COLOR)ready!\n"
CLEANED					=	echo "\n💧 $(GREEN)Clean: $(NO_COLOR)$(UNDERLINE)Removed$(RESET) all the \".o\" files 🗑\\n"
FCLEANED				=	echo "\n🧼 $(GREEN)Fclean: $(NO_COLOR)$(UNDERLINE)Removed$(RESET) the executables 🗑\\n"
NEW_LINE				=	echo "\n"
# ==================================================================== [ Rules ]
# 										  (Default rule for library compilation)
all : $(MANDATORY_NAME)
bonus : $(BONUS_NAME)
# 									(Compilation of object files into a library)
$(MANDATORY_NAME) : $(OBJS_MANDATORY)
	$(MAKE) -C $(MINI_LIB_PATH)
	$(COPY) $(MINI_LIB_PATH)$(LIB_SO_LONG_NAME) .
	@$(SO_LONG_COMP)
	$(MAKE) --no-print-directory -C $(MLX_PATH)
	$(COPY) $(MLX_PATH)$(MLX_NAME) .
	$(CC) $(CFLAGS) -o $(MANDATORY_NAME) $(OBJS_MANDATORY) mandatory/main.c $(MLX_FLAGS) -L. $(MLX_NAME) -L. $(LIB_SO_LONG_NAME)
	@echo "$$ASCII_MANDATORY"
	@$(SO_LONG_READY)

$(BONUS_NAME) : $(OBJS_BONUS)
	$(MAKE) -C $(MINI_LIB_PATH)
	$(COPY) $(MINI_LIB_PATH)$(LIB_SO_LONG_NAME) .
	$(MAKE) --no-print-directory -C $(MLX_PATH)
	$(COPY) $(MLX_PATH)$(MLX_NAME) .
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) bonus/main.c $(MLX_FLAGS) -L. $(MLX_NAME) -L. $(LIB_SO_LONG_NAME)
	@echo "$$ASCII_BONUS"
	@$(BONUS_READY)
# 							   (Rule for creating object files and dependencies)

$(MANDATORY_OBJS_DIR)%.o: $(MANDATORY_PATH)%.c
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(MANDATORY_DEPS_DIR)$(patsubst $(MANDATORY_PATH)%,%,$(dir $<)))
	$(CC) $(CFLAGS) -MMD -c -I $(INCLUDES_DIR) -MP $< -o $@ -MF $(MANDATORY_DEPS_DIR)$(patsubst $(MANDATORY_PATH)%,%,$(dir $<))/$*.d

$(BONUS_OBJS_DIR)%.o: $(BONUS_PATH)%.c
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(BONUS_DEPS_DIR)$(patsubst $(BONUS_PATH)%,%,$(dir $<)))
	$(CC) $(CFLAGS) -MMD -c -I $(INCLUDES_DIR) -MP $< -o $@ -MF $(BONUS_DEPS_DIR)$(patsubst $(BONUS_PATH)%,%,$(dir $<))/$*.d

clean :
	$(RM) $(RMFLAGS) $(OBJS_DIR) > $(NULL_FILE)
	$(RM) $(RMFLAGS) $(DEPS_DIR) > $(NULL_FILE)
	$(MAKE) -C $(MINI_LIB_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	@$(CLEANED)
# 													(Rule for complete cleaning)
fclean : clean
	$(RM) $(RMFLAGS) $(MANDATORY_NAME) > $(NULL_FILE)
	$(RM) $(RMFLAGS) $(BONUS_NAME) > $(NULL_FILE)
	$(RM) $(RMFLAGS) $(LIB_SO_LONG_NAME) > $(NULL_FILE)
	$(RM) $(RMFLAGS) $(MLX_NAME) > $(NULL_FILE)
	$(MAKE) -C $(MINI_LIB_PATH) fclean
	@$(FCLEANED)

# 												(Rule for rebuilding everything)
re : fclean all

debug_make:
	@echo "MANDATORY_PATH = $(MANDATORY_PATH)"
	@echo "MANDATORY_SRCS_FILES = $(MANDATORY_SRCS_FILES)"

# 								(Rule for checking compliance with the standard)
define HELP_MSG
Usage: make [TARGET]
                all         - Build the main program
                clean       - Remove object file(s)
                fclean      - Remove object file(s) and binary file(s)
                re          - Rebuild the program
                bonus       - Build the bonus part of the program
                norm        - Run norminette checks
                debug       - Activate debug flags
                help        - Display this help message
endef
export HELP_MSG
norm :
	@ALL_NORM_CHECK=0; \
	for cmd in $(NORM_SRC) $(NORM_HEAD) $(NORM_DEFINE); do \
		if ! eval $$cmd 2>&1; then \
			ALL_NORM_CHECK=1; \
			$(NORM_KO); \
		else \
			$(NORM_OK); \
		fi; \
	done; \
	if [ $$ALL_NORM_CHECK -eq 0 ]; then \
		$(GLOBAL_NORM_OK); \
	else \
		$(GLOBAL_NORM_KO); \
	fi
# ============================================================= [ PROGRESS BAR ]
# 									  (Function to display compilation progress)
define progress_bar
    @$(eval COMPILED_SRCS_FILES := $(shell expr $(COMPILED_SRCS_FILES) + 1))
    @printf "⚙️  "
    @$(eval PROGRESS := $(shell expr $(COMPILED_SRCS_FILES) \* $(PROGRESS_BAR_SIZE) / $(TOTAL_SRCS_FILES)))
    @$(eval REMAINING := $(shell expr $(PROGRESS_BAR_SIZE) - $(PROGRESS)))
    @printf "$(RED)%$(PROGRESS)s$(NO_COLOR)" | sed 's/ /$(PROGRESS_UNICODE)/g'
    @printf "$(BLUE)%$(REMAINING)s$(NO_COLOR)" | sed 's/ /$(REMAINING_UNICODE)/g'
    @printf " (%.2f%%) [%d/%d] %s" \
        $(shell echo "scale=2; $(COMPILED_SRCS_FILES)/$(TOTAL_SRCS_FILES) * 100" | bc) \
        $(COMPILED_SRCS_FILES) $(TOTAL_SRCS_FILES) $(notdir $<)
    @printf "\033[0K\r"
endef
# =============================================================== [ DEPENDENCY ]
# 													(Including dependency files)
-include $(DEPS_MANDATORY)
-include $(DEPS_BONUS)
# ==================================================================== [ ASCII ]
# 							 (Ascii are to diplay at the end of the compilation)
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
# ==================================================================== [ ASCII ]
# 							 (Ascii are to diplay at the end of the compilation)
info: ascii

define ASCII_MANDATORY
$(RED)       								$(NO_COLOR)
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
.SILENT: re
# ‧₊˚✩ { E̶̩̹̽ṉ̸̂d̷̰̫̉͊ ̷̖̀Ọ̴͆͝f̴͎̒ ̸̡͈̀̊M̵̞͘a̷͓̞͂͝ḳ̶̚é̴̹̈f̸̞̟̀́i̵̤͆l̷͔̐ḛ̵̥̎̓  •. 。　.
