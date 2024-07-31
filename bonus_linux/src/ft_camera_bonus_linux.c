/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_bonus_linux.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:05:20 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/30 12:48:05 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

void	ft_init_camera(t_game *game)
{
	//mettre a 0 pour une fondue sur le personnage au demarrage ?

	game->camera.current.x = game->player.movement.current_position.x;
	game->camera.current.y = game->player.movement.current_position.y;
	game->camera.target.x = game->player.movement.current_position.x;
	game->camera.target.y = game->player.movement.current_position.y;
	game->camera.shake_intensity = 0.0;
	game->camera.shake_speed = 0.0;
	game->camera.lerp_speed = 0.0;
}
