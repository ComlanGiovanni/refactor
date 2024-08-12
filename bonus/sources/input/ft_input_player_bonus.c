/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:11 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 15:42:35 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// void move_pawn(t_game *game);
// //void move_pawn_to_target(t_pawn_movement *pawn, t_game *game);
// void update_grid(t_game *game, t_point old_pos, t_point new_pos, char pawn_char, char void_char);
// int is_obstacle(char **grid, t_point pos, char player_char);
// void ft_find_pawn_positions(t_game *game);
// void ft_init_pawns_array(t_game *game);
// void find_farthest_position_for_pawn(t_game *game);
// t_point calculate_farthest_position(t_point start_position, const char *direction, t_game *game);
// int ft_is_position_free_for_pawn(char **grid, t_point pos);
// t_point get_next_position(t_point current, const char *direction);

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
	//move_pawn(game);
	if (key_code == 112)//make enumaration for input ?abcd
	{ // 'P' key for pause
		game->paused = !game->paused;
		if (game->paused)
			ft_printf("Game Paused\n");
		else
			ft_printf("Game Resumed\n");
		return (EXIT_SUCCESS);
	}
	if (game->paused)
		return (EXIT_SUCCESS);
	if (game->map.info.nbr_keke)
		ft_a_star_keke_movement(game);
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
		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR
			&& !(next_tile == EXIT_CHAR
				&& game->map.info.nbr_key != game->player.storage)
			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
		{
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y - 1][x] = PLAYER_CHAR;
			ft_play_movement_sound(game);
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
		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR
			&& !(next_tile == EXIT_CHAR
				&& game->map.info.nbr_key != game->player.storage)
			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
		{
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y + 1][x] = PLAYER_CHAR;
			ft_play_movement_sound(game);
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
			ft_move_box(game, y, x - 1, 0, -1);
			;
			next_tile = game->map.grid[y][x - 1];
		}
		if (next_tile == 'N' || next_tile == 'Z')
		{
			game->map.grid[y][x] = VOID_CHAR;
			ft_teleport_player(game, y, x - 1);
			return ;
		}
		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR
			&& !(next_tile == EXIT_CHAR
				&& game->map.info.nbr_key != game->player.storage)
			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
		{
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y][x - 1] = PLAYER_CHAR;
			ft_play_movement_sound(game);
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
		if (next_tile != WALL_CHAR && next_tile != BOX_CHAR
			&& !(next_tile == EXIT_CHAR
				&& game->map.info.nbr_key != game->player.storage)
			&& !(next_tile == LOVE_CHAR && game->player.life >= 6))
		{
			game->map.grid[y][x] = VOID_CHAR;
			game->map.grid[y][x + 1] = PLAYER_CHAR;
			ft_play_movement_sound(game);
			game->player.movement.current_position.x += 1;
			//ft_handle_tile_action(game, next_tile);
		}
	}
}
