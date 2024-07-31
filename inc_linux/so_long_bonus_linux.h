/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_linux.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:31:55 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/31 19:01:59 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_LINUX_H
# define SO_LONG_BONUS_LINUX_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"
# include "../lib/small_lib/libft.h"
# include "../mlx_linux/mlx.h"
# include "so_long_define_bonus_linux.h"
# include <math.h>
# include <time.h>

typedef enum e_key_code_linux
{
	LINUX_CLOSE_ICON = 17,
	LINUX_ESC_KEY = 65307,
	LINUX_KEY_PRESS = 2,
	LINUX_KEY_RELEASE = 3,
	LINUX_W_KEY = 119,
	LINUX_A_KEY = 97,
	LINUX_S_KEY = 115,
	LINUX_D_KEY = 100,
	LINUX_UP_ARROW_KEY = 65362,
	LINUX_DOWN_ARROW_KEY = 65364,
	LINUX_LEFT_ARROW_KEY = 65361,
	LINUX_RIGHT_ARROW_KEY = 65363,
	LINUX_UP_PAV_NUM_KEY = 65431,
	LINUX_DOWN_PAV_NUM_KEY = 65433,
	LINUX_LEFT_PAV_NUM_KEY = 65430,
	LINUX_RIGHT_PAV_NUM_KEY = 65432
}					t_key_code_linux;

// lol read le scp-10
//http://fondationscp.wikidot.com/scp-010

typedef enum e_map_char
{
	LAVA_CHAR = 'L',
	EXIT_CHAR = 'E',
	LOVE_CHAR = 'S',
	KEY_CHAR = 'C',
	PLAYER_CHAR = 'P',
	WALL_CHAR = '1',
	VOID_CHAR = '0',
	BORDER_CHAR = 'B',
	VISITED_CHAR = 'V'
}					t_map_char;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}					t_bool;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_fps
{
	struct timespec	last_time;
	struct timespec	current_time;
	int				frame_count;
	double			fps;
	double			elapsed;
}					t_fps;

typedef struct s_animation
{
	int				frames;
	void			*current;
	void			*frame_0;
	void			*frame_1;
	void			*frame_2;
}					t_animation;
typedef struct s_lava
{
	t_animation		animation;
	char			move;
}					t_lava;

typedef struct s_key
{
	t_animation		animation;
}					t_key;

typedef struct s_grass
{
	t_animation		animation;
}					t_grass;

typedef struct s_wall
{
	t_animation		animation;
}					t_wall;

typedef struct s_anim_door
{
	int				frames;
	void			*current;
	void			*frame_0;
	void			*frame_1;
	void			*frame_2;
}					t_anim_door;

typedef struct s_door
{
	//int				frames;
	t_anim_door		closed;
	t_anim_door		open;
}					t_door;

typedef struct s_love
{
	t_animation		animation;
	void			*nope;
	void			*icon;
}					t_love;
typedef struct s_anim_player
{
	void			*current;
	void			*frame_0;
	void			*frame_1;
	void			*frame_2;
	void			*frame_move;
}					t_anim_player;

// typedef struct s_point_visual
// {
// 	float x;
//     float y;
// } t_point_visual;

typedef struct s_movement
{
	//t_point_visual	visual;
	t_point			current_position;
	t_point			target_position;
	t_bool			moved;
	char			direction;
	//float			speed;
}					t_movement;

typedef struct s_player
{
	t_anim_player	up_anim;
	t_anim_player	down_anim;
	t_anim_player	left_anim;
	t_anim_player	right_anim;
	//t_point			position;
	t_movement		movement;
	// t_point			target_position;
	// float			speed;
	//t_movement	movement
	//t_bool			moved;
	int				frames;
	long long int	life;
	long long int	storage;
	long long int	step;
	//char			direction;
	// double			x_speed;
	// double			y_speed;
}					t_player;

typedef struct s_info
{
	long long int	nbr_key;
	long long int	nbr_exit;
	long long int	nbr_player;
	long long int	nbr_lava;
	long long int	nbr_love;
	long long int	nbr_wall;
	long long int	nbr_void;
}					t_info;

typedef struct s_map
{
	t_point			size;
	t_point			start;
	t_point			end;
	t_info			info;
	char			*map_str;
	char			**matrice;
	char			**grid;
	void			*ground;
	//void			*grass;
	//void			*borders;
	long long int	len;
	// long long int	nbr_key;
	// long long int	nbr_exit;
	// long long int	nbr_player;
	// long long int	nbr_lava;
	// long long int	nbr_love;
	// long long int	nbr_wall;
	// long long int	nbr_void;
	long long int	border_width;
}					t_map;

typedef struct s_window
{
	int				bpp;
	int				size_line;
	int				endian;
	void			*img;
	char			*img_data;
	int				width;
	int				height;
}					t_window;

