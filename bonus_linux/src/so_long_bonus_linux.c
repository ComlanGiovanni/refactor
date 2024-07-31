/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_linux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:12:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 01:06:43 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

void	ft_init_fps(t_game *game)
{
	clock_gettime(1, &game->fps.current_time);
	game->fps.frame_count = 0;
	game->fps.fps = 0.0;
	game->fps.last_time = game->fps.current_time;
	game->fps.elapsed = 0.0;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_print_error(MLX_INIT_ERROR, game);
}

void	ft_setup_map(t_game *game)
{
	ft_display_start_end(game->map.start, game->map.end);
	if (game->map.matrice != NULL)
		ft_clean_grid_map(game->map.matrice, game->height);
	game->map.matrice = ft_split_map(game);
	ft_print_display_grid(game->map.matrice);
	game->map.grid = ft_create_map_with_border(game);
	ft_printf(NEW_GRID_MSG);
	ft_print_display_grid(game->map.grid);
	game->map.start = ft_find_pos_char(game->map.grid, game->map.size, 'P');
	game->map.end = ft_find_pos_char(game->map.grid, game->map.size, 'E');
	ft_display_start_end(game->map.start, game->map.end);
	game->player.movement.current_position.x = game->map.start.x;
	game->player.movement.current_position.y = game->map.start.y;
}

void	ft_create_window(t_game *game)
{
	game->window.width = ((game->width * IMG_SIZE) / 2);
	game->window.height = ((game->height * IMG_SIZE) / 2);
	game->win = mlx_new_window(game->mlx, game->window.width,
			game->window.height, GAME_TITLE);
	if (game->win == NULL)
		ft_print_error(MLX_WINDOW_ERROR, game);
	game->finished = 0;
}

void	ft_init_frames(t_game *game)
{
	game->player.frames = PLAYER_FRAMES;
	game->lava.animation.frames = 24;
	game->key.animation.frames = 6;
	game->wall.animation.frames = 64;
	game->grass.animation.frames = 8;
	game->love.animation.frames = 48;
	game->hud.digits.zero.frames = 64;
	game->hud.digits.one.frames = 7;
	game->hud.digits.two.frames = 12;
	game->hud.digits.tree.frames = 7;
	game->hud.digits.four.frames = 12;
	game->hud.digits.five.frames = 7;
	game->hud.digits.six.frames = 12;
	game->hud.digits.seven.frames = 7;
	game->hud.digits.eight.frames = 7;
	game->hud.digits.nine.frames = 78;
}

//make position offset ?
//missing t_point for life
// game->hud.storage.x = 200;
// game->hud.storage.y = 300;

void	ft_init_hud_sprites_position(t_game *game)
{
	game->hud.step.x = 90;
	game->hud.step.y = 40;
	game->hud.fps.x = 60;
	game->hud.fps.y = 290;
	game->hud.direction.x = 230;
	game->hud.direction.y = 320;
	game->hud.keys.x = 170;
	game->hud.keys.y = 240;
}

void	ft_display_sprites_addr(t_game *game)
{
	ft_printf("All image width and height are [%d x %d]\n\n",
		IMG_SIZE, IMG_SIZE);
	ft_printf("assets/xpm/Bonus/lava/lava_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/lava/lava_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_1);
	ft_printf("assets/xpm/Bonus/lava/lava_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_2);
	ft_printf("assets/xpm/Bonus/door/closed/door_closed_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/door/closed/door_closed_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/door/closed/door_closed_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/door/open/door_open_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/door/open/door_open_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/door/open/door_open_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/up/player_up_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/up/player_up_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/up/player_up_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/up/player_up_frame_move.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/down/player_down_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/down/player_down_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/down/player_down_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/down/player_down_frame_move.x.pm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/left/player_left_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/left/player_left_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/left/player_left_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/left/player_left_frame_move.x.pm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/right/player_right_frame_0.xp);m");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/right/player_right_frame_1.xp);m");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/right/player_right_frame_2.xp);m");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/right/player_right_frame_move);.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/key/key_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/key/key_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/key/key_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/wall/wall_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/wall/wall_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/wall/wall_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/grass/grass_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/grass/grass_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/grass/grass_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/ground/ground.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/love/love_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/love/love_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/love/love_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/love/love_small_icon.xpm");
}

// void	ft_draw_sprite(t_game *game, void *sprite_img, int x, int y)
// {
// 	int				sprite_width;
// 	int				sprite_height;
// 	int				i;
// 	int				j;
// 	char			*dst;
// 	char			*src;
// 	unsigned int	color;
// 	char			*sprite_data;
// 	int				sprite_bpp;
// 	int				sprite_size_line;
// 	int				sprite_endian;

// 	// Récupérer les données de l'image du sprite
// 	sprite_data = mlx_get_data_addr(sprite_img, &sprite_bpp, &sprite_size_line,
// 			&sprite_endian);
// 	sprite_width = 64;
// 	sprite_height = 64;
// 	// Parcourir chaque pixel du sprite
// 	for (i = 0; i < sprite_height; i++)
// 	{
// 		for (j = 0; j < sprite_width; j++)
// 		{
// 			// Calculer la position du pixel source et destination
// 			src = sprite_data + (i * sprite_size_line + j * (sprite_bpp / 8));
// 			dst = game->win + ((y + i) * game->window.size_line + (x + j)
// 					* (game->window.bpp / 8));
// 			// Récupérer la couleur du pixel source
// 			color = *(unsigned int *)src;
// 			// Gestion de la transparence
// 			if (color != 0xFF000000)
// 			// 0xFF000000 pour la transparence (si applicable)
// 				*(unsigned int *)dst = color;
// 		}
// 	}
// }

