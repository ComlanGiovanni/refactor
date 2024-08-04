/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:32:50 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:09:57 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_five_animation(t_animation *animation)
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

void	ft_six_animation(t_animation *animation)
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

void	ft_seven_animation(t_animation *animation)
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

void	ft_eight_animation(t_animation *animation)
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

void	ft_nine_animation(t_animation *animation)
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
