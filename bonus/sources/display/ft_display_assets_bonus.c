/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:46:14 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 19:45:21 by gicomlan         ###   ########.fr       */
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
 *  //ft_load_grass_sprites(game)
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
//use if for every print
void ft_put_sprite(t_game *game, void *sprite, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite, pos.x, pos.y);
}

void ft_handle_key_love_box_sprites(t_game *game, char tile, t_point sprite_pos)
{
	if (tile == KEY_CHAR)
		ft_key_sprite(game, sprite_pos);
	else if (tile == LOVE_CHAR)
		ft_love_sprite(game, sprite_pos);
	else if (tile == BOX_CHAR)
		ft_box_sprite(game, sprite_pos);
}

void ft_handle_exit_portals_sprites(t_game *game, char tile, t_point sprite_pos)
{
	if (tile == EXIT_CHAR)
	{
		if (game->player.storage == game->map.info.nbr_key)
			ft_put_sprite(game, game->door.open.current, sprite_pos);
		else
			ft_exit_sprite(game, sprite_pos);
	}
	else if (tile == PORTAL_1_CHAR)
		ft_portal_n_sprite(game, sprite_pos);
	else if (tile == PORTAL_2_CHAR)
		ft_portal_z_sprite(game, sprite_pos);
}

void ft_handle_enemies_sprites(t_game *game, char tile, t_point sprite_pos)
{
  	if (tile == LAVA_CHAR)
		ft_lava_sprite(game, sprite_pos);
	else if (tile == PAWN_CHAR)
		ft_pawn_sprite(game, sprite_pos);
}

void	ft_tree_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->tree.animation.current, pos.x, pos.y);
}

void	ft_trees_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->trees.animation.current, pos.x, pos.y);
}

void	ft_reed_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->reed.animation.current, pos.x, pos.y);
}

void	ft_husks_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->husks.animation.current, pos.x, pos.y);
}

void	ft_fungus_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->fungus.animation.current, pos.x, pos.y);
}

void	ft_fungi_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->fungi.animation.current, pos.x, pos.y);
}

void	ft_flower_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->flower.animation.current, pos.x, pos.y);
}

void	ft_algae_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->algae.animation.current, pos.x, pos.y);
}

void	ft_water_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->water.animation.current, pos.x, pos.y);
}

void	ft_crab_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->crab.animation.current, pos.x, pos.y);
}

void	ft_foliage_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->foliage.animation.current, pos.x, pos.y);
}

void	ft_bog_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->bog.animation.current, pos.x, pos.y);
}

void	ft_snail_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->snail.animation.current, pos.x, pos.y);
}

void	ft_pillar_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->pillar.animation.current, pos.x, pos.y);
}

void	ft_hedge_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->hedge.animation.current, pos.x, pos.y);
}

void ft_handle_borders_sprites(t_game *game, char tile, t_point sprite_pos)
{
	if (tile == GRASS_CHAR)
		ft_grass_sprite(game, sprite_pos);
    else if (tile == TREE_CHAR)
        ft_tree_sprite(game, sprite_pos);
    else if (tile == TREES_CHAR)
        ft_trees_sprite(game, sprite_pos);
    else if (tile == REED_CHAR)
        ft_reed_sprite(game, sprite_pos);
    else if (tile == HUSKS_CHAR)
        ft_husks_sprite(game, sprite_pos);
    else if (tile == FUNGUS_CHAR)
        ft_fungus_sprite(game, sprite_pos);
	else if (tile == FUNGI_CHAR)
        ft_fungi_sprite(game, sprite_pos);
	else if (tile ==  FLOWER_CHAR)
        ft_flower_sprite(game, sprite_pos);
	else if (tile == ALGAE_CHAR)
        ft_algae_sprite(game, sprite_pos);
	else if (tile == WATER_CHAR)
        ft_water_sprite(game, sprite_pos);
}

void ft_handle_other_borders_sprites(t_game *game, char tile, t_point sprite_pos)
{
	if (tile == CRAB_CHAR)
		ft_crab_sprite(game, sprite_pos);
    else if (tile == FOLIAGE_CHAR)
        ft_foliage_sprite(game, sprite_pos);
    else if (tile == BOG_CHAR)
        ft_bog_sprite(game, sprite_pos);
    else if (tile == SNAIL_CHAR)
        ft_snail_sprite(game, sprite_pos);
    else if (tile == PILLAR_CHAR)
        ft_pillar_sprite(game, sprite_pos);
    else if (tile == HEDGE_CHAR)
		ft_hedge_sprite(game, sprite_pos);
}

t_bool ft_is_key_love_box_sprites(char tile)
{
	return (tile == KEY_CHAR) || (tile == LOVE_CHAR) || (tile == BOX_CHAR);
}

