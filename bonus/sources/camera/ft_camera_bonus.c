/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:05:20 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 14:49:56 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//Use a few terms of the Taylor series for approximation
double	ft_sin(double x)
{
	double	current_term;
	double	sine_sum;
	int		factorial_index;
	int		iteration;

	current_term = x;
	sine_sum = x;
	factorial_index = 1;
	iteration = 1;
	while (iteration <= 10)
	{
		current_term *= -x * x / ((2 * factorial_index)
				* (2 * factorial_index + 1));
		sine_sum += current_term;
		factorial_index++;
		iteration++;
	}
	return (sine_sum);
}

double	ft_fmod(double x, double y)
{
	if (y == 0.0)
		return (0.0);
	return (x - y * (int)(x / y));
}

void	ft_camera_shake(t_game *game)
{
	const double	shake_intensity = 30.0;
	const double	shake_speed = 1.0;
	const double	shake_duration = 4.84;
	t_point			shake_offset;

	shake_offset.x = ft_sin(game->fps.elapsed * shake_speed) * shake_intensity;
	shake_offset.y = ft_sin(ft_fmod(game->fps.elapsed, shake_duration)
			* shake_speed) * shake_intensity;
	game->camera.current.x += shake_offset.x;
	game->camera.current.y += shake_offset.y;
}

// void	ft_camera_shake(t_game *game)
// {
// 	double	shake_offset_x;
// 	double	shake_offset_y;
// 	double	shake_time;
// 	double	shake_intensity;
// 	double	shake_speed;
// 	double	shake_duration;

// 	shake_intensity = 30;
// 	shake_speed = 1.0;
// 	shake_offset_x = sin(game->fps.elapsed * shake_speed) * shake_intensity;
// 	shake_duration = 4.84;
// 	shake_offset_y = 0.0;
// 	shake_time = fmod(game->fps.elapsed, shake_duration);
// 	shake_offset_y = sin(shake_time * shake_speed) * shake_intensity;
// 	game->camera.current.x += shake_offset_x;
// 	game->camera.current.y += shake_offset_y;
// }

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