/**
 * @brief
 *
 * 		we check the mlx_init() that will be in game->mlx
 * 	we also check the mlx_new_windows that will be in game->win
 *
 * 			we need the width height and a title for it
 * 		those are set inside ft_read_map/ft_init_map_info
 *	and get inc will reading the map file, then those nbr would be
 *		multiply by IMG_SIZE -> (64) who is the size of every
 * 				sprite load int ft_init_sprites()
 * 				the we print every sprite line by line
 * 			we make sure that the map is well formatted
 * 				before printing all the sprite
 *
 *
 * 	ft_printf("Printing map with border:\n"
 * for (int i = 0; i < game->height; i++) {
 * 		ft_printf("%s\n", game->map.grid[i]);
 * 	}
 *
	//mdr this shit happen because the map the modify
	//because of the path founding so we need to get it again
 * ft_printf("Size of new grid x-%d y-%d\n", game->map.size.x,
		game->map.size.y);
 *	ft_printf("Position in Start in new grid x-%d y-%d\n", game->map.start.x,
			game->map.start.y);
 *	pause();
 *
 * @param game
 * @param map_name
 */
void	ft_init_game(t_game *game, char *map_name)
{
	if (!ft_check_extension(map_name, BER_EXTENSION))
		ft_print_error_empty_and_free(EXTENSION_ERROR, game);
	ft_init_camera(game);
	ft_init_hud_sprites_position(game);
	ft_init_mlx(game);
	ft_init_frames(game);
	ft_load_sprites(game);
	ft_init_fps(game);
	ft_init_player_info(game);
	ft_read_map(game, map_name);
	ft_check_map(game);
	ft_setup_map(game);
	ft_create_window(game);
	ft_display_sprites_addr(game);
	system("cvlc sounds/BabaIsYouOnTheIsland.wav &");
}

/**
 * @brief
 *
 * 		we check if every char until the end is
 *  		equal to typedef enum e_map_char
 * 		if not quit and print the error msg for it
 *
 * @param game
 */
void	ft_check_valid_char(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (game->map.map_str[idx] != '\0')
	{
		if (game->map.map_str[idx] != WALL_CHAR
			&& game->map.map_str[idx] != PLAYER_CHAR
			&& game->map.map_str[idx] != KEY_CHAR
			&& game->map.map_str[idx] != EXIT_CHAR
			&& game->map.map_str[idx] != VOID_CHAR
			&& game->map.map_str[idx] != LAVA_CHAR
			&& game->map.map_str[idx] != LOVE_CHAR)
			ft_print_error(BAD_CHAR_MAP_ERROR, game);
		idx++;
	}
}

/**
 * @brief
 *
 * 			Just exit the window by destroying
 * 		mlx and win with mlx_destroy_window and return
 * 			0 -> EXIT_SUCCESS hummm we exit the game
 * 		when we press esc so the exit for me is SUCCESS
 * 			think its good, this fct is call when
 * 				the mlx_hook in the game is trigger
 * 				by the x mask 17 -> CLOSE_ICON
 *
 * 		for ft_exit_game ft_win_game we should free the game malloc
 * 			if need send t_game * game to ft_print_error
 * 				for good free for linux version
 *
 * 			mlx_destroy_window(game->mlx, game->win);
 *
 * @param game
 * @return int
 */
int	ft_exit_game(t_game *game)
{
	system("pkill vlc");
	ft_free_all(game);
	exit(EXIT_SUCCESS);
}

/**
 * @brief
 *
 * 		This fct is called only when the player win the game
 * 			so we print the number of step a the end
 * 					with a define win msg
 *
 * 		we also print the storage and the life of the player
 *
 *  			Just exit the window by destroying
 * 		mlx and win with mlx_destroy_window and return
 * 			0 -> EXIT_SUCCESS hummm we exit the game
 * 		when we player win so for me is SUCCESS var
 *
 *
 * 		for ft_exit_game ft_win_game we should free the game malloc
 * 			if need send t_game * game to ft_print_error
 * 				for good free for linux version
 *
 * 		mlx_destroy_window(game->mlx, game->win);
 *
 * @param game
 * @return int
 */
int	ft_win_game(t_game *game)
{
	system("pkill vlc");
	ft_printf(WIN_MSG "%d ", game->player.step);
	ft_printf("Storage : %d, ", game->player.storage);
	ft_printf("Life : %d\n", game->player.life);
	ft_free_all(game);
	exit(EXIT_SUCCESS);
}

/**
 * @brief
 *
 * If the error value is >= 1
 * 	print Error in standard error
 * else 0 -1 etc
 * 	just exit the code
 *
 * EXIT_SUCCESS = 0
 * EXIT_FAILURE = 1;
 *
 * STDIN_FILENO    Standard input value, stdin. Its value is 0.
 * STDOUT_FILENO   Standard output value, stdout. Its value is 1.
 * STDERR_FILENO   Standard error value, stderr. Its value is 2.
 *
 * @param error_code
 * @return int
 */
void	ft_print_error(char *error_msg, t_game *game)
{
	ft_free_all(game);
	ft_printf("%s%s", ERROR_MSG, error_msg);
	exit(EXIT_FAILURE);
}
