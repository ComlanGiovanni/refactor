/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:02:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 01:51:52 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//make a fct to return the good usleep in fonction of the limitation
//fps limiation usleep(game->fps.limitation); usleep(15000);

int	ft_update(t_game *game)
{
	ft_update_fps(game);
	ft_update_camera(game);
	ft_play_animation(game);
	//ft_draw_sprite(game, game->grass.animation.current, 500, 500);
	if ((game->map.info.nbr_key == game->player.storage) && !game->finished)
	{
		game->finished = 1;
		system("cvlc sounds/FinishLevel.wav &");
	}
	//mlx_clear_window(game->mlx, game->win);
	ft_put_sprites_by_line(game);
	//ft_put_buffer_image(game);
	//mlx_put_image_to_window(game->mlx, game->win, game->window.img, 0, 0);
    //mlx_destroy_image(game->mlx, game->window.img);
	//mlx_do_sync(game->mlx);
	ft_print_info_on_window(game);
	// system("clear");
	// ft_print_display_grid(game->map.grid);
	return (EXIT_SUCCESS);
}

void	ft_update_fps(t_game *game)
{
	clock_gettime(1, &game->fps.current_time);
	game->fps.elapsed = (game->fps.current_time.tv_sec
			- game->fps.last_time.tv_sec) +
		(game->fps.current_time.tv_nsec - game->fps.last_time.tv_nsec) / 1e9;
	game->fps.frame_count++;
	if (game->fps.elapsed >= 1.0)
	{
		game->fps.fps = game->fps.frame_count / game->fps.elapsed;
		game->fps.frame_count = 0;
		game->fps.last_time = game->fps.current_time;
	}
}

void	ft_update_map_matrice(t_game *game)
{
	if (game->map.matrice != NULL)
		ft_clean_grid_map(game->map.matrice, game->height);
	game->map.matrice = ft_split_map(game);
}

void	ft_update_player_position(t_game *game)
{
	game->player.movement.current_position.x = game->map.start.x;
	game->player.movement.current_position.y = game->map.start.y;
}

void	ft_update_map_positions(t_game *game)
{
	game->map.start = ft_find_pos_char(game->map.grid, game->map.size,
		PLAYER_CHAR);
	game->map.end = ft_find_pos_char(game->map.grid, game->map.size,
		EXIT_CHAR);
	game->map.portal_1_pos = ft_find_pos_char(game->map.grid, game->map.size,
		PORTAL_1_CHAR);
	game->map.portal_2_pos = ft_find_pos_char(game->map.grid, game->map.size,
		PORTAL_2_CHAR);
}