typedef	struct s_digits
{
	void			*tab[10];
	t_animation		zero;
	t_animation		one;
	t_animation		two;
	t_animation		tree;
	t_animation		four;
	t_animation		five;
	t_animation		six;
	t_animation		seven;
	t_animation		eight;
	t_animation		nine;
} t_digits;

typedef struct s_hud
{
	char			*str_step;
	char			*str_storage;
	char			*str_fps;
	char			*str_key_remain;
	//int				frame;
	t_digits		digits;
	t_point			fps;
	t_point			step;
	t_point			direction;
	t_point			keys;
	t_point			storage;
}					t_hud;

typedef struct s_camera
{
	t_point 		current; // faire une struct camera
	t_point			target;
	double			shake_intensity;
	double			shake_speed;
	double			lerp_speed;
	//float			zoom_factor;
}					t_camera;
typedef struct s_game
{
	t_player		player;
	t_love			love;
	t_map			map;
	t_lava			lava;
	t_key			key;
	t_wall			wall;
	t_grass			grass;
	t_door			door;
	t_camera		camera;
	// t_point			camera;// faire une struct camera
	// t_point			camera_target;
	t_fps			fps;
	t_window		window;
	t_hud			hud;
	void			*mlx;
	void			*win;
	t_bool			finished;
	//void			*img;
	//char			*img_data;
	// char			*str_step;
	// char			*str_storage;
	// char			*str_fps;
	// float 			distance_camera;
	// float			zoom_factor;
	// double			last_time;
	long long int width;      //useleep try to make a map very big;
	long long int height;     //useleep
	long long int empty_line; //mettre dans map information
}					t_game;

//../src/bonus/main.c

void				ft_moving_lava(t_game *game);
void				ft_render(t_game *game);
int					ft_update(t_game *game);
void				ft_print_info_on_window(t_game *game);
void				ft_init_player_info(t_game *game);
void				ft_update_camera(t_game *game);
void				ft_double_buffering(t_game *game);
void				ft_draw_frame(t_game *game);
//../src/bonus/animation_bonus.c

void				ft_wall_animation(t_animation *animation);
void				ft_lava_animation(t_animation *animation);
void				ft_key_animation(t_animation *animation);
void				ft_door_open_animation(t_anim_door *animation);
void				ft_door_closed_animation(t_anim_door *animation);
//void				ft_door_animation(t_door *door);
void				ft_love_animation(t_animation *animation);
void				ft_grass_animation(t_animation *animation);
//../src/bonus/ft_debug.c

void				ft_print_fill_grid(char **map);
void				ft_print_display_grid(char **res);
void				ft_display_start_end(t_point start, t_point end);
void				ft_secure_usleep(int microseconds);
//../src/bonus/check_map_format.c

int					get_map_height(char *map_name, t_game *game);
void				check_ber_format(char *map_name, int height, t_game *game);
void				ft_init_map_info(t_game *game, char *line);
void				ft_check_rectangular(t_game *game);

//../src/bonus/check_map_finishable.c

t_point				ft_find_pos_char(char **tab, t_point size, char c);
t_bool				ft_path_exists(char **tab, t_point size, t_point start,
						t_point end);
t_bool				ft_path_founding(char **tab, t_point size, t_point cur,
						t_point end);
void				ft_get_all_collectable(char **tab, t_game *game,
						t_point start, int *coins);

void				ft_flood_fill(char **tab, t_game *game, t_point start,
						t_bool *exit_found, int *coins);
//../src/bonus/check_map_finishable.c

void				ft_check_map_finishable(t_game *game);
void				ft_free_and_print(char **map, t_game *game, char *str);
char				**ft_split_map(t_game *game);
void				ft_clean_fail_malloc_split_map(t_game *game, char **grid,
						int row);
void				ft_clean_grid_map(char **grid, int row);

//../src/bonus/free_all.c

void				ft_free_all(t_game *game);
void				ft_free_player(t_game *game);
void				ft_free_player_move(t_game *game);
void				ft_free_ground(t_game *game);
void				ft_free_life(t_game *game);
void				ft_free_lava(t_game *game);
//void				ft_free_key_wall_door(t_game *game);

//../src/bonus/ft_free_all_one.c

void				ft_free_animation(t_game *game);
void				ft_free_mlx(t_game *game);
void				ft_free_key(t_game *game);
void				ft_free_wall(t_game *game);
void				ft_free_door(t_game *game);
void				ft_free_grass(t_game *game);

//../src/bonus/input_bonus.c

int					ft_input_manager(int key, t_game *game);
void				ft_move_up(t_game *game);
void				ft_move_down(t_game *game);
void				ft_move_left(t_game *game);
void				ft_move_right(t_game *game);

