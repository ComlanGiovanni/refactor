/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_sprite_bonus_linux.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:43 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 14:15:46 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

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
 * 	same but we change every state of the player
 * 		in can we are facing up down left and right
 *
 * @param player
 */
void	ft_player_animation(t_player *player)
{
	static int	frame;

	if (frame == player->frames)
	{
		player->up_anim.current = player->up_anim.frame_0;
		player->down_anim.current = player->down_anim.frame_1;
		player->left_anim.current = player->left_anim.frame_1;
		player->right_anim.current = player->right_anim.frame_1;
	}
	else if (frame >= player->frames * 2)
	{
		player->up_anim.current = player->up_anim.frame_1;
		player->down_anim.current = player->down_anim.frame_2;
		player->left_anim.current = player->left_anim.frame_2;
		player->right_anim.current = player->right_anim.frame_2;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_load_player_up_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/player/up/player_up_frame_0.xpm",
		"assets/xpm/Bonus/player/up/player_up_frame_1.xpm",
		"assets/xpm/Bonus/player/up/player_up_frame_2.xpm"};
	const char	*error_messages[] = {
		"PLAYER_U_0_ERROR",
		"PLAYER_U_1_ERROR",
		"PLAYER_U_2_ERROR"};

	ft_load_animation_sprites((t_animation *)&(game->player.up_anim), game,
		paths, error_messages);
	ft_load_sprite_frame(&(game->player.up_anim.frame_move), game,
		"assets/xpm/Bonus/player/up/player_up_frame_move.xpm",
		"Generic message error replace soon");
}

void	ft_load_player_down_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/player/down/player_down_frame_0.xpm",
		"assets/xpm/Bonus/player/down/player_down_frame_1.xpm",
		"assets/xpm/Bonus/player/down/player_down_frame_2.xpm"};
	const char	*error_messages[] = {
		"PLAYER_D_0_ERROR",
		"PLAYER_D_1_ERROR",
		"PLAYER_D_2_ERROR"};

	ft_load_animation_sprites((t_animation *)&(game->player.down_anim), game,
		paths, error_messages);
	ft_load_sprite_frame(&(game->player.down_anim.frame_move), game,
		"assets/xpm/Bonus/player/down/player_down_frame_move.xpm",
		"Generic message error replace soon");
}

void	ft_load_player_left_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/player/left/player_left_frame_0.xpm",
		"assets/xpm/Bonus/player/left/player_left_frame_1.xpm",
		"assets/xpm/Bonus/player/left/player_left_frame_2.xpm"};
	const char	*error_messages[] = {
		"PLAYER_L_0_ERROR",
		"PLAYER_L_1_ERROR",
		"PLAYER_L_2_ERROR"};

	ft_load_animation_sprites((t_animation *)&(game->player.left_anim), game,
		paths, error_messages);
	ft_load_sprite_frame(&(game->player.left_anim.frame_move), game,
		"assets/xpm/Bonus/player/left/player_left_frame_move.xpm",
		"Generic message error replace soon");
}

void	ft_load_player_right_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/player/right/player_right_frame_0.xpm",
		"assets/xpm/Bonus/player/right/player_right_frame_1.xpm",
		"assets/xpm/Bonus/player/right/player_right_frame_2.xpm",};
	const char	*error_messages[] = {
		"PLAYER_R_0_ERROR",
		"PLAYER_R_1_ERROR",
		"PLAYER_R_2_ERROR",
	};

	ft_load_animation_sprites((t_animation *)&(game->player.right_anim), game,
		paths, error_messages);
	ft_load_sprite_frame(&(game->player.right_anim.frame_move), game,
		"assets/xpm/Bonus/player/right/player_right_frame_move.xpm",
		"Generic message error replace soon");
}

void	ft_load_portal_z_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/portal/second/portal_2_frame_1.xpm",
		"assets/xpm/Bonus/portal/second/portal_2_frame_0.xpm",
		"assets/xpm/Bonus/portal/second/portal_2_frame_2.xpm",};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon",
	};

	ft_load_animation_sprites((t_animation *)&(game->portal.z), game,
		paths, error_messages);
}

void	ft_load_portal_n_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/portal/first/portal_1_frame_1.xpm",
		"assets/xpm/Bonus/portal/first/portal_1_frame_0.xpm",
		"assets/xpm/Bonus/portal/first/portal_1_frame_2.xpm",};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon",
	};

	ft_load_animation_sprites((t_animation *)&(game->portal.n), game,
		paths, error_messages);
}
