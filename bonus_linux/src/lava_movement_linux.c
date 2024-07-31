/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lava_movement_linux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:25 by gicomlan          #+#    #+#             */
/*   Updated: 2024/07/31 16:57:09 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

static int	ft_is_wall_obstacle(char tile)
{
	return (tile == WALL_CHAR || tile == EXIT_CHAR || tile == KEY_CHAR ||
			tile == LAVA_CHAR || tile == LOVE_CHAR || tile == PLAYER_CHAR);
}

static void	move_lava_up(t_game *game, int row, int col)
{
	if (game->map.grid[row - 1][col] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_wall_obstacle(game->map.grid[row - 1][col]))
	{
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row - 1][col] = LAVA_CHAR;
	}
}

void	ft_lava_move_up(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == LAVA_CHAR && row > 0)
				move_lava_up(game, row, col);
			col++;
		}
		row++;
	}
}

static void	move_lava_down(t_game *game, int row, int col)
{
	if (game->map.grid[row + 1][col] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_wall_obstacle(game->map.grid[row + 1][col]))
	{
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row + 1][col] = LAVA_CHAR;
	}
}

void	ft_lava_move_down(t_game *game)
{
	int	row;
	int	col;

	row = game->height - 1;
	while (row >= 0)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == LAVA_CHAR && row < game->height - 1)
				move_lava_down(game, row, col);
			col++;
		}
		row--;
	}
}

static void	move_lava_left(t_game *game, int row, int col)
{
	if (game->map.grid[row][col - 1] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_wall_obstacle(game->map.grid[row][col - 1]))
	{
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row][col - 1] = LAVA_CHAR;
	}
}

void	ft_lava_move_left(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == LAVA_CHAR && col > 0)
				move_lava_left(game, row, col);
			col++;
		}
		row++;
	}
}

static void	move_lava_right(t_game *game, int row, int col)
{
	if (game->map.grid[row][col + 1] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_wall_obstacle(game->map.grid[row][col + 1]))
	{
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row][col + 1] = LAVA_CHAR;
	}
}

void	ft_lava_move_right(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->height)
	{
		col = game->width - 1;
		while (col >= 0)
		{
			if (game->map.grid[row][col] == LAVA_CHAR && col < game->width - 1)
				move_lava_right(game, row, col);
			col--;
		}
		row++;
	}
}


/**
 * @brief
 *
 * 						Comment for the whole file
 *
 * 			so now that the direction of the lava is set
 * 				in ft_random_lava_move we can now
 * 					check to direction to go aka the fct to call,
 * 					there its the same logic as
 * 			the management of the player input,
 * 						we loop in all the map and if we found a
 * 		lava we apply this rule, if there is not wall exit key lava key
 * 				love or player char aka everything
 * 						except void we can move by change the previous
 * 					char L(asset because we are alway printing
 * 				asset by the map str) by void and the next
 * 					by the lava char, then if we face a player char
 * 			he lose life and the lava disappear to
 * 						because 0 aka void ground
 *
 *
 * @param game
 */

void	ft_move_lava(t_game *game)
{
	if (game->lava.move == 'u')
		ft_lava_move_up(game);
	if (game->lava.move == 'd')
		ft_lava_move_down(game);
	if (game->lava.move == 'l')
		ft_lava_move_left(game);
	if (game->lava.move == 'r')
		ft_lava_move_right(game);
}


// static int	ft_lava_is_obstacle(char tile)
// {
// 	return (tile == WALL_CHAR || tile == EXIT_CHAR || tile == KEY_CHAR ||
// 			tile == LAVA_CHAR || tile == LOVE_CHAR || tile == PLAYER_CHAR);
// }

// void	ft_lava_move_up(t_game *game)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	while (row < game->height)
// 	{
// 		col = 0;
// 		while (col < game->width)
// 		{
// 			if (game->map.grid[row][col] == LAVA_CHAR)
// 			{
// 				if (row > 0 && game->map.grid[row - 1][col] == PLAYER_CHAR)
// 				{
// 					ft_player_get_hit(game);
// 					game->map.grid[row][col] = VOID_CHAR;
// 				}
// 				if (row > 0 && game->map.grid[row - 1][col] != WALL_CHAR
// 					&& game->map.grid[row - 1][col] != EXIT_CHAR
// 					&& game->map.grid[row - 1][col] != KEY_CHAR
// 					&& game->map.grid[row - 1][col] != LAVA_CHAR
// 					&& game->map.grid[row - 1][col] != KEY_CHAR
// 					&& game->map.grid[row - 1][col] != LOVE_CHAR
// 					&& game->map.grid[row - 1][col] != PLAYER_CHAR)
// 				{
// 					game->map.grid[row][col] = VOID_CHAR;
// 					game->map.grid[row - 1][col] = LAVA_CHAR;
// 				}
// 			}
// 			col++;
// 		}
// 		row++;
// 	}
// }

