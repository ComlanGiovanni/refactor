/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_behaviour_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:21:59 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/07 14:30:50 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 *
 * 		This fct its only here to give more life at the game,
 * 		instead of spawning everytime look to up down or left
 * 		we simply generate a randonn nbr with random -> time.h
 * 		srand if for more random generaton so 0 1 2 3 represent
 * 		up down left right assign is belong to you
 *
 * 	diriger la position en fonciton de la position de player
 * par rapport a l'exit ?
 *
 *	bas haut gauche droite
 *
 * @param game
 */
void	ft_dir_player_by_pos_exit_after_launch(t_game *game)
{
	if (game->map.start.y > game->map.end.y)
		game->player.movement.direction = 'u'; // Exit is above the player
	else if (game->map.start.y < game->map.end.y)
		game->player.movement.direction = 'd'; // Exit is below the player
	else if (game->map.start.x > game->map.end.x)
		game->player.movement.direction = 'l'; // Exit is to the left of the player
	else if (game->map.start.x < game->map.end.x)
		game->player.movement.direction = 'r'; // Exit is to the right of the player
}

void	ft_move_box(t_game *game, int new_y, int new_x, int dir_y, int dir_x)
{
	char	next_tile;

	next_tile = game->map.grid[new_y + dir_y][new_x + dir_x];
	// Vérifie si la box peut être déplacée dans la direction donnée
	if (next_tile == VOID_CHAR && (next_tile != LOVE_CHAR
			&& next_tile != EXIT_CHAR && next_tile != KEY_CHAR))
	{
		game->map.grid[new_y + dir_y][new_x + dir_x] = BOX_CHAR;
		game->map.grid[new_y][new_x] = VOID_CHAR;
		system("cvlc sounds/box_move.wav &");
	}
}

void	ft_teleport_player(t_game *game, int y, int x)
{
	t_point	destination;

	if (game->map.grid[y][x] == 'N')
	{
		destination = game->map.portal_1_pos;
		ft_printf("bugs");
	}
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
