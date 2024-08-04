/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_digits_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:01:57 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:09:55 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_digits_animation(t_game *game)
{
	ft_zero_animation(&game->hud.digits.zero);
	ft_one_animation(&game->hud.digits.one);
	ft_two_animation(&game->hud.digits.two);
	ft_tree_animation(&game->hud.digits.tree);
	ft_four_animation(&game->hud.digits.four);
	ft_five_animation(&game->hud.digits.five);
	ft_six_animation(&game->hud.digits.six);
	ft_seven_animation(&game->hud.digits.seven);
	ft_eight_animation(&game->hud.digits.eight);
	ft_nine_animation(&game->hud.digits.nine);
}

void	ft_zero_animation(t_animation *animation)
{
	static int	frame;

	if (frame == animation->frames)
		animation->current = animation->frame_2;
	else if (frame >= animation->frames * 2)
	{
		animation->current = animation->frame_1;
		frame = FALSE;
	}
	frame += TRUE;
}

void	ft_one_animation(t_animation *animation)
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

void	ft_two_animation(t_animation *animation)
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

void	ft_tree_animation(t_animation *animation)
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

void	ft_four_animation(t_animation *animation)
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


