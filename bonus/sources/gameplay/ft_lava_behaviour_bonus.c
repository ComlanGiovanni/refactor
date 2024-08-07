/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lava_behaviour_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:25 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/07 20:31:35 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_direction_keke_after_launch(t_game *game)
{
	static int	random;

	srand(time(0));
	random = rand() % 4;
	if (random == 0x0)
		game->keke.direction = 'u';
	if (random == 0x1)
		game->keke.direction = 'd';
	if (random == 0x2)
		game->keke.direction = 'l';
	if (random == 0x3)
		game->keke.direction = 'r';
}

int	ft_is_keke_obstacle(char tile)
{
	return (tile == WALL_CHAR || tile == EXIT_CHAR || tile == KEY_CHAR
		|| tile == KEKE_CHAR || tile == LOVE_CHAR || tile == PLAYER_CHAR
		|| tile == PORTAL_1_CHAR || tile == PORTAL_2_CHAR || tile == LAVA_CHAR);
}

void	ft_keke_move_up(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == KEKE_CHAR && row > 0)
				ft_move_keke_up(game, row, col);
			col++;
		}
		row++;
	}
}

void	ft_keke_move_down(t_game *game)
{
	int	row;
	int	col;

	row = game->height - 1;
	while (row >= 0)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == KEKE_CHAR && row < game->height - 1)
				ft_move_keke_down(game, row, col);
			col++;
		}
		row--;
	}
}


void	ft_keke_move_left(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map.grid[row][col] == KEKE_CHAR && col > 0)
				ft_move_keke_left(game, row, col);
			col++;
		}
		row++;
	}
}

void	ft_keke_move_right(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->height)
	{
		col = game->width - 1;
		while (col >= 0)
		{
			if (game->map.grid[row][col] == KEKE_CHAR && col < game->width - 1)
				ft_move_keke_right(game, row, col);
			col--;
		}
		row++;
	}
}


