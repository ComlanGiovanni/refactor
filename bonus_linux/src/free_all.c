/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:06 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/31 13:20:24 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 * 	Free of last minutes, need to read the project again for better free fct
 * 	we need to free all the image load in sprites before so we check and free
 * 	then the map in str (alway check if exist)
 * 	then we destroy the game (mlx, win)
 * 	then the display (mlx)
 * 	and at the end we need to free the mlx and the game we malloc in the main
 *
 *
 * @param game
 */
void	ft_free_all(t_game *game)
{
	//mlx_loop_end(game->mlx);
	ft_free_animation(game);
	//ft_free_mapgame->map.matrice
	if (game->map.map_str) // ? != NULL
		free(game->map.map_str);
	// if (game->map.matrice) != NULL
	// 	ft_clean_grid_map(game->map.matrice, game->height); // dois-je caster ?
	if (game->map.grid)
		ft_clean_grid_map(game->map.grid, game->height); // dois-je caster ?
	ft_free_mlx(game);
}

void	ft_free_player(t_game *game)
{
	if (game->player.up_anim.frame_2)
		mlx_destroy_image(game->mlx, game->player.up_anim.frame_2);
	if (game->player.up_anim.frame_1)
		mlx_destroy_image(game->mlx, game->player.up_anim.frame_1);
	if (game->player.down_anim.frame_1)
		mlx_destroy_image(game->mlx, game->player.down_anim.frame_1);
	if (game->player.down_anim.frame_2)
		mlx_destroy_image(game->mlx, game->player.down_anim.frame_2);
	if (game->player.left_anim.frame_1)
		mlx_destroy_image(game->mlx, game->player.left_anim.frame_1);
	if (game->player.left_anim.frame_2)
		mlx_destroy_image(game->mlx, game->player.left_anim.frame_2);
	if (game->player.right_anim.frame_1)
		mlx_destroy_image(game->mlx, game->player.right_anim.frame_1);
	if (game->player.right_anim.frame_2)
		mlx_destroy_image(game->mlx, game->player.right_anim.frame_2);
	if (game->player.right_anim.frame_0)
		mlx_destroy_image(game->mlx, game->player.right_anim.frame_0);
	if (game->player.left_anim.frame_0)
		mlx_destroy_image(game->mlx, game->player.left_anim.frame_0);
	if (game->player.up_anim.frame_0)
		mlx_destroy_image(game->mlx, game->player.up_anim.frame_0);
	if (game->player.down_anim.frame_0)
		mlx_destroy_image(game->mlx, game->player.down_anim.frame_0);
}

void	ft_free_player_move(t_game *game)
{
	if (game->player.up_anim.frame_move)
		mlx_destroy_image(game->mlx, game->player.up_anim.frame_move);
	if (game->player.down_anim.frame_move)
		mlx_destroy_image(game->mlx, game->player.down_anim.frame_move);
	if (game->player.left_anim.frame_move)
		mlx_destroy_image(game->mlx, game->player.left_anim.frame_move);
	if (game->player.right_anim.frame_move)
		mlx_destroy_image(game->mlx, game->player.right_anim.frame_move);
}

void	ft_free_ground(t_game *game)
{
	if (game->map.ground)
		mlx_destroy_image(game->mlx, game->map.ground);
}

void	ft_free_lava(t_game *game)
{
	if (game->lava.animation.frame_0)
		mlx_destroy_image(game->mlx, game->lava.animation.frame_0);
	if (game->lava.animation.frame_1)
		mlx_destroy_image(game->mlx, game->lava.animation.frame_1);
	if (game->lava.animation.frame_2)
		mlx_destroy_image(game->mlx, game->lava.animation.frame_2);
}

void	ft_free_life(t_game *game)
{
	if (game->love.icon)
		mlx_destroy_image(game->mlx, game->love.icon);
	if (game->love.animation.frame_1)
		mlx_destroy_image(game->mlx, game->love.animation.frame_1);
	if (game->love.animation.frame_0)
		mlx_destroy_image(game->mlx, game->love.animation.frame_0);
	if (game->love.animation.frame_2)
		mlx_destroy_image(game->mlx, game->love.animation.frame_2);
	if (game->love.nope)
		mlx_destroy_image(game->mlx,game->love.nope);
}

// void	ft_free_key_wall_door(t_game *game)
// {
// 	if (game->key.animation.frame_1)
// 		mlx_destroy_image(game->mlx, game->key.animation.frame_1);
// 	if (game->key.animation.frame_2)
// 		mlx_destroy_image(game->mlx, game->key.animation.frame_2);
// 	if (game->wall.animation.frame_1)
// 		mlx_destroy_image(game->mlx, game->wall.animation.frame_1);
// 	if (game->wall.animation.frame_2)
// 		mlx_destroy_image(game->mlx, game->wall.animation.frame_2);
// 	if (game->door.open.frame_1)
// 		mlx_destroy_image(game->mlx, game->door.open.frame_1);
// 	if (game->door.open.frame_2)
// 		mlx_destroy_image(game->mlx, game->door.open.frame_2);
// 	if (game->door.closed.frame_0)
// 		mlx_destroy_image(game->mlx, game->door.closed.frame_0);
// 	if (game->door.closed.frame_1)
// 		mlx_destroy_image(game->mlx, game->door.closed.frame_1);
// 	if (game->door.closed.frame_2)
// 		mlx_destroy_image(game->mlx, game->door.closed.frame_2);
// 	if (game->key.animation.frame_0)
// 		mlx_destroy_image(game->mlx, game->key.animation.frame_0);
// 	if (game->wall.animation.frame_0)
// 		mlx_destroy_image(game->mlx, game->wall.animation.frame_0);
// 	if (game->door.open.frame_0)
// 		mlx_destroy_image(game->mlx, game->door.open.frame_0);
// }

