/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_world_assets_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:12:28 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/09 17:15:17 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_ground_sprites(t_game *game)
{
	int	width;
	int	height;

	game->map.ground = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/ground/ground.xpm", &width, &height);
	if (game->map.ground == NULL)
		ft_print_error(GROUND_XPM_ERROR, game);
}

void	ft_load_borders_sprite(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/grass/grass_frame_0.xpm",
		"assets/xpm/Bonus/grass/grass_frame_1.xpm",
		"assets/xpm/Bonus/grass/grass_frame_0.xpm"};
	const char	*error_messages[] = {
		GRASS_0_XPM_ERROR,
		GRASS_1_XPM_ERROR,
		GRASS_2_XPM_ERROR};

	ft_load_animation_sprites(&(game->grass.animation), game, paths,
		error_messages);
}

void	ft_load_wall_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/wall/wall_frame_0.xpm",
		"assets/xpm/Bonus/wall/wall_frame_1.xpm",
		"assets/xpm/Bonus/wall/wall_frame_2.xpm"};
	const char	*error_messages[] = {
		WALL_0_XPM_ERROR,
		WALL_1_XPM_ERROR,
		WALL_2_XPM_ERROR};

	ft_load_animation_sprites(&(game->wall.animation), game, paths,
		error_messages);
}

void	ft_load_pawn_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/pawn/pawn_frame_0.xpm",
		"assets/xpm/Bonus/pawn/pawn_frame_1.xpm",
		"assets/xpm/Bonus/pawn/pawn_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message change soon",
		"Generic message change soon",
		"Generic message change soon"};

	ft_load_animation_sprites(&(game->pawn.animation), game, paths,
		error_messages);
}
