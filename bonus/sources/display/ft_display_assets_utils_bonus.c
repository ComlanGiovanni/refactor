/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_assets_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:46:45 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 01:58:03 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

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
void	ft_wall_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->wall.animation.current, pos.x, pos.y);
}

void	ft_borders_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->grass.animation.current, pos.x, pos.y);
}

void	ft_box_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->box.animation.current, pos.x, pos.y);
}

void	ft_portal_z_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->portal.z.current, pos.x, pos.y);
}

void	ft_portal_n_sprite(t_game *game, t_point pos)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->portal.n.current, pos.x, pos.y);
}


void	ft_down_sprite(t_game *game, int draw_x, int draw_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.down_anim.current, draw_x, draw_y);
}

void	ft_up_sprite(t_game *game, int draw_x, int draw_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player.up_anim.current,
		draw_x, draw_y);
}

void	ft_left_sprite(t_game *game, int draw_x, int draw_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.left_anim.current, draw_x, draw_y);
}

void	ft_right_sprite(t_game *game, int draw_x, int draw_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.right_anim.current, draw_x, draw_y);
}
