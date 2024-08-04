# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 03:25:21 by gicomlan          #+#    #+#              #
#    Updated: 2024/08/04 00:43:17 by gicomlan         ###   ########.fr        #
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
# 												(Directory for dependency files)
DEPS_DIR 				= dependencies/
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
ANIMATION_SUBDIR	 	= $(BONUS_PATH)animation/
CHECK_SUBDIR	 		= $(BONUS_PATH)check/
DISPLAY_SUBDIR 			= $(BONUS_PATH)display/
GAMEPLAY_SUBDIR 		= $(BONUS_PATH)gameplay/
INIT_SUBDIR 			= $(BONUS_PATH)init/
LOAD_SUBDIR 			= $(BONUS_PATH)load/
PARSING_SUBDIR 			= $(BONUS_PATH)parsing/
PRINTING_SUBDIR 		= $(BONUS_PATH)printing/
CAMERA_SUBDIR 			= $(BONUS_PATH)camera/
DEBUG_SUBDIR 			= $(BONUS_PATH)debug/
FREE_SUBDIR 			= $(BONUS_PATH)free/
HUD_SUBDIR 				= $(BONUS_PATH)hud/
INPUT_SUBDIR 			= $(BONUS_PATH)input/
MLX_SUBDIR 				= $(BONUS_PATH)mlx/
PATH_FOUNDING_SUBDIR 	= $(BONUS_PATH)path-founding/
UPDATE_SUBDIR 			= $(BONUS_PATH)update/
# ------------------------------------------------------------------ [ SOURCES ]
# 															  (Mandatory sources)
MANDATORY_SRCS_FILES 	+= $(MANDATORY_PATH)check_map_finishable.c
MANDATORY_SRCS_FILES 	+= $(MANDATORY_PATH)ft_utils_map_finishable.c
MANDATORY_SRCS_FILES 	+= $(MANDATORY_PATH)so_long_linux.c
MANDATORY_SRCS_FILES 	+= $(MANDATORY_PATH)check_map_format_linux.c
MANDATORY_SRCS_FILES 	+= $(MANDATORY_PATH)input_linux.c
MANDATORY_SRCS_FILES 	+= $(MANDATORY_PATH)sprite_linux.c
MANDATORY_SRCS_FILES 	+= $(MANDATORY_PATH)ft_debug.c
MANDATORY_SRCS_FILES 	+= $(MANDATORY_PATH)map_linux.c
MANDATORY_SRCS_FILES 	+= $(MANDATORY_PATH)tools_linux.c
MANDATORY_SRCS_FILES	+= $(MANDATORY_DIR)main.c
# 																  (Bonus sources)
BONUS_SRCS_FILES		+= $(ANIMATION_SUBDIR)ft_animation_bonus.c
BONUS_SRCS_FILES		+= $(ANIMATION_SUBDIR)ft_animation_digits_bonus.c
BONUS_SRCS_FILES		+= $(ANIMATION_SUBDIR)ft_animation_player_bonus.c
BONUS_SRCS_FILES		+= $(ANIMATION_SUBDIR)ft_animation_utils.c
BONUS_SRCS_FILES		+= $(ANIMATION_SUBDIR)ft_animation_world_bonus.c
BONUS_SRCS_FILES		+= $(CAMERA_SUBDIR)ft_camera_bonus.c
BONUS_SRCS_FILES		+= $(CHECK_SUBDIR)ft_check_bonus.c
BONUS_SRCS_FILES		+= $(CHECK_SUBDIR)ft_check_utils_bonus.c
BONUS_SRCS_FILES		+= $(DEBUG_SUBDIR)ft_debug_bonus.c
BONUS_SRCS_FILES		+= $(DEBUG_SUBDIR)ft_debug_utils_one.c
BONUS_SRCS_FILES		+= $(DISPLAY_SUBDIR)ft_display_assets_bonus.c
BONUS_SRCS_FILES		+= $(DISPLAY_SUBDIR)ft_display_assets_utils_bonus.c
BONUS_SRCS_FILES		+= $(FREE_SUBDIR)ft_free_bonus.c
BONUS_SRCS_FILES		+= $(FREE_SUBDIR)ft_free_parsing_bonus.c
BONUS_SRCS_FILES		+= $(GAMEPLAY_SUBDIR)ft_lava_behaviour_bonus.c
BONUS_SRCS_FILES		+= $(GAMEPLAY_SUBDIR)ft_lava_event_bonus.c
BONUS_SRCS_FILES		+= $(GAMEPLAY_SUBDIR)ft_lava_movement.c
BONUS_SRCS_FILES		+= $(GAMEPLAY_SUBDIR)ft_player_behaviour_bonus.c
BONUS_SRCS_FILES		+= $(GAMEPLAY_SUBDIR)ft_player_event_bonus.c
BONUS_SRCS_FILES		+= $(HUD_SUBDIR)ft_hud_bonus.c
BONUS_SRCS_FILES		+= $(INIT_SUBDIR)ft_init_bonus.c
BONUS_SRCS_FILES		+= $(INIT_SUBDIR)ft_init_map_bonus.c
BONUS_SRCS_FILES		+= $(INIT_SUBDIR)ft_init_mlx_bonus.c
BONUS_SRCS_FILES		+= $(INIT_SUBDIR)ft_init_so_long_bonus.c
BONUS_SRCS_FILES		+= $(INPUT_SUBDIR)ft_input_player_bonus.c
BONUS_SRCS_FILES		+= $(INPUT_SUBDIR)ft_input_utils_bonus.c
BONUS_SRCS_FILES		+= $(LOAD_SUBDIR)ft_load_assets_bonus.c
BONUS_SRCS_FILES		+= $(LOAD_SUBDIR)ft_load_digits_assets_bonus.c
BONUS_SRCS_FILES		+= $(LOAD_SUBDIR)ft_load_door_assets_bonus.c
BONUS_SRCS_FILES		+= $(LOAD_SUBDIR)ft_load_even_digts_assets_bonus.c
BONUS_SRCS_FILES		+= $(LOAD_SUBDIR)ft_load_gameplay_assets_bonus.c
BONUS_SRCS_FILES		+= $(LOAD_SUBDIR)ft_load_gameplay_portal_assets_bonus.c
BONUS_SRCS_FILES		+= $(LOAD_SUBDIR)ft_load_odd_digts_assets_bonus.c
BONUS_SRCS_FILES		+= $(LOAD_SUBDIR)ft_load_player_assets_bonus.c
BONUS_SRCS_FILES		+= $(LOAD_SUBDIR)ft_load_portals_assets_bonus.c
BONUS_SRCS_FILES		+= $(LOAD_SUBDIR)ft_load_world_assets_bonus.c
BONUS_SRCS_FILES		+= $(MLX_SUBDIR)ft_mlx_hook_loop_bonus.c
BONUS_SRCS_FILES		+= $(PARSING_SUBDIR)ft_parsing_bonus.c
BONUS_SRCS_FILES		+= $(PARSING_SUBDIR)ft_parsing_border_map_bonus.c
BONUS_SRCS_FILES		+= $(PARSING_SUBDIR)ft_parsing_utils_bonus.c
BONUS_SRCS_FILES		+= $(PATH_FOUNDING_SUBDIR)ft_path_founding_bonus.c
BONUS_SRCS_FILES		+= $(PATH_FOUNDING_SUBDIR)ft_path_founding_utils_bonus.c
BONUS_SRCS_FILES		+= $(PRINTING_SUBDIR)ft_print_bonus.c
BONUS_SRCS_FILES		+= $(PRINTING_SUBDIR)ft_print_console_bonus.c
BONUS_SRCS_FILES		+= $(UPDATE_SUBDIR)ft_update_bonus.c
BONUS_SRCS_FILES		+= $(BONUS_DIR)main.c
# -------------------------------------------------------------------------- []
# 							   (Calculation of the total number of source files)
#TOTAL_SRCS_FILES 	:= $(words $(BONUS_SRCS_FILES))----------------------------
# 										            (Full paths to source files)
# Fichiers objets correspondants
OBJS_BONUS				= $(patsubst ${BONUS_SRCS_FILES}%.c,$(OBJS_DIR)%.o,$(BONUS_SRCS_FILES))
OBJS_MANDATORY			= $(patsubst ${MANDATORY_SRCS_FILES}%.c,$(OBJS_DIR)%.o,$(MANDATORY_SRCS_FILES))
# Dépendances
DEP_BONUS				= $(patsubst %.c,$(DEPS_DIR)%.d,$(BONUS_SRCS_FILES))
DEPS_MANDATORY			= $(patsubst %.c,$(DEPS_DIR)%.d,$(MANDATORY_SRCS_FILES))
# ----------------------------------------------------------- ---------- [VPATH]
# 																  (virtual path)
vpath %.c $(BONUS_PATH)$(MANDATORY_PATH)
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
#CFLAGS 				+= -MMD
CFLAGS 					+= -I $(INCLUDES_DIR)
#CFLAGS 				+= -lbsd
#CFLAGS 				+= -fsanitize=address
#CFLAGS 				+= -fsanitize=undefined
#CFLAGS 					+= -MP -MF $(DEPS_DIR)/$*.define
#CFLAGS 				+= -MP
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
bonus : ${BONUS_NAME}
# 									(Compilation of object files into a library)
$(MANDATORY_NAME) : $(OBJS_MANDATORY)
	$(MAKE) -C $(MINI_LIB_PATH)
	$(COPY) $(MINI_LIB_PATH)/$(LIB_SO_LONG_NAME) .
	@$(SO_LONG_COMP)
	$(MAKE) --no-print-directory -C $(MLX_PATH)
	$(COPY) $(MLX_PATH)/$(MLX_NAME) .
	$(CC) $(CFLAGS) -o $(MANDATORY_NAME) $(MANDATORY_SRCS_FILES) $(MLX_FLAGS) -L. $(MLX_NAME) -L. $(LIB_SO_LONG_NAME)
	@echo "$$ASCII_MANDATORY"
	@$(SO_LONG_READY)

${BONUS_NAME} : ${OBJS_BONUS}
	$(MAKE) -C $(MINI_LIB_PATH)
	$(COPY) $(MINI_LIB_PATH)$(LIB_SO_LONG_NAME) .
	$(MAKE) --no-print-directory -C $(MLX_PATH)
	$(COPY) $(MLX_PATH)/$(MLX_NAME) .
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_SRCS_FILES) $(MLX_FLAGS)  -L. $(MLX_NAME) -L. $(LIB_SO_LONG_NAME)
	@echo "$$ASCII_BONUS"
	@$(BONUS_READY)
# 							   (Rule for creating object files and dependencies)

$(OBJS_DIR) $(DEPS_DIR) :
	@$(MKDIR) $(MKDIRFLAGS) $(OBJS_DIR)$(MANDATORY_PATH)
	@$(MKDIR) $(MKDIRFLAGS) $(OBJS_DIR)$(BONUS_PATH)


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
-include $(DEPS_DIR)
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
