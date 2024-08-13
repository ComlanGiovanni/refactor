/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:05:20 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 20:24:16 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_camera_shake(t_game *game)
{
	double	shake_offset_x;
	double	shake_offset_y;
	double	shake_time;
	double	shake_intensity;
	double	shake_speed;
	double	shake_duration;

	shake_intensity = 30;
	shake_speed = 1.0;
	shake_offset_x = sin(game->fps.elapsed * shake_speed) * shake_intensity;
	shake_duration = 4.84;
	shake_offset_y = 0.0;
	shake_time = fmod(game->fps.elapsed, shake_duration);
	shake_offset_y = sin(shake_time * shake_speed) * shake_intensity;
	game->camera.current.x += shake_offset_x;
	game->camera.current.y += shake_offset_y;
}

//(double)
void	ft_update_camera(t_game *game)
{
	game->camera.lerp_speed = 0.02;
	game->camera.target.x = (game->player.movement.current_position.x
			* IMG_SIZE) - ((game->width * IMG_SIZE) / 4);
	game->camera.target.y = (game->player.movement.current_position.y
			* IMG_SIZE) - ((game->height * IMG_SIZE) / 4);
	game->camera.current.x = ft_linear_interpolation(game->camera.lerp_speed,
										game->camera.current.x,
										game->camera.target.x);
	game->camera.current.y = ft_linear_interpolation(game->camera.lerp_speed,
										game->camera.current.y,
										game->camera.target.y);
}

// double	ft_lerp(double start, double end, double t)
// {
// 	return (start + t * (end - start));
// }

// Fonction d'interpolation linéaire
/*
t: This is the interpolation factor,
typically permutation_index_lower_left value between 0 and 1.
It determines the weight of each of the two values being interpolated.
permutation_index_lower_left: The starting value.
permutation_index_upper_left: The ending value.
The function calculates permutation_index_lower_left weighted average
of permutation_index_lower_left and permutation_index_upper_left. When t is 0,
	the function returns permutation_index_lower_left. When t is 1,
	it returns permutation_index_upper_left. For values of t between 0 and 1,
	the function returns permutation_index_lower_left value that is
	proportionally between permutation_index_lower_left and
	permutation_index_upper_left.
*/
float	ft_linear_interpolation(float interpolation_factor, float start,
		float end)
{
	return (start + interpolation_factor * (end - start));
}
