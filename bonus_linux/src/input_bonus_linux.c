/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus_linux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:11 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 17:20:31 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 * 		this fct will be trigger by mlx_hook in the main
 * 	mlx_hook is alway listening if there i KEY_PRESS -> 2 x_event
 * the send it to input manager as a int, look at the mlx_hook
 * 	prototype, the here i manager wasd up down left right arrow
 * 				and also 4 8 6 2 pav num
 * 		those are set in the enumeration in .h  t_key_code
 *
 * for each direction we call the good fct and seed the t_game pointer
 * 			alway returning 0 -> EXIT_SUCCESS
 *
 *
 *  //recup key_code and put in game struct
 *
 * @param key_code
 * @param game
 * @return int
 */
int	ft_input_manager(int key_code, t_game *game)
{
	ft_random_lava_move(game);
	if (key_code == LINUX_ESC_KEY)
		ft_exit_game(game);
	if ((key_code == LINUX_W_KEY || key_code == LINUX_UP_ARROW_KEY
			|| key_code == LINUX_UP_PAV_NUM_KEY))
		ft_input_up(game);
	if ((key_code == LINUX_S_KEY || key_code == LINUX_DOWN_ARROW_KEY
			|| key_code == LINUX_DOWN_PAV_NUM_KEY))
		ft_input_down(game);
	if ((key_code == LINUX_A_KEY || key_code == LINUX_LEFT_ARROW_KEY
			|| key_code == LINUX_LEFT_PAV_NUM_KEY))
		ft_input_left(game);
	if ((key_code == LINUX_D_KEY || key_code == LINUX_RIGHT_ARROW_KEY
			|| key_code == LINUX_RIGHT_PAV_NUM_KEY))
		ft_input_right(game);
	return (EXIT_SUCCESS);
}

// if ((game->fps.current_time.tv_sec - game->fps.last_time.tv_sec) > 1.0)
void	play_movement_sound(t_game *game)
{
	game->player.step++;
	system("cvlc sounds/baba-move.wav &");
}

void	ft_player_take_coin(t_game *game)
{
	game->player.storage++;
	system("cvlc sounds/babatakekey.wav &");
}

void	ft_player_take_life(t_game *game)
{
	game->player.life++;
	system("cvlc sounds/baba_take_life.wav &");
}

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

void	ft_player_get_hit(t_game *game)
{
	game->player.life--;
	system("cvlc sounds/baba_take_damage.wav &");
	ft_camera_shake(game);
}

void	ft_baba_forbidden(t_game *game)
{
	ft_camera_shake(game);
}

void	ft_move_box(t_game *game, int new_y, int new_x, int dir_y, int dir_x)
{
	char next_tile;

	next_tile = game->map.grid[new_y + dir_y][new_x + dir_x];

	// Vérifie si la box peut être déplacée dans la direction donnée
	if (next_tile == VOID_CHAR && (next_tile != LOVE_CHAR && next_tile != EXIT_CHAR
		&& next_tile != KEY_CHAR))
	{
		game->map.grid[new_y + dir_y][new_x + dir_x] = BOX_CHAR;
		game->map.grid[new_y][new_x] = VOID_CHAR;
		system("cvlc sounds/box_move.wav &");
	}
}


void	ft_handle_tile_action(t_game *game, char next_tile)
{
	if (next_tile == LOVE_CHAR)
	{
		if (game->player.life < 6)
			ft_player_take_life(game);
		else
		{
			ft_baba_forbidden(game);
			return ;
		}
	}
	if (next_tile == KEY_CHAR)
		ft_player_take_coin(game);
	if (next_tile == LAVA_CHAR)
		ft_player_get_hit(game);
	if (next_tile == EXIT_CHAR
		&& game->map.info.nbr_key == game->player.storage)
		ft_win_game(game);
}

