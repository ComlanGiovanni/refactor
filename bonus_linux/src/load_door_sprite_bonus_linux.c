/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_door_sprite_bonus_linux.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:37 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 00:56:44 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

void	ft_load_door_closed_sprites(t_game *game)
{
	int	width;
	int	height;

	game->door.closed.frames = 24;
	game->door.closed.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/door/closed/door_closed_frame_0.xpm",
			&width, &height);
	if (game->door.closed.frame_0 == NULL)
		ft_print_error(DOOR_C_0_XPM_ERROR, game);
	game->door.closed.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/door/closed/door_closed_frame_1.xpm",
			&width, &height);
	if (game->door.closed.frame_1 == NULL)
		ft_print_error(DOOR_C_1_XPM_ERROR, game);
	game->door.closed.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/door/closed/door_closed_frame_2.xpm",
			&width, &height);
	if (game->door.closed.frame_2 == NULL)
		ft_print_error(DOOR_C_2_XPM_ERROR, game);
}

void	ft_load_door_open_sprites(t_game *game)
{
	int	width;
	int	height;

	game->door.open.frames = 24;
	game->door.open.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/door/open/door_open_frame_0.xpm",
			&width, &height);
	if (game->door.open.frame_0 == NULL)
		ft_print_error(DOOR_O_0_XPM_ERROR, game);
	game->door.open.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/door/open/door_open_frame_1.xpm",
			&width, &height);
	if (game->door.open.frame_1 == NULL)
		ft_print_error(DOOR_O_1_XPM_ERROR, game);
	game->door.open.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/door/open/door_open_frame_2.xpm",
			&width, &height);
	if (game->door.open.frame_2 == NULL)
		ft_print_error(DOOR_O_2_XPM_ERROR, game);
}
