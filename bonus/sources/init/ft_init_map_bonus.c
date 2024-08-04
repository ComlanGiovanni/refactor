/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:59:15 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:14:43 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_setup_map(t_game *game)
{
	ft_print_initial_positions(game);
	ft_update_map_matrice(game);
	ft_print_display_grid(game->map.matrice);

	game->map.grid = ft_create_map_with_border(game);
	game->map.info.nbr_border = (game->map.size.x * game->map.size.y)
		- game->map.len;
	ft_printf(NEW_GRID_MSG);
	ft_print_display_grid(game->map.grid);

	ft_update_map_positions(game);
	ft_display_position(game->map.start, game->map.end,
		game->map.portal_1_pos, game->map.portal_2_pos);

	ft_update_player_position(game);
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
		else if (game->map.map_str[idx] == BORDER_CHAR)
			game->map.info.nbr_border++;
		else
			game->map.info.nbr_void++;
	}
}

void	ft_play_random_theme()
{
	static int random;

	srand(time(0));
	random = rand() % 4 ;
	if (random == 0)
		system("cvlc sounds/BabaIsYouOnTheIsland.wav &");
	if (random == 1)
		system("cvlc sounds/BabaIsYouTheme.wav &");
	if (random == 2)
		system("cvlc sounds/BabaIsYouWaterIsSinkThelake.wav &");
	if (random == 3)
		system("cvlc sounds/BabaIsYouCrystalIsStillCrystalcave.wav &");
}
