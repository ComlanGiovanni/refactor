/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_management_linux.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:30 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 01:09:15 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 * 	this fct simply display the number of life of the player
 * 		whe loop by the life.player.map, and print the small love.icon
 * 				10x10 at the x y and we also reset
 * 			the x position to 0 to print at the next line y
 *
 * is not great display because for 100 life we dont manage to print all
 * 		for DLC we can stack every heath
 *
 * 	//t_point for less line put in struct
 * //regarde pour la tranparance lalpha
 * @param game
 */
void	ft_display_life_on_windows(t_game *game)
{
	int	idx;
	int	x;
	int	y;
	int	icons_per_row;
	int	icon_spacing;

	idx = 0;
	x = 5;
	y = 5;
	icons_per_row = 3;
	icon_spacing = 5;
	while (idx < game->player.life && idx < 500)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->love.icon, x, y);
		idx++;
		if ((idx % icons_per_row) == 0)
		{
			x = 5;
			y += 32 + icon_spacing;
		}
		else
			x += 32 + icon_spacing;
	}
	if (game->player.life <= 0)
		ft_lose_game(game);
}

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

/*
print error and free, print error and free
if (!map_fits_screen(g))
	write(2, "not fit screen size\n",);

*/

void	ft_map_fit_screen(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	width = 0;
	mlx_get_screen_size(game->mlx, &width, &height);
	if (game->width * 64 > width || game->height * 64 > height)
		ft_print_error(MAP_TOO_BIG, game);
}

/**
 * @brief
 *
 *  For real i rteally dont know, i jjust
 * notcce thatthe current frqme of the door
 * is not loadead and i can easly free the
 * frae 0 of te door even if its animated
 * aka cchange y the fram 1 2 when i am playing
 * the game so that meain that i can
 * free the frame 0 even if it animatead ????
 *
 * @param game
 */
void	ft_load_player_current(t_game *game)
{
	game->player.up_anim.current = game->player.up_anim.frame_0;
	if (game->player.up_anim.current == NULL)
		ft_print_error(PLAYER_U_0_ERROR, game);
	game->player.down_anim.current = game->player.down_anim.frame_0;
	if (game->player.down_anim.current == NULL)
		ft_print_error(PLAYER_D_0_ERROR, game);
	game->player.left_anim.current = game->player.left_anim.frame_0;
	if (game->player.left_anim.current == NULL)
		ft_print_error(PLAYER_L_0_ERROR, game);
	game->player.right_anim.current = game->player.right_anim.frame_0;
	if (game->player.right_anim.current == NULL)
		ft_print_error(PLAYER_R_0_ERROR, game);
}
