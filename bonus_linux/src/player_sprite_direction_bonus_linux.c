/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite_direction_bonus_linux.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:12:17 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/31 18:12:30 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 * 					see ft_put_all_sprites_to_line
 * 			because its only because of 25 line norm we here
 *
 * 	But we print but the direction the good loade fram of player move
 * this frame_0 is alway changing
 * in the animation_bonus fct for the iddle anim
 *
 * @param game
 * @param width
 * @param height
 */
void	ft_player_sprite_call(t_game *game, int width, int height,
		t_point sprite_pos)
{
    if (game->map.grid[height][width] == PLAYER_CHAR) {
        if (game->player.movement.direction == 'd')
            ft_down_sprite(game, sprite_pos.x, sprite_pos.y);
        else if (game->player.movement.direction == 'u')
            ft_up_sprite(game, sprite_pos.x, sprite_pos.y);
        else if (game->player.movement.direction == 'l')
            ft_left_sprite(game, sprite_pos.x, sprite_pos.y);
        else if (game->player.movement.direction == 'r')
            ft_right_sprite(game, sprite_pos.x, sprite_pos.y);
    }
}

/**
 * @brief
 *
 * 	25 line norm small fct because of long struct name and inception
 *
 * @param game
 * @param width
 * @param height
 */
void	ft_down_sprite(t_game *game, int draw_x, int draw_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.down_anim.current, draw_x, draw_y);
}

void	ft_up_sprite(t_game *game, int draw_x, int draw_y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.up_anim.current, draw_x, draw_y);
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
