/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fct_bonus_linux.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:17 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 00:55:36 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 * 		those fct are use in ft_input_manager in input_bonus.c
 * 				just game design game feeling we change the
 * 			player curent sprite aka the only one use as primary
 * 		frame_0 et the loaded sprit move int load player sprite bonus
 * 		we is use only when the player more or try to move so it why
 * 			when change the frame when we press the key so signal to to
 * 		true gamer that is input is well register but not et step varaible
 * 		we change the direction map player info to the direction we press
 * 			for the print in the console and the screen
 * 		ft_put_all_sprites_to_line/ft_player_sprite_call need it too
 * 	 because we call that first fct everytime to print all the char of strmap
 *
 * @param game
 */

void	ft_input_up(t_game *game)
{
	game->player.up_anim.current = game->player.up_anim.frame_move;
	game->player.movement.direction = 'u';
	game->player.movement.moved = TRUE;
	ft_move_up(game);
}

void	ft_input_down(t_game *game)
{
	game->player.down_anim.current = game->player.down_anim.frame_move;
	game->player.movement.direction = 'd';
	game->player.movement.moved = TRUE;
	ft_move_down(game);
}

void	ft_input_left(t_game *game)
{
	game->player.left_anim.current = game->player.left_anim.frame_move;
	game->player.movement.direction = 'l';
	game->player.movement.moved = TRUE;
	ft_move_left(game);
}

void	ft_input_right(t_game *game)
{
	game->player.right_anim.current = game->player.right_anim.frame_move;
	game->player.movement.direction = 'r';
	game->player.movement.moved = TRUE;
	ft_move_right(game);
}
