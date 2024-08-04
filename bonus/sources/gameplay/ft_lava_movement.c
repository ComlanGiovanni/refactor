/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lava_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:43:47 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:26:52 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	move_lava_up(t_game *game, int row, int col)
{
	if (game->map.grid[row - 1][col] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_lava_obstacle(game->map.grid[row - 1][col]))
	{
		if (game->map.grid[row - 1][col] == BOX_CHAR)
			system("cvlc sounds/box_destroyed.wav &");
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row - 1][col] = LAVA_CHAR;
	}
}

void	move_lava_down(t_game *game, int row, int col)
{
	if (game->map.grid[row + 1][col] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_lava_obstacle(game->map.grid[row + 1][col]))
	{
		if (game->map.grid[row + 1][col] == BOX_CHAR)
			system("cvlc sounds/box_destroyed.wav &");
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row + 1][col] = LAVA_CHAR;
	}
}

void	move_lava_left(t_game *game, int row, int col)
{
	if (game->map.grid[row][col - 1] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_lava_obstacle(game->map.grid[row][col - 1]))
	{
		if (game->map.grid[row][col - 1] == BOX_CHAR)
			system("cvlc sounds/box_destroyed.wav &");
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row][col - 1] = LAVA_CHAR;
	}
}

void	move_lava_right(t_game *game, int row, int col)
{
	if (game->map.grid[row][col + 1] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_lava_obstacle(game->map.grid[row][col + 1]))
	{
		if (game->map.grid[row][col + 1] == BOX_CHAR)
			system("cvlc sounds/box_destroyed.wav &");
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row][col + 1] = LAVA_CHAR;
	}
}
