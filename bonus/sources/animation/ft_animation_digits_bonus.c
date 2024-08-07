/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_digits_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 04:01:57 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/06 23:38:04 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_zero_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_one_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_two_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_tree_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}

void	ft_four_animation(t_animation *animation)
{
	static int	frame = 0;

	ft_generic_animation(animation, &frame);
	frame++;
}


