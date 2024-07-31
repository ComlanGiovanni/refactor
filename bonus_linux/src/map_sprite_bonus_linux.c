/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sprite_bonus_linux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:12:02 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/31 18:12:27 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 *
 * 		we split for 25 line norm so see ft_put_all_sprites_to_line comment
 *
 *
 * @param game
 * @param width
 * @param height
 */
void	ft_key_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->key.animation.current,
		pos.x, pos.y);
}

void	ft_lava_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->lava.animation.current,
		pos.x, pos.y);
}

void	ft_love_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->love.animation.current,
		pos.x, pos.y);
}

void	ft_exit_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->door.closed.current,
		pos.x, pos.y);
}

void	ft_ground_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->map.ground, pos.x,
		pos.y);
}
