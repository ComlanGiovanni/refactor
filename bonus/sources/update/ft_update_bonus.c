/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:02:13 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/13 01:59:58 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//make a fct to return the good usleep in fonction of the limitation
//fps limiation usleep(game->fps.limitation); usleep(15000);

void move_pawn(t_game *game);
//void move_pawn_to_target(t_pawn_movement *pawn, t_game *game);
void update_grid(t_game *game, t_point old_pos, t_point new_pos, char pawn_char, char void_char);
int is_obstacle(char **grid, t_point pos, char player_char);
void ft_find_pawn_positions(t_game *game);
void ft_init_pawns_array(t_game *game);
void find_farthest_position_for_pawn(t_game *game);
t_point calculate_farthest_position(t_point start_position, const char *direction, t_game *game);
int ft_is_position_free_for_pawn(char **grid, t_point pos);
t_point get_next_position(t_point current, const char *direction);

void	ft_draw_pause_message(t_game *game)
{
	if (game->paused)
		mlx_string_put(game->mlx, game->win, 300, 200, 0xFFFFFF, "PAUSED");
}

int	ft_update(t_game *game)
{
	if (game->paused)
	{
		ft_draw_pause_message(game);
		return (EXIT_SUCCESS); // Do nothing if the game is paused
	}
	int x, y;
	mlx_mouse_get_pos(game->mlx, game->win, &x, &y);
	// system("clear");
	// ft_printf("=[%d]=", x);
	// ft_printf("=[%d]=", y);
	ft_update_fps(game);
	ft_update_camera(game);
	ft_play_animation(game);
	//ft_draw_sprite(game, game->grass.animation.current, 500, 500);
	if ((game->map.info.nbr_key == game->player.storage) && !game->finished)
	{
		game->finished = 1;
		system("aplay sounds/theme/level_finished.wav &");
	}
	mlx_clear_window(game->mlx, game->win);
	ft_put_sprites_by_line(game);
	//mlx_put_image_to_window(game->mlx, game->win, game->window.img, 0, 0);
	//mlx_destroy_image(game->mlx, game->window.img);
	//mlx_do_sync(game->mlx);
	ft_print_info_on_window(game);
	//system("clear");
	//ft_print_display_grid(game->map.grid);
	return (EXIT_SUCCESS);
}

void	ft_update_fps(t_game *game)
{
	clock_gettime(1, &game->fps.current_time);
	game->fps.elapsed = (game->fps.current_time.tv_sec
			- game->fps.last_time.tv_sec) +
		(game->fps.current_time.tv_nsec - game->fps.last_time.tv_nsec) / 1e9;
	game->fps.elapsed_time = (game->fps.current_time.tv_sec
			- game->fps.last_time.tv_sec) +
		(game->fps.current_time.tv_nsec - game->fps.last_time.tv_nsec) / 1e9;
	game->fps.frame_count++;
	if (game->fps.elapsed >= 1.0)
	{
		game->fps.fps = game->fps.frame_count / game->fps.elapsed;
		game->fps.frame_count = 0;
		game->fps.last_time = game->fps.current_time;
	}
	if (game->map.info.nbr_pawn && game->fps.elapsed_time >= 1.0) {
            // Perform the desired action
            //printf("One second has passed!\n");
			// srand((unsigned int)time(NULL));
			// int tic_or_tac = rand() % 2;
			if (game->fps.last_time.tv_sec % 2)
				system("aplay sounds/special-effects/clock_tic.wav &");
			else
				system("aplay sounds/special-effects/clock_tac.wav &");
			move_pawn(game);
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

// t_point	ft_find_pos_char_in_new_grid(char **tab, t_point size, char c)
// {
// 	int	x;
// 	int	y;

// 	if (!tab || size.x <= 0 || size.y <= 0)
// 		return ((t_point){-1, -1});
// 	y = 0;
// 	while (y < size.y)
// 	{
// 		if (tab[y] == NULL)
// 			return ((t_point){-1, -1});
// 		x = 0;
// 		while (x < size.x)
// 		{
// 			if (tab[y][x] == '\0')
// 				break ;
// 			if (tab[y][x] == c)
// 				return ((t_point){x, y});
// 			x++;
// 		}
// 		y++;
// 	}
// 	return ((t_point){-1, -1});
// }

void	ft_update_map_positions(t_game *game)
{
	game->map.start = ft_find_pos_char(game->map.grid, game->map.size,
			PLAYER_CHAR);
	game->map.end = ft_find_pos_char(game->map.grid, game->map.size, EXIT_CHAR);
	game->map.portal_1_pos = ft_find_pos_char(game->map.grid, game->map.size,
			PORTAL_1_CHAR);
	game->map.portal_2_pos = ft_find_pos_char(game->map.grid, game->map.size,
			PORTAL_2_CHAR);
	if ((game->map.start.x == -1 && game->map.start.y == -1)
		|| (game->map.end.x == -1 && game->map.end.y == -1))
		ft_free_and_print(game->map.matrice, game, NO_POSITION_FOUND);
}
