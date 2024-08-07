/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_keke_assets_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:46:45 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/07 13:44:40 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_keke_sprites(t_game *game, int width, int height,
		t_point sprite_pos)
{
	if (game->map.grid[height][width] == KEKE_CHAR)
	{
		if (game->keke.direction == 'd')
			ft_keke_down_sprite(game, sprite_pos.x, sprite_pos.y);
		else if (game->keke.direction == 'u')
			ft_keke_up_sprite(game, sprite_pos.x, sprite_pos.y);
		else if (game->keke.direction == 'l')
			ft_keke_left_sprite(game, sprite_pos.x, sprite_pos.y);
		else if (game->keke.direction == 'r')
			ft_keke_right_sprite(game, sprite_pos.x, sprite_pos.y);
	}
}

void	ft_keke_down_sprite(t_game *game, int draw_x, int draw_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->keke.down_anim.current, draw_x, draw_y);
}

void	ft_keke_up_sprite(t_game *game, int draw_x, int draw_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->keke.up_anim.current,
		draw_x, draw_y);
}

void	ft_keke_left_sprite(t_game *game, int draw_x, int draw_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->keke.left_anim.current, draw_x, draw_y);
}

void	ft_keke_right_sprite(t_game *game, int draw_x, int draw_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->keke.right_anim.current, draw_x, draw_y);
}
