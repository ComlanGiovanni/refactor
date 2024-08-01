/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus_linux.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:10:53 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 14:02:48 by gicomlan         ###   ########.fr       */
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

static void	ft_update_animation(t_animation *animation, int *frame)
{
	if (*frame == animation->frames)
		animation->current = animation->frame_1;
	else if (*frame >= animation->frames * 2)
	{
		animation->current = animation->frame_2;
		*frame = 0;
	}
}

void	ft_wall_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_update_animation(animation, &frame);
	frame++;
}

void	ft_lava_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_update_animation(animation, &frame);
	frame++;
}

void	ft_key_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_update_animation(animation, &frame);
	frame++;
}

void	ft_love_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_update_animation(animation, &frame);
	frame++;
}

void	ft_grass_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_update_animation(animation, &frame);
	frame++;
}

void	ft_box_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_update_animation(animation, &frame);
	frame++;
}

void	ft_portal_n_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_update_animation(animation, &frame);
	frame++;
}

void	ft_portal_z_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_update_animation(animation, &frame);
	frame++;
}
