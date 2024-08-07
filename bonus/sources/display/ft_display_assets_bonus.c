/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:46:14 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/07 13:40:21 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"


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


void	ft_put_sprites_by_line(t_game *game)
{
	int		width;
	int		height;
	int		win_width;
	int		win_height;
	t_point	sprite_pos;

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
				&& (sprite_pos.y + IMG_SIZE) >= 0
				&& (sprite_pos.y <= win_height))
				ft_put_all_sprites_to_line(game, width, height, sprite_pos);
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
	char	tile;

	tile = game->map.grid[height][width];
	if (tile == WALL_CHAR)
		ft_wall_sprite(game, sprite_pos);
	else if (tile == KEY_CHAR)
		ft_key_sprite(game, sprite_pos);
	else if (tile == LAVA_CHAR)
		ft_lava_sprite(game, sprite_pos);
	else if (tile == LOVE_CHAR)
		ft_love_sprite(game, sprite_pos);
	else if (tile == EXIT_CHAR
		&& game->player.storage == game->map.info.nbr_key)
		mlx_put_image_to_window(game->mlx, game->win,
			game->door.open.current, sprite_pos.x, sprite_pos.y);
	else if (tile == EXIT_CHAR)
		ft_exit_sprite(game, sprite_pos);
	else if (tile == VOID_CHAR)
		ft_ground_sprite(game, sprite_pos);
	else if (tile == BORDER_CHAR)
		ft_borders_sprite(game, sprite_pos);
	else if (tile == BOX_CHAR)
		ft_box_sprite(game, sprite_pos);
	else if (tile == PORTAL_1_CHAR)
		ft_portal_n_sprite(game, sprite_pos);
	else if (tile == PORTAL_2_CHAR)
		ft_portal_z_sprite(game, sprite_pos);
	else if (tile == KEKE_CHAR)
		ft_keke_sprites(game, width, height, sprite_pos);
	else
		ft_player_sprite_call(game, width, height, sprite_pos);
}

void	ft_player_sprite_call(t_game *game, int width, int height,
		t_point sprite_pos)
{
	if (game->map.grid[height][width] == PLAYER_CHAR)
	{
		if (game->player.movement.direction == 'd')
			ft_player_down_sprite(game, sprite_pos.x, sprite_pos.y);
		else if (game->player.movement.direction == 'u')
			ft_player_up_sprite(game, sprite_pos.x, sprite_pos.y);
		else if (game->player.movement.direction == 'l')
			ft_player_left_sprite(game, sprite_pos.x, sprite_pos.y);
		else if (game->player.movement.direction == 'r')
			ft_player_right_sprite(game, sprite_pos.x, sprite_pos.y);
	}
}

