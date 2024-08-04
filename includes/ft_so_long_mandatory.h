/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_mandatory.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:32:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 00:59:06 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_LINUX_H
# define SO_LONG_LINUX_H

# include "../libraries/ft_printf/ft_printf.h"
# include "../libraries/get_next_line/get_next_line.h"
# include "../libraries/mini-libft/libft.h"
# include "../libraries/mlx/mlx.h"

# define BER_EXTENSION ".ber"
# define ERROR_MSG "Error\n"
# define GAME_TITLE "./so_long"
# define USAGE_MSG "./so_long [pass to map][map name].ber\n"
# define NO_ENV_ERROR "No variable environment available\n"
# define NO_DISP_ERROR "DISPLAY not found in env\n"
# define MALLOC_GAME_ERROR "Malloc t_game fail\n"
# define BAD_CHAR_MAP_ERROR "Map Should contain char : '1' 'P' 'C' 'E' '0'\n"
# define WALL_ERROR ".ber should be surrounded by walls : 1\n"
# define FORM_ERROR ".ber should be in rectangular form !\n"
# define COIN_ERROR ".ber should have at least one collectible -> C\n"
# define PLAYER_ERROR ".ber should have one starting point -> P\n"
# define EXIT_ERROR ".ber should have at east one exit -> E\n"
# define EXTENSION_ERROR "Map extension should be a .ber\n"
# define FAIL_OPEN_ERROR ".ber fail to open\n"
# define MLX_INIT_ERROR "mlx_init() fail\n"
# define MLX_WINDOW_ERROR "mlx_new_window() fail\n"
# define PLAYER_XPM_ERROR "player.xpm fail to load\n"
# define GROUND_XPM_ERROR "ground.xpm fail to load\n"
# define WALL_XPM_ERROR "wall.xpm fail to load\n"
# define KEY_XPM_ERROR "key.xpm fail to load\n"
# define EXIT_XPM_ERROR "exit.xpm fail to load\n"
# define SPLIT_MAP_ERROR "Malloc grid for path finding fail\n"
# define PATH_MAP_ERROR "No Valid Path Found in map\n"
# define COIN_MAP_ERROR "Not All coin are collectible in map\n"
# define WIN_MSG "Thanks for playing, you win with steps : "
# define EMPTY_LINE "Remove that empty line at the top or middle\n"
# define MAP_TOO_BIG "Reduce map size, map too big for the screen\n"

typedef enum e_key_code		t_key_code;
typedef enum e_map_char		t_map_char;
typedef enum e_bool			t_bool;
typedef struct s_point		t_point;
typedef struct s_sprites	t_sprites;
typedef struct s_game		t_game;

enum						e_key_code
{
	CLOSE_ICON = 17,
	ESC_KEY = 65307,
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	UP_ARROW_KEY = 65362,
	DOWN_ARROW_KEY = 65364,
	LEFT_ARROW_KEY = 65361,
	RIGHT_ARROW_KEY = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
};

enum						e_map_char
{
	WALL_CHAR = '1',
	PLAYER_CHAR = 'P',
	COIN_CHAR = 'C',
	EXIT_CHAR = 'E',
	VOID_CHAR = '0'
};

// true false enum for loop if etc
enum						e_bool
{
	TRUE = 1,
	FALSE = 0
};

// point in char **
struct						s_point
{
	int						x;
	int						y;
};

// sprite struct
struct						s_sprites
{
	void					*player;
	void					*ground;
	void					*wall;
	void					*key;
	void					*exit;
};

// game struct
typedef struct s_game
{
	t_sprites				sprite;
	long long int			step;
	long long int			nbr_love;
	void					*mlx;
	void					*win;
	char					*map;
	long long int			map_len;
	long long int			width;
	long long int			height;
	long long int			key;
	long long int			storage;
	long long int			exit;
	long long int			player;
	long long int			empty_line;
}							t_game;

//main_linux

void						ft_map_fit_screen(t_game *game);

void						ft_free_all(t_game *game);

//../src_linux/check_map_format_linux.c

int							get_map_height(char *map_name, t_game *game);
void						check_ber_format(char *map_name, int height,
								t_game *game);
void						ft_init_map_info(t_game *game, char *line);

//../src_linux/check_map_finishable.c

void						ft_get_number_collectible(t_game *game);
t_point						ft_find_pos_char(char **tab, t_point size, char c);
t_bool						ft_path_exists(char **tab, t_point size,
								t_point start, t_point end);
t_bool						ft_path_founding(char **tab, t_point size,
								t_point cur, t_point end);
void						ft_get_all_collectable(char **tab, t_game *game,
								t_point start, int *coins);

//../src_linux/ft_utils_map_finishable.c

void						ft_check_map_finishable(t_game *game);
char						**ft_split_map(t_game *game);
void						ft_clean_fail_malloc_split_map(t_game *game,
								char **grid, int row);
void						ft_clean_grid_map(char **grid, int row);
void						ft_free_and_print(char **map, t_game *game,
								char *str);

//../src_linux/ft_debug.c

void						ft_check_path_founding(char **map);
void						ft_print_display_grid(char **res);
void						ft_display_start_end(t_point start, t_point end);

//../src_linux/input_linux.c

int							ft_input_manager(int key, t_game *game);
void						ft_move_up(t_game *game);
void						ft_move_down(t_game *game);
void						ft_move_left(t_game *game);
void						ft_move_right(t_game *game);

//../src_linux/map_linux.c

void						ft_read_map(t_game *game, char *map_name);
void						ft_check_map(t_game *game);
void						ft_check_sealed(t_game *game);
void						ft_check_rectangular(t_game *game);
void						ft_check_playability(t_game *game);
void						ft_get_number_collectible(t_game *game);

//../src_linux/so_long_linux.c

void						ft_init_game(t_game *game, char *map_name);
int							ft_exit_game(t_game *game);
int							ft_win_game(t_game *game);
void						ft_print_error(char *error_msg, t_game *game);
void						ft_check_valid_char(t_game *game);

//../src_linux/sprite_linux.c

t_sprites					ft_init_sprites(void *mlx, t_game *game);
void						ft_put_sprites_by_line(t_game *game);
void						ft_put_all_sprites_to_line(t_game *game, int width,
								int height);

//../src_linux/tools_linux.c

char						*ft_custom_strdup(char *s1);
int							ft_custom_strlcpy(char *dst, char *src,
								int dst_size);
char						*ft_custom_strjoin(char *s1, char *s2);
void						ft_check_env(char **env);
int							ft_check_extension(char *map_name, char *extension);

#endif