// void	ft_lava_move_down(t_game *game)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	while (row < game->height)
// 	{
// 		col = 0;
// 		while (col < game->width)
// 		{
// 			if (game->map.grid[row][col] == LAVA_CHAR)
// 			{
// 				if (row < game->height - 1 && game->map.grid[row + 1][col] == PLAYER_CHAR)
// 				{
// 					ft_player_get_hit(game);
// 					game->map.grid[row][col] = VOID_CHAR;
// 				}
// 				if (row < game->height - 1 && game->map.grid[row + 1][col] != WALL_CHAR
// 					&& game->map.grid[row + 1][col] != EXIT_CHAR
// 					&& game->map.grid[row + 1][col] != KEY_CHAR
// 					&& game->map.grid[row + 1][col] != LAVA_CHAR
// 					&& game->map.grid[row + 1][col] != KEY_CHAR
// 					&& game->map.grid[row + 1][col] != LOVE_CHAR
// 					&& game->map.grid[row + 1][col] != PLAYER_CHAR)
// 				{
// 					game->map.grid[row][col] = VOID_CHAR;
// 					game->map.grid[row + 1][col] = LAVA_CHAR;
// 				}
// 			}
// 			col++;
// 		}
// 		row++;
// 	}
// }

// void	ft_lava_move_left(t_game *game)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	while (row < game->height)
// 	{
// 		col = 0;
// 		while (col < game->width)
// 		{
// 			if (game->map.grid[row][col] == LAVA_CHAR)
// 			{
// 				if (col > 0 && game->map.grid[row][col - 1] == PLAYER_CHAR)
// 				{
// 					ft_player_get_hit(game);
// 					game->map.grid[row][col] = VOID_CHAR;
// 				}
// 				if (col > 0 && game->map.grid[row][col - 1] != WALL_CHAR
// 					&& game->map.grid[row][col - 1] != EXIT_CHAR
// 					&& game->map.grid[row][col - 1] != KEY_CHAR
// 					&& game->map.grid[row][col - 1] != LAVA_CHAR
// 					&& game->map.grid[row][col - 1] != KEY_CHAR
// 					&& game->map.grid[row][col - 1] != LOVE_CHAR
// 					&& game->map.grid[row][col - 1] != PLAYER_CHAR)
// 				{
// 					game->map.grid[row][col] = VOID_CHAR;
// 					game->map.grid[row][col - 1] = LAVA_CHAR;
// 				}
// 			}
// 			col++;
// 		}
// 		row++;
// 	}
// }

// void	ft_lava_move_right(t_game *game)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	while (row < game->height)
// 	{
// 		col = 0;
// 		while (col < game->width)
// 		{
// 			if (game->map.grid[row][col] == LAVA_CHAR)
// 			{
// 				if (col < game->width - 1 && game->map.grid[row][col + 1] == PLAYER_CHAR)
// 				{
// 					ft_player_get_hit(game);
// 					game->map.grid[row][col] = VOID_CHAR;
// 				}
// 				if (col < game->width - 1 && game->map.grid[row][col + 1] != WALL_CHAR
// 					&& game->map.grid[row][col + 1] != EXIT_CHAR
// 					&& game->map.grid[row][col + 1] != KEY_CHAR
// 					&& game->map.grid[row][col + 1] != LAVA_CHAR
// 					&& game->map.grid[row][col + 1] != KEY_CHAR
// 					&& game->map.grid[row][col + 1] != LOVE_CHAR
// 					&& game->map.grid[row][col + 1] != PLAYER_CHAR)
// 				{
// 					game->map.grid[row][col] = VOID_CHAR;
// 					game->map.grid[row][col + 1] = LAVA_CHAR;
// 				}
// 			}
// 			col++;
// 		}
// 		row++;
// 	}
// }
