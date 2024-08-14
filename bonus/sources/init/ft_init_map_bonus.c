/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:59:15 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/14 05:11:01 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_setup_map(t_game *game)
{
	ft_printf("\nGrid Width && Height -> \t[%d %d]\n",game->map.size.x, game->map.size.y);
	ft_print_initial_positions(game);
	ft_update_map_matrice(game);
	ft_print_display_grid(game->map.matrice);

	game->map.grid = ft_create_map_with_border(game);
	game->map.info.nbr_grass = (game->map.size.x * game->map.size.y)
		- game->map.len;
	ft_printf(NEW_GRID_MSG);
	ft_print_display_grid(game->map.grid);

	ft_update_map_positions(game);
	ft_printf("\nGrid Width && Height -> \t[%d %d]\n",game->map.size.x, game->map.size.y);
	ft_display_position(game->map.start, game->map.end,
		game->map.portal_1_pos, game->map.portal_2_pos);

	ft_update_player_position(game);
	ft_init_pawns_array(game);
}

/**
 * @brief
 * 		we loop in the map until we reach the end (map.len)
 * 			we get all the map info that we read previously
 * 		if we found any char 0 1 P E L S we inc the variable
 *
 * @param game
 */
void	ft_get_info_map(t_game *game)
{
	int	idx;

	idx = FALSE;
	while (idx++ < game->map.len)
	{
		if (game->map.map_str[idx] == KEY_CHAR)
			game->map.info.nbr_key++;
		else if (game->map.map_str[idx] == PLAYER_CHAR)
			game->map.info.nbr_player++;
		else if (game->map.map_str[idx] == EXIT_CHAR)
			game->map.info.nbr_exit++;
		else if (game->map.map_str[idx] == LAVA_CHAR)
			game->map.info.nbr_lava++;
		else if (game->map.map_str[idx] == LOVE_CHAR)
			game->map.info.nbr_love++;
		else if (game->map.map_str[idx] == WALL_CHAR)
			game->map.info.nbr_wall++;
		else if (game->map.map_str[idx] == BOX_CHAR)
			game->map.info.nbr_box++;
		else if (game->map.map_str[idx] == PORTAL_1_CHAR)
			game->map.info.nbr_portal_1++;
		else if (game->map.map_str[idx] == PORTAL_2_CHAR)
			game->map.info.nbr_portal_2++;
		else if (game->map.map_str[idx] == GRASS_CHAR)
			game->map.info.nbr_grass++;
		else if (game->map.map_str[idx] == PAWN_CHAR)
			game->map.info.nbr_pawn++;
		else if (game->map.map_str[idx] == KEKE_CHAR)
			game->map.info.nbr_keke++;
		else
			game->map.info.nbr_void++;
	}
}

void	ft_play_random_theme()
{
	static int random;

	srand((unsigned int)time(NULL));
	random = rand() % 4 ;
	if (random == 0)
		system("aplay sounds/theme/baba_is_you_on_the_island.wav &");
	if (random == 1)
		system("aplay sounds/theme/baba_is_you_theme.wav &");
	if (random == 2)
		system("aplay sounds/theme/baba_is_you_water_is_sink_the_lake.wav &");
	if (random == 3)
		system("aplay sounds/theme/baba_is_you_crystal_is_still_crystal_cave.wav &");
}
