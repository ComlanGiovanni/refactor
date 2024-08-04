/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:20:05 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:28:35 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_init_camera(t_game *game)
{
	game->camera.current.x = game->player.movement.current_position.x;
	game->camera.current.y = game->player.movement.current_position.y;
	game->camera.target.x = game->player.movement.current_position.x;
	game->camera.target.y = game->player.movement.current_position.y;
	game->camera.shake_intensity = 0.0;
	game->camera.shake_speed = 0.0;
	game->camera.lerp_speed = 0.0;
}

//make position offset ?
//missing t_point for life
// game->hud.storage.x = 200;
// game->hud.storage.y = 300;

void	ft_init_hud_sprites_position(t_game *game)
{
	game->hud.step.x = 90;
	game->hud.step.y = 40;
	game->hud.fps.x = 60;
	game->hud.fps.y = 290;
	game->hud.direction.x = 230;
	game->hud.direction.y = 320;
	game->hud.keys.x = 170;
	game->hud.keys.y = 240;
}

void	ft_init_frames(t_game *game)
{
	game->player.frames = 9;
	game->lava.animation.frames = 24;
	game->key.animation.frames = 6;
	game->wall.animation.frames = 64;
	game->grass.animation.frames = 128;
	game->love.animation.frames = 48;
	game->hud.digits.zero.frames = 64;
	game->door.closed.frames = 24;
	game->door.open.frames = 24;
	game->hud.digits.one.frames = 7;
	game->hud.digits.two.frames = 12;
	game->hud.digits.tree.frames = 7;
	game->hud.digits.four.frames = 12;
	game->hud.digits.five.frames = 7;
	game->hud.digits.six.frames = 12;
	game->hud.digits.seven.frames = 7;
	game->hud.digits.eight.frames = 7;
	game->hud.digits.nine.frames = 78;
	game->box.animation.frames = 42;
	game->portal.n.frames = 24;
	game->portal.z.frames = 24;
}

void	ft_init_fps(t_game *game)
{
	clock_gettime(1, &game->fps.current_time);
	game->fps.frame_count = 0;
	game->fps.fps = 0.0;
	game->fps.last_time = game->fps.current_time;
	game->fps.elapsed = 0.0;
}

/**
 * @brief
 *
 * 		init to 0 height step
 * 				and init width to the
 * 		len of line send to the fct
 * 					the copy the line in map
 *game->window.img = NULL;
 * @param game
 * @param line
 */

void	ft_init_map_info(t_game *game, char *line)
{
	game->height = FALSE;
	game->width = ft_strlen(line) - TRUE;
	game->map.map_str = ft_custom_strdup(line);
	game->window.width = 0x0;
	game->window.height = 0x0;
	game->window.size_line = 0x0;
	game->window.bpp = 0x0;
	game->window.endian = 0x0;
	free(line);
}

void	ft_init_game_info(t_game *game)
{
	game->map.info.nbr_player = FALSE;
	game->map.info.nbr_key = FALSE;
	game->map.info.nbr_exit = FALSE;
	game->map.info.nbr_lava = FALSE;
	game->map.info.nbr_love = FALSE;
	game->map.info.nbr_wall = TRUE;
	game->map.info.nbr_void = FALSE;
	game->map.info.nbr_box = FALSE;
	game->map.info.nbr_border = FALSE;
	game->map.info.nbr_portal_1 = FALSE;
	game->map.info.nbr_portal_2 = FALSE;
	game->map.border_width = BORDERS_WIDTH;
}


