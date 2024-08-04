/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lava_behaviour_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:25 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 11:43:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

int	ft_is_lava_obstacle(char tile)
{
	return (tile == WALL_CHAR || tile == EXIT_CHAR || tile == KEY_CHAR
		|| tile == LAVA_CHAR || tile == LOVE_CHAR || tile == PLAYER_CHAR
		|| tile == PORTAL_1_CHAR || tile == PORTAL_2_CHAR);
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
				ft_move_lava_up(game, row, col);
			col++;
		}
		row++;
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
				ft_move_lava_down(game, row, col);
			col++;
		}
		row--;
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
				ft_move_lava_left(game, row, col);
			col++;
		}
		row++;
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
				ft_move_lava_right(game, row, col);
			col--;
		}
		row++;
	}
}


