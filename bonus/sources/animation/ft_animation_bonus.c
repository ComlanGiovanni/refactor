/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:10:53 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 22:34:08 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_tree_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_trees_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_reed_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_husks_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_fungus_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_fungi_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_flower_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_algae_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_water_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_borders_animation(t_game *game)
{
	ft_grass_animation(&game->grass.animation);
	ft_tree_animation(&game->tree.animation);
	ft_trees_animation(&game->trees.animation);
	ft_reed_animation(&game->reed.animation);
	ft_husks_animation(&game->husks.animation);
	ft_fungus_animation(&game->fungus.animation);
	ft_fungi_animation(&game->fungi.animation);
	ft_flower_animation(&game->flower.animation);
	ft_algae_animation(&game->algae.animation);
	ft_water_animation(&game->water.animation);
}

void	ft_play_animation(t_game *game)
{
	ft_wall_animation(&game->wall.animation);
	ft_pawn_animation(&game->pawn.animation);
	ft_player_animation(&game->player);
	ft_keke_animation(&game->keke);
	ft_lava_animation(&game->lava.animation);
	ft_key_animation(&game->key.animation);
	ft_box_animation(&game->box.animation);
	ft_portal_n_animation(&game->portal.n);
	ft_portal_z_animation(&game->portal.z);
	ft_door_open_animation(&game->door.open);
	ft_door_closed_animation(&game->door.closed);
	ft_borders_animation(game);
	if (game->player.life == 6)
		game->love.animation.current = game->love.nope;
	else
		ft_love_animation(&game->love.animation);
	ft_digits_animation(game);
}


/**
 * @brief
 *
 * 			Same thing for every animation
 *
 * 	so every x.frames and x.frame * 2
 *  	we change the frame_0 to the 1 when we hit
 * 			the frame fof the object aka frame count
 * 				in the fct, then change it to frame 2
 * 					when we hit the double of the frame
 * 						the reset it to 0 again and again
 *
 *
 * @param door
 */
void	ft_door_open_animation(t_anim_door *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

/**
 * @brief
 *
 * 			Same thing for every animation
 *
 * 	so every x.frames and x.frame * 2
 *  	we change the frame_0 to the 1 when we hit
 * 			the frame fof the object aka frame count
 * 				in the fct, then change it to frame 2
 * 					when we hit the double of the frame
 * 						the reset it to 0 again and again
 *
 *
 * @param door
 */
void	ft_door_closed_animation(t_anim_door *animation)
{
	static int	frame;

	if (frame >= 0 && frame < animation->frames)
		animation->current = animation->frame_0;
	else if (frame >= animation->frames && frame < 2 * animation->frames)
		animation->current = animation->frame_1;
	else if (frame >= 2 * animation->frames)
	{
		animation->current = animation->frame_2;
		frame = -1;
	}
	frame++;
}

// void	ft_generic_animation(t_animation *animation, int *frame)
// {
// 	if (*frame == animation->frames)
// 		animation->current = animation->frame_1;
// 	else if (*frame >= animation->frames * 2)
// 	{
// 		animation->current = animation->frame_2;
// 		*frame = 0;
// 	}
// }

void	ft_generic_animation(t_animation *animation, int *frame)
{
	if (*frame == animation->frames)
		animation->current = animation->frame_1;
	else if (*frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		*frame = FALSE;
	}
}

void	ft_digits_animation(t_game *game)
{
	ft_zero_animation(&game->hud.digits.zero);
	ft_one_animation(&game->hud.digits.one);
	ft_two_animation(&game->hud.digits.two);
	ft_three_animation(&game->hud.digits.three);
	ft_four_animation(&game->hud.digits.four);
	ft_five_animation(&game->hud.digits.five);
	ft_six_animation(&game->hud.digits.six);
	ft_seven_animation(&game->hud.digits.seven);
	ft_eight_animation(&game->hud.digits.eight);
	ft_nine_animation(&game->hud.digits.nine);
}
