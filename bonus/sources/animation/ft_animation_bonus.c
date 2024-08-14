/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:10:53 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/13 22:10:25 by gicomlan         ###   ########.fr       */
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

void	ft_crab_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_foliage_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_bog_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_snail_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_pillar_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_hedge_animation(t_animation *animation)
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
	ft_crab_animation(&game->crab.animation);
	ft_foliage_animation(&game->foliage.animation);
	ft_bog_animation(&game->bog.animation);
	ft_snail_animation(&game->snail.animation);
	ft_pillar_animation(&game->pillar.animation);
	ft_hedge_animation(&game->hedge.animation);
}

void	ft_alphabet_a_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_b_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_c_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_d_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_e_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_f_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_g_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_h_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_i_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_j_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_k_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_l_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_m_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_n_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_o_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_p_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_q_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_r_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_s_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_t_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_u_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_v_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_w_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_x_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_y_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_alphabet_z_animation(t_animation *animation)
{
	static int	frame;

	frame = 0;
	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_odd_alphabet_animation(t_game *game)
{
	ft_alphabet_a_animation(&game->hud.alphabet.a);
	ft_alphabet_c_animation(&game->hud.alphabet.c);
	ft_alphabet_e_animation(&game->hud.alphabet.e);
	ft_alphabet_g_animation(&game->hud.alphabet.g);
	ft_alphabet_i_animation(&game->hud.alphabet.i);
	ft_alphabet_k_animation(&game->hud.alphabet.k);
	ft_alphabet_m_animation(&game->hud.alphabet.m);
	ft_alphabet_o_animation(&game->hud.alphabet.o);
	ft_alphabet_q_animation(&game->hud.alphabet.q);
	ft_alphabet_s_animation(&game->hud.alphabet.s);
	ft_alphabet_u_animation(&game->hud.alphabet.u);
	ft_alphabet_w_animation(&game->hud.alphabet.w);
	ft_alphabet_y_animation(&game->hud.alphabet.y);
}

void	ft_even_alphabet_animation(t_game *game)
{
	ft_alphabet_b_animation(&game->hud.alphabet.b);
	ft_alphabet_d_animation(&game->hud.alphabet.d);
	ft_alphabet_f_animation(&game->hud.alphabet.f);
	ft_alphabet_h_animation(&game->hud.alphabet.h);
	ft_alphabet_j_animation(&game->hud.alphabet.j);
	ft_alphabet_l_animation(&game->hud.alphabet.l);
	ft_alphabet_n_animation(&game->hud.alphabet.n);
	ft_alphabet_p_animation(&game->hud.alphabet.p);
	ft_alphabet_r_animation(&game->hud.alphabet.r);
	ft_alphabet_t_animation(&game->hud.alphabet.t);
	ft_alphabet_v_animation(&game->hud.alphabet.v);
	ft_alphabet_x_animation(&game->hud.alphabet.x);
	ft_alphabet_z_animation(&game->hud.alphabet.z);
}

void	ft_alphabet_animation(t_game *game)
{
	ft_odd_alphabet_animation(game);
	ft_even_alphabet_animation(game);
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
	ft_alphabet_animation(game);
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
