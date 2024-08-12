/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keke_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:43:47 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 11:51:35 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_move_keke_up(t_game *game, int row, int col)
{
	if (game->map.grid[row - 1][col] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_keke_obstacle(game->map.grid[row - 1][col]))
	{
		if (game->map.grid[row - 1][col] == BOX_CHAR)
			system("aplay sounds/special-effects/box_destroyed.wav &");
		game->keke.up_anim.current = game->keke.up_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		// game->keke.up_anim.current = game->keke.up_anim.frame_move_1;
		game->map.grid[row - 1][col] = KEKE_CHAR;
		game->keke.up_anim.current = game->keke.up_anim.frame_move_1;
	}
}

void	ft_move_keke_down(t_game *game, int row, int col)
{
	if (game->map.grid[row + 1][col] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_keke_obstacle(game->map.grid[row + 1][col]))
	{
		if (game->map.grid[row + 1][col] == BOX_CHAR)
			system("aplay sounds/special-effects/box_destroyed.wav &");
		game->keke.down_anim.current = game->keke.down_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row + 1][col] = KEKE_CHAR;
		game->keke.down_anim.current = game->keke.down_anim.frame_move_1;
	}
}

void	ft_move_keke_left(t_game *game, int row, int col)
{
	if (game->map.grid[row][col - 1] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_keke_obstacle(game->map.grid[row][col - 1]))
	{
		if (game->map.grid[row][col - 1] == BOX_CHAR)
			system("aplay sounds/special-effects/box_destroyed.wav &");
		game->keke.left_anim.current = game->keke.left_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row][col - 1] = KEKE_CHAR;
		game->keke.left_anim.current = game->keke.left_anim.frame_move_1;
	}
}

void	ft_move_keke_right(t_game *game, int row, int col)
{
	if (game->map.grid[row][col + 1] == PLAYER_CHAR)
	{
		ft_player_get_hit(game);
		game->map.grid[row][col] = VOID_CHAR;
	}
	else if (!ft_is_keke_obstacle(game->map.grid[row][col + 1]))
	{
		if (game->map.grid[row][col + 1] == BOX_CHAR)
			system("aplay sounds/special-effects/box_destroyed.wav &");
		game->keke.right_anim.current = game->keke.right_anim.frame_move_0;
		game->map.grid[row][col] = VOID_CHAR;
		game->map.grid[row][col + 1] = KEKE_CHAR;
		game->keke.right_anim.current = game->keke.right_anim.frame_move_1;
	}
}
