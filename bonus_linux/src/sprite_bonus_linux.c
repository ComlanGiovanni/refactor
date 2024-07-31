/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus_linux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:12:36 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/31 20:33:41 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"


//					IDEA
//				ft_print_spite_error char * path
//			This fct will print Error $variable fail to load header define
//		The variable will be splitted from the path header define
//				ft_split_path char * path
//		this fct will parse the path and put iin double table
//			path to the xm file and will return the str int the tab
//				Need : ft_split free after using
//				pros : less define form specific xpm file

/**
 * @brief
 *
 * 				This fct  call all the fct that load all
 * 					the sprite we need for the game aka
 * 		key lava wall ground player direct sprite door open and close
 *
 *  //ft_load_borders_sprite(game)
 * @param mlx
 * @return t_sprites
 */
void	ft_load_sprites(t_game *game)
{
	ft_load_key_sprites(game);
	ft_load_lava_sprites(game);
	ft_load_love_sprites(game);
	ft_load_wall_sprites(game);
	ft_load_ground_sprites(game);
	ft_load_borders_sprite(game);
	ft_load_player_up_sprites(game);
	ft_load_player_down_sprites(game);
	ft_load_player_left_sprites(game);
	ft_load_player_right_sprites(game);
	ft_load_player_current(game);
	ft_load_door_closed_sprites(game);
	ft_load_door_open_sprites(game);
	ft_load_digits_sprites(game);
}

/**
 * @brief
 *
 * 		0-   1111
 *  	1-   1CC1
 * 		2-   1PE1
 *      3-   1111
 *
 * 		we print all the sprite line by line by th height and width
 * 				get in ft_read_map and ft_init_map_info we send those
 * 	to ft_put_all_sprites_to_line to use mlx_put_image_to_window
 * 			for every elm in the map t_game map needed or map str and
 * 					width height
 *
 * @param game
 */
void	ft_put_sprites_by_line(t_game *game)
{
	int width;
	int height;
	int win_width;
	int win_height;
	t_point sprite_pos;

	height = 0;
	win_width = ((game->width * IMG_SIZE) / 2);
	win_height = ((game->height * IMG_SIZE) / 2);
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			sprite_pos.x = ((width * IMG_SIZE) - game->camera.current.x);
			sprite_pos.y = ((height * IMG_SIZE) - game->camera.current.y);
			if ((sprite_pos.x + IMG_SIZE) >= 0 && (sprite_pos.x <= win_width)
				&& (sprite_pos.y + IMG_SIZE) >= 0 && (sprite_pos.y <= win_height))
				ft_put_all_sprites_to_line(game, width, height, sprite_pos);
			width++;
		}
		height++;
	}
}


void	ft_put_buffer_image(t_game *game)
{
	int width;
	int height;
	t_point sprite_pos;

	height = 0;
	while (height < game->window.height)
	{
		width = 0;
		while (width < game->window.width)
		{
			sprite_pos.x = ((width * IMG_SIZE));
			sprite_pos.y = ((height * IMG_SIZE));
			if ((sprite_pos.x + IMG_SIZE) >= 0 && (sprite_pos.x <= game->window.width)
				&& (sprite_pos.y + IMG_SIZE) >= 0 && (sprite_pos.y <= game->window.height))
				ft_draw_image_buffer(game, width, height, sprite_pos);
			width++;
		}
		height++;
	}
}

/**
 * @brief
 * 			1111
 *  		1CC1
 * 			1PE1
 *         1111
 *
 *  We print all the xpm load in ft_init_sprites if we found
 * 		char (WALL-COIN-PLAYER-EXIT-GROUND)  0 1 P E C with this fct :
 * 							Lava love char
 * int	mlx_put_image_to_window(void *mlx_ptr,	{game->mlx}
 * 								void *win_ptr,  {game->ptr}
 * 								void *img_ptr,	{game->sprite}->.{you_assets}
 *							int x, int y); position width height
 *
 * x && y are multiply by 64 because int init_game in main
 * 			we set the windows like :
 *   win ->(game->mlx, game->width * 64, game->height * 64, GAME_TITLE);
 *
 * every time for every char we check all idx to see witch one to print
 * so 0 1 2 3 4 would be check for  0 1 P E C to get printed because
 * the player can move and the coin can be remove so we need to check all
 * the time to get the illusion of update and good feed back on the windows
 *
 * 	game->map[height * game->width + width]	idx -> [0 1 2 3] * (4) + [0 1 2 3]
 *
 * we slit in small fct or 42 norm in all those ft_{01PECLL}_sprite we just
 * 						mlx_put_image_to_window
 *
 *
 * // else if (tile == BORDER_CHAR)
 * //		ft_borders_sprite(game, sprite_pos);

 * @param game
 * @param width
 * @param height
 */
void	ft_put_all_sprites_to_line(t_game *game, int width, int height,
		t_point sprite_pos)
{
    char tile;

    tile = game->map.grid[height][width];
    if (tile == WALL_CHAR)
        ft_wall_sprite(game, sprite_pos);
    else if (tile == KEY_CHAR)
        ft_key_sprite(game, sprite_pos);
    else if (tile == LAVA_CHAR)
        ft_lava_sprite(game, sprite_pos);
    else if (tile == LOVE_CHAR)
        ft_love_sprite(game, sprite_pos);
    else if (tile == EXIT_CHAR && game->player.storage == game->map.info.nbr_key)
        mlx_put_image_to_window(game->mlx, game->win, game->door.open.current, sprite_pos.x, sprite_pos.y);
	else if (tile == EXIT_CHAR)
        ft_exit_sprite(game, sprite_pos);
    else if (tile == VOID_CHAR)
        ft_ground_sprite(game, sprite_pos);
	else if (tile == BORDER_CHAR)
		ft_borders_sprite(game, sprite_pos);
    else
        ft_player_sprite_call(game, width, height, sprite_pos);
}

