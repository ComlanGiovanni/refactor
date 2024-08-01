/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:06 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 04:29:12 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 * 	Free of last minutes, need to read the project again for better free fct
 * 	we need to free all the image load in sprites before so we check and free
 * 	then the map in str (alway check if exist)
 * 	then we destroy the game (mlx, win)
 * 	then the display (mlx)
 * 	and at the end we need to free the mlx and the game we malloc in the main
 *
 *
 * @param game
 */
void	ft_free_all(t_game *game)
{
	mlx_loop_end(game->mlx);
	ft_free_animation(game);
	if (game->map.map_str)
		free(game->map.map_str);
	if (game->map.grid)
		ft_clean_grid_map(game->map.grid, game->height);
	ft_free_mlx(game);
}

void	ft_free_sprite_frame(void **frame, void *mlx)
{
	if (*frame)
	{
		mlx_destroy_image(mlx, *frame);
		*frame = NULL;
	}
}

void	ft_free_ground(t_game *game)
{
	ft_free_sprite_frame((void **)&game->map.ground, game->mlx);
}