t_bool ft_is_exit_portals_sprites(char tile)
{
	return (tile == EXIT_CHAR) || (tile == PORTAL_1_CHAR) || tile == (PORTAL_2_CHAR);
}
t_bool ft_is_enemies_sprites(char tile)
{
	return ((tile == LAVA_CHAR) || (tile == PAWN_CHAR));
}
t_bool ft_is_borders_sprites(char tile)
{
	return (tile == GRASS_CHAR) || (tile == TREE_CHAR) || (tile == TREES_CHAR)
		|| (tile == REED_CHAR) || (tile == HUSKS_CHAR) || (tile == FUNGUS_CHAR)
		|| (tile == FUNGI_CHAR) || (tile == FLOWER_CHAR) || (tile == ALGAE_CHAR) || (tile == WATER_CHAR);
}

t_bool ft_is_other_borders_sprites(char tile)
{
	return (tile == CRAB_CHAR) || (tile == FOLIAGE_CHAR) || (tile == BOG_CHAR)
		|| (tile == SNAIL_CHAR) || (tile == PILLAR_CHAR) || (tile == HEDGE_CHAR);
}

// typedef struct s_walls {
//     t_animation top_left;
//     t_animation top_right;
//     t_animation bottom_left;
//     t_animation bottom_right;
//     t_animation horizontal;
//     t_animation vertical;
// } t_walls;


// void ft_wall_sprite(t_game *game, t_point pos, int width, int height) {
//     void *sprite = NULL;

//     if (width == 0 && height == 0) {
//         sprite = game->wall.top_left.current;
//     } else if (width == game->map.size.x - 1 && height == 0) {
//         sprite = game->wall.top_right.current;
//     } else if (width == 0 && height == game->map.size.y - 1) {
//         sprite = game->wall.bottom_left.current;
//     } else if (width == game->map.size.x - 1 && height == game->map.size.y - 1) {
//         sprite = game->wall.bottom_right.current;
//     } else if (height == 0 || height == game->map.size.y - 1) {
//         sprite = game->wall.horizontal.current;
//     } else if (width == 0 || width == game->map.size.x - 1) {
//         sprite = game->wall.vertical.current;
//     }

//     if (sprite) {
//         mlx_put_image_to_window(game->mlx, game->win, sprite, pos.x, pos.y);
//     }
// }



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
 * // else if (tile == GRASS_CHAR)
 * //		ft_grass_sprite(game, sprite_pos);

 * @param game
 * @param width
 * @param height
 */
void	ft_put_all_sprites_to_line(t_game *game, int width, int height,
		t_point sprite_pos)
{
	char	tile;

	tile = game->map.grid[height][width];
	//printf("Tile -> %c Width -> %d Height -> %d sprite_pos.x -> %d sprite_pos.y -> %d\n", tile, width, height, sprite_pos.x, sprite_pos.y);
	if (tile == WALL_CHAR)
		ft_wall_sprite(game, sprite_pos);
	else if (tile == VOID_CHAR)
		ft_ground_sprite(game, sprite_pos);
	else if (ft_is_key_love_box_sprites(tile))
		ft_handle_key_love_box_sprites(game, tile, sprite_pos);
	else if (ft_is_exit_portals_sprites(tile))
		ft_handle_exit_portals_sprites(game, tile, sprite_pos);
	else if (ft_is_borders_sprites(tile))
		ft_handle_borders_sprites(game, tile, sprite_pos);
	else if (ft_is_other_borders_sprites(tile))
		ft_handle_other_borders_sprites(game, tile, sprite_pos);
	else if (ft_is_enemies_sprites(tile))
		ft_handle_enemies_sprites(game, tile, sprite_pos);
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


// typedef struct s_game {

//     void *wall_sprites[16]; // Array of wall sprites based on bitmask
// } t_game;

// int calculate_wall_bitmask(t_game *game, int x, int y) {
//     int bitmask = 0;

//     // Check north
//     if (y > 0 && game->grid[y - 1][x] == WALL_CHAR)
//         bitmask |= 1 << 0;
//     // Check south
//     if (y < GRID_HEIGHT - 1 && game->grid[y + 1][x] == WALL_CHAR)
//         bitmask |= 1 << 1;
//     // Check west
//     if (x > 0 && game->grid[y][x - 1] == WALL_CHAR)
//         bitmask |= 1 << 2;
//     // Check east
//     if (x < GRID_WIDTH - 1 && game->grid[y][x + 1] == WALL_CHAR)
//         bitmask |= 1 << 3;

//     return bitmask;
// }

// void ft_draw_wall_sprite(t_game *game, int x, int y, t_point pos) {
//     int bitmask = calculate_wall_bitmask(game, x, y);
//     void *sprite = game->wall_sprites[bitmask];
//     mlx_put_image_to_window(game->mlx, game->win, sprite, pos.x, pos.y);
// }

// 0: No neighbors
// 1: North
// 2: South
// 3: North + South
// 4: West
// 5: North + West
// 6: South + West
// 7: North + South + West
// 8: East
// 9: North + East
// 10: South + East
// 11: North + South + East
// 12: West + East
// 13: North + West + East
// 14: South + West + East
// 15: All sides (North + South + West + East)

// Define Bitmask Values: Assign a bitmask value to
// each possible surrounding tile configuration.
// For example, if a wall tile has neighboring wall tiles
// to the north, south, east, and west, it might have a
// bitmask value of 1111 in binary, which corresponds to 15 in decimal.