void	ft_draw_image_buffer(t_game *game, int width, int height,
		t_point sprite_pos)
{
    char tile;

    tile = game->map.grid[height][width];
    if (tile == WALL_CHAR)
        ft_draw_sprite(game, game->wall.animation.current, sprite_pos.x, sprite_pos.y);
    else if (tile == KEY_CHAR)
        ft_draw_sprite(game, game->key.animation.current, sprite_pos.x, sprite_pos.y);
    else if (tile == LAVA_CHAR)
        ft_draw_sprite(game, game->lava.animation.current, sprite_pos.x, sprite_pos.y);
    else if (tile == LOVE_CHAR)
        ft_draw_sprite(game, game->love.animation.current, sprite_pos.x, sprite_pos.y);
    else if (tile == EXIT_CHAR && game->player.storage == game->map.info.nbr_key)
        ft_draw_sprite(game, game->door.open.current, sprite_pos.x, sprite_pos.y);
	else if (tile == EXIT_CHAR)
        ft_draw_sprite(game, game->door.closed.current, sprite_pos.x, sprite_pos.y);
    else if (tile == VOID_CHAR)
        ft_draw_sprite(game, game->map.ground, sprite_pos.x, sprite_pos.y);
	else if (tile == BORDER_CHAR)
		ft_draw_sprite(game, game->grass.animation.current, sprite_pos.x, sprite_pos.y);
    else
	{
		 if (game->map.grid[height][width] == PLAYER_CHAR) {
			if (game->player.movement.direction == 'd')
				ft_draw_sprite(game, game->player.down_anim.current, sprite_pos.x, sprite_pos.y);
			else if (game->player.movement.direction == 'u')
				ft_draw_sprite(game, game->player.up_anim.current, sprite_pos.x, sprite_pos.y);
			else if (game->player.movement.direction == 'l')
				ft_draw_sprite(game, game->player.left_anim.current, sprite_pos.x, sprite_pos.y);
			else if (game->player.movement.direction == 'r')
				ft_draw_sprite(game, game->player.right_anim.current, sprite_pos.x, sprite_pos.y);
		}
	}
}

// not great but you will stay here lol

void	ft_wall_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->wall.animation.current,
		pos.x, pos.y);
}

void ft_borders_sprite(t_game *game, t_point pos)
{
    mlx_put_image_to_window(game->mlx, game->win, game->grass.animation.current, pos.x,
		pos.y);
}


// void ft_alpha_blend(t_game *game, t_point pos, void *sprite, int width, int height) {
//     int x, y;
//     int color;
//     int dst_offset;
//     int src_offset;
//     char *src_data;
//     int a, r, g, b;
//     int bg_r, bg_g, bg_b;

//     src_data = mlx_get_data_addr(sprite, &game->bpp, &game->size_line, &game->endian);

//     for (y = 0; y < height; y++) {
//         for (x = 0; x < width; x++) {
//             src_offset = (y * game->size_line) + (x * (game->bpp / 8));
//             dst_offset = ((pos.y + y) * game->size_line) + ((pos.x + x) * (game->bpp / 8));

//             color = *(int *)(src_data + src_offset);
//             a = (color >> 24) & 0xFF;
//             r = (color >> 16) & 0xFF;
//             g = (color >> 8) & 0xFF;
//             b = color & 0xFF;

//             bg_r = game->img_data[dst_offset + 2] & 0xFF;
//             bg_g = game->img_data[dst_offset + 1] & 0xFF;
//             bg_b = game->img_data[dst_offset] & 0xFF;

//             game->img_data[dst_offset + 2] = (r * a + bg_r * (255 - a)) / 255;
//             game->img_data[dst_offset + 1] = (g * a + bg_g * (255 - a)) / 255;
//             game->img_data[dst_offset] = (b * a + bg_b * (255 - a)) / 255;
//         }
//     }
// }

//ft_capture_screen(game, "screenshot.bmp");

// void ft_capture_screen(t_game *game, const char *filename) {
//     int fd;
//     int filesize = 54 + 3 * game->win_width * game->win_height;
//     unsigned char bmpfileheader[14] = {
//         'B', 'M', filesize, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0
//     };
//     unsigned char bmpinfoheader[40] = {
//         40, 0, 0, 0, game->win_width, 0, 0, 0, game->win_height, 0, 0, 0, 1, 0, 24, 0
//     };
//     unsigned char bmppad[3] = {0, 0, 0};
//     int i, j;
//     int *img_data_int = (int *)game->img_data;

//     fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0666);
//     if (fd < 0) {
//         ft_print_error("Error opening file for screenshot", game);
//     }

//     write(fd, bmpfileheader, 14);
//     write(fd, bmpinfoheader, 40);

//     for (i = 0; i < game->win_height; i++) {
//         for (j = 0; j < game->win_width; j++) {
//             int pixel = img_data_int[(game->win_height - i - 1) * game->win_width + j];
//             unsigned char color[3] = {pixel & 0xFF, (pixel >> 8) & 0xFF, (pixel >> 16) & 0xFF};
//             write(fd, color, 3);
//         }
//         write(fd, bmppad, (4 - (game->win_width * 3) % 4) % 4);
//     }

//     close(fd);
// }
