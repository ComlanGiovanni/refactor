/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_tools_bonus_linux.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:12:11 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 01:15:59 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"
#include <time.h>

/**
 * @brief
 *
 *			This fct display the map store in
 * 			game->map.map_str not in one line but like
 * 			in the map.ber where we join every line
 * 				11111
 * 		print->	1PCE1		str-> 111111PCE111111
 * 				11111
 *
 * 		so we simply loop intil the end and print the chac i he
 * 	he exist and reset the resest varibale who is indicate that we reach
 * 			the end of the line so we can print a new line and pint
 * 					all the char of the next line
 * 							and so on
 *
 * @param game
 */
void	ft_print_map_better_format(t_game *game)
{
	int	idx;
	int	reset;

	idx = FALSE;
	reset = TRUE;
	while (idx < game->map.len)
	{
		if (game->map.map_str[idx])
			ft_printf("%c", game->map.map_str[idx]);
		if (reset == game->width)
		{
			ft_printf("\n");
			reset = FALSE;
		}
		idx++;
		reset++;
	}
}

/**
 * @brief
 *
 * 			this is just a display int console
 * 			for debug or can be see ass stat
 * 		for gameplay lol, just some player and map info
 *
 * 			simple remaing key
 *		(game->map.nbr_key - game->player.storage)
 *
 * 		Remaining is pretty annoying to impplement let see later in DLC 1
 *
 * @param game
 * @param key_code
 */
void	ft_print_game_info(t_game *game)
{
	system("clear");
	ft_print_display_grid(game->map.grid);
	ft_printf("Player position: (%d, %d)\n",
		game->player.movement.current_position.x,
		game->player.movement.current_position.y);
}

/**
 * @brief
 *
 * this fct is use in the ft_print_game_info and just display
 *  up down left right by the game.player.direction set when
 * 	we print any directional touch in the file of input_fct_bonus.c
 * 	that is use in ft_input_manager we get call by the mlx_hook
 * 	listener of x_event MAC_KEY_PRESS -> 2
 *
 * @param game
 */
void	ft_print_facing(t_game *game)
{
	if (game->player.movement.direction == 'u')
		ft_printf("* Player Facing : up                     \n");
	if (game->player.movement.direction == 'd')
		ft_printf("* Player Facing : down                   \n");
	if (game->player.movement.direction == 'l')
		ft_printf("* Player Facing : left                   \n");
	if (game->player.movement.direction == 'r')
		ft_printf("* Player Facing : right                  \n");
}

void	ft_print_status(t_game *game)
{
	if (game->player.movement.moved)
		ft_printf("* Status : Moving                  \n");
	else
		ft_printf("* Status : idle                  \n");
}

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
void	ft_direction_by_pos_after_launch(t_game *game)
{
	int	random;

	srand(time(0));
	random = rand() % 4;
	if (random == 0x0)
		game->player.movement.direction = 'u';
	if (random == 0x1)
		game->player.movement.direction = 'd';
	if (random == 0x2)
		game->player.movement.direction = 'l';
	if (random == 0x3)
		game->player.movement.direction = 'r';
}

/**
 * @brief
 *
 * 			This fct is call when the game->player.life is 0
 * 		this variable is dec only when we it a lava aka L see
 * 	ft_display_life_on_windows  all moving fct in -> input_bonus.c
 * 		he is set in ft_init_player_info in the main at 1
 *
 * 		we print storage at the death with the life 0 pretty dumb be meh is ok
 *
 * 		the we destroy the windows, we should probaly
 * 			free the game, check with valgrind
 * 					on the linux version
 *
 * 		return 1 because we fail hummmm legit ? or its 0
 *
 * 			mlx_destroy_window(game->mlx, game->win);
 *
 * @param game
 * @return int
 */
int	ft_lose_game(t_game *game)
{
	ft_printf(LOSE_MSG "%d ", game->player.step);
	ft_printf("Storage : %d, ", game->player.storage);
	ft_printf("Life : %d\n\n", game->player.life);
	ft_free_step_and_storage(game);
	ft_free_all(game);
	exit(EXIT_FAILURE);
}

void	ft_free_step_and_storage(t_game *game)
{
	if (game->hud.str_step != NULL)
		free(game->hud.str_step);
	if (game->hud.str_fps != NULL)
		free(game->hud.str_fps);
	if (game->hud.str_key_remain != NULL)
		free(game->hud.str_key_remain);
}