//../src/bonus/input_fct_bonus.c

void				ft_input_up(t_game *game);
void				ft_input_down(t_game *game);
void				ft_input_left(t_game *game);
void				ft_input_right(t_game *game);

//../src/bonus/lava_movement.c

void				ft_move_lava(t_game *game);
void				ft_lava_move_up(t_game *game);
void				ft_lava_move_down(t_game *game);
void				ft_lava_move_left(t_game *game);
void				ft_lava_move_right(t_game *game);

//../src/bonus/life_management.c

void				ft_display_life_on_windows(t_game *game);
void				ft_random_lava_move(t_game *game);
void				ft_map_fit_screen(t_game *game);
void				ft_load_player_current(t_game *game);

//../src/bonus/load_door_sprite_bonus.c

void				ft_load_door_closed_sprites(t_game *game);
void				ft_load_door_open_sprites(t_game *game);

//../src/bonus/load_sprite_bonus.c

void				ft_load_lava_sprites(t_game *game);
void				ft_load_key_sprites(t_game *game);
void				ft_load_wall_sprites(t_game *game);
void				ft_load_borders_sprite(t_game *game);
void				ft_load_ground_sprites(t_game *game);
void				ft_load_love_sprites(t_game *game);
void				ft_load_digits_sprites(t_game *game);
//../src/bonus/load_player_sprite_bonus.c

void				ft_player_animation(t_player *player);
void				ft_load_player_up_sprites(t_game *game);
void				ft_load_player_down_sprites(t_game *game);
void				ft_load_player_left_sprites(t_game *game);
void				ft_load_player_right_sprites(t_game *game);

//../src/bonus/map_bonus.c

void				ft_read_map(t_game *game, char *map_name);
void				ft_check_map(t_game *game);
void				ft_check_sealed(t_game *game);
void				ft_check_playability(t_game *game);
void				ft_get_info_map(t_game *game);
void				ft_init_game_info(t_game *game);

//../src/bonus/map_sprite_bonus.c

void				ft_key_sprite(t_game *game, t_point pos);
void				ft_lava_sprite(t_game *game, t_point pos);
void				ft_love_sprite(t_game *game, t_point pos);
void				ft_exit_sprite(t_game *game, t_point pos);
void				ft_ground_sprite(t_game *game, t_point pos);

//../src/bonus/other_tools_bonus.c

void				ft_print_map_better_format(t_game *game);
;
void				ft_print_game_info(t_game *game);
void				ft_print_facing(t_game *game);
void				ft_direction_by_pos_after_launch(t_game *game);
int					ft_lose_game(t_game *game);
void				ft_print_status(t_game *game);
void				ft_free_step_and_storage(t_game *game);

//../src/bonus/player_sprite_direction_bonus.c

void				ft_player_sprite_call(t_game *game, int width, int height,
						t_point sprite_pos);
void				ft_down_sprite(t_game *game, int width, int height);
void				ft_up_sprite(t_game *game, int width, int height);
void				ft_left_sprite(t_game *game, int width, int height);
void				ft_right_sprite(t_game *game, int width, int height);

//../src/bonus/so_long_bonus.c

void				ft_init_game(t_game *game, char *map_name);
int					ft_exit_game(t_game *game);
int					ft_win_game(t_game *game);
void				ft_print_error(char *error_msg, t_game *game);
void				ft_check_valid_char(t_game *game);
//void ft_init_map_with_borders(t_game *game);

//../src/bonus/sprite_bonus.c

void				ft_load_sprites(t_game *game);
void				ft_put_sprites_by_line(t_game *game);
void				ft_put_all_sprites_to_line(t_game *game, int width,
						int height, t_point sprite_pos);
void				ft_wall_sprite(t_game *game, t_point pos);
void				ft_borders_sprite(t_game *game, t_point pos);

//../src/bonus/tools_bonus.c

char				*ft_custom_strdup(char *s1);
int					ft_custom_strlcpy(char *dst, char *src, int dst_size);
char				*ft_custom_strjoin(char *s1, char *s2);
void				ft_check_env(char **env);
int					ft_check_extension(char *map_name, char *extension);

//../src/bonus/ft_error_managements.c

void				ft_print_no_arg(void);
void	ft_print_error_empty_and_free(char *error_msg,
									t_game *game);

//../src/bonus/ft_camera_bonus_linux.c

void				ft_init_camera(t_game *game);

char				**ft_create_map_with_border(t_game *game);
void				ft_player_get_hit(t_game *game);

void	ft_draw_sprite(t_game *game, void *sprite_img, int x, int y);

void	ft_put_buffer_image(t_game *game);

void	ft_draw_image_buffer(t_game *game, int width, int height,
		t_point sprite_pos);

#endif
