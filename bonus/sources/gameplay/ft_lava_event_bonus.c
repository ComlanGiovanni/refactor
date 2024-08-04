/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lava_event_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:40:59 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:14:21 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 *
 * 		we simply generate a random int
 * 			aka direction for the
 * 			ft_move_lava(game);
 *
 * 	no good place found stay here
 *
 * sleep(1); dont work kinda wierd
 *
 * @param game
 */
void	ft_random_lava_move(t_game *game)
{
	int	random;

	srand(time(0));
	random = rand() % 4 ;
	if (random == 0)
		game->lava.move = 'u';
	if (random == 1)
		game->lava.move = 'd';
	if (random == 2)
		game->lava.move = 'l';
	if (random == 3)
		game->lava.move = 'r';
	ft_move_lava(game);
}

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