void	ft_teleport_player(t_game *game, int y, int x)
{
	t_point		destination;

	if (game->map.grid[y][x] == 'N')
		destination = game->map.portal_1_pos;
	else if (game->map.grid[y][x] == 'Z')
		destination = game->map.portal_2_pos;
	else
		return ;

	if (destination.y != -1 && destination.x != -1)
	{
		game->map.grid[y][x] = VOID_CHAR;
		system("cvlc sounds/teleportation.wav &");
		game->map.grid[destination.y][destination.x] = PLAYER_CHAR;
		game->player.movement.current_position.y = destination.y;
		game->player.movement.current_position.x = destination.x;
		//ft_camera_zoom(game, 2.5, 4.2);
		//game->map.grid[destination.y][destination.x] = VOID_CHAR;
		//play_teleport_sound(game);
	}
}

void	ft_move_up(t_game *game)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	if (y > 0)
	{
		next_tile = game->map.grid[y - 1][x];
		ft_handle_tile_action(game, next_tile);
		if (next_tile == BOX_CHAR)
		{
			ft_move_box(game, y - 1, x, -1, 0);
			next_tile = game->map.grid[y - 1][x];
		}
		if (next_tile == 'N' || next_tile == 'Z')
		{
			game->map.grid[y][x] = VOID_CHAR;
			ft_teleport_player(game, y - 1, x);
			return ;
		}
		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR && !(next_tile == EXIT_CHAR
				&& game->map.info.nbr_key != game->player.storage)
			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
		{
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y - 1][x] = PLAYER_CHAR;
			play_movement_sound(game);
			game->player.movement.current_position.y -= 1;
			//ft_handle_tile_action(game, next_tile);
		}
	}
}

void	ft_move_down(t_game *game)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	if (y < game->height - 1)
	{
		next_tile = game->map.grid[y + 1][x];
		ft_handle_tile_action(game, next_tile);
		if (next_tile == BOX_CHAR)
		{
			ft_move_box(game, y + 1, x, 1, 0);
			next_tile = game->map.grid[y + 1][x];
		}
		if (next_tile == 'N' || next_tile == 'Z')
		{
			game->map.grid[y][x] = VOID_CHAR;
			ft_teleport_player(game, y + 1, x);
			return ;
		}
		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR && !(next_tile == EXIT_CHAR
				&& game->map.info.nbr_key != game->player.storage)
			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
		{
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y + 1][x] = PLAYER_CHAR;
			play_movement_sound(game);
			game->player.movement.current_position.y += 1;
			//ft_handle_tile_action(game, next_tile);
		}
	}
}

void	ft_move_left(t_game *game)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	if (x > 0)
	{
		next_tile = game->map.grid[y][x - 1];
		ft_handle_tile_action(game, next_tile);
		if (next_tile == BOX_CHAR)
		{
			ft_move_box(game, y, x - 1, 0, -1);;
			next_tile = game->map.grid[y][x - 1];
		}
		if (next_tile == 'N' || next_tile == 'Z')
		{
			game->map.grid[y][x] = VOID_CHAR;
			ft_teleport_player(game, y, x - 1);
			return ;
		}
		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR && !(next_tile == EXIT_CHAR
				&& game->map.info.nbr_key != game->player.storage)
			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
		{
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y][x - 1] = PLAYER_CHAR;
			play_movement_sound(game);
			game->player.movement.current_position.x -= 1;
			//ft_handle_tile_action(game, next_tile);
		}
	}
}

void	ft_move_right(t_game *game)
{
	int		x;
	int		y;
	char	next_tile;

	x = game->player.movement.current_position.x;
	y = game->player.movement.current_position.y;
	if (x < game->width - 1)
	{
		next_tile = game->map.grid[y][x + 1];
		ft_handle_tile_action(game, next_tile);
		if (next_tile == BOX_CHAR)
		{
			ft_move_box(game, y, x + 1, 0, 1);
			next_tile = game->map.grid[y][x + 1];
		}
		if (next_tile == 'N' || next_tile == 'Z')
		{
			game->map.grid[y][x] = VOID_CHAR;
			ft_teleport_player(game, y, x + 1);
			return ;
		}
		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR && !(next_tile == EXIT_CHAR
				&& game->map.info.nbr_key != game->player.storage)
			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
		{
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y][x + 1] = PLAYER_CHAR;
			play_movement_sound(game);
			game->player.movement.current_position.x += 1;
			//ft_handle_tile_action(game, next_tile);
		}
	}
}
