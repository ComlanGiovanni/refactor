/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:29:36 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 19:43:01 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

/**
 * @brief
 *
 * 	we display a itoa o step storage on the win and free it the end
 * 	we print all info in color define in the define header
 * 	we can make a fct for the print of up down life right but iam lazy
 * 	so in fct of the char in game->player.direction we print the
 * 	full word in color
 *
 * //mlx_string_put(game->mlx, game->win, 5, game->height - 10,
 * //YELLOW, "Press [Esc]-key to Rage-Quit");
 *
 * @param game
 */
void	ft_print_info_on_window(t_game *game)
{
	game->hud.str_step = ft_itoa(game->player.step);
	//game->hud.str_storage = ft_itoa(game->player.storage);
	game->hud.str_fps = ft_itoa(game->fps.fps);
	game->hud.str_key_remain = ft_itoa(game->map.info.nbr_key
			- game->player.storage);
	ft_display_life_on_windows(game);
	ft_display_digits_sprites(game, game->hud.str_step, game->hud.step);
	ft_display_digits_sprites(game, game->hud.str_fps, game->hud.fps);
	ft_display_digits_sprites(game, game->hud.str_key_remain, game->hud.keys);
	//ft_display_step_on_widows(game);
	// mlx_string_put(game->mlx, game->win, 5, 42, YELLOW, "Step-> ");
	// mlx_string_put(game->mlx, game->win, 69, 42, RED, game->hud.str_step);
	// mlx_string_put(game->mlx, game->win, 5, 52, RED, "Storage-> ");
	// mlx_string_put(game->mlx, game->win, 69, 52, RED,
	//			game->hud.str_storage );
	// mlx_string_put(game->mlx, game->win, 5, 62, AQUA, "Facing-> ");
	// if (game->player.storage == game->map.info.nbr_key) // the fuck is this ?
	// 	mlx_string_put(game->mlx, game->win, 69, 52, GREEN,
	//				game->hud.str_storage );
	// if (game->player.movement.direction == 'u')
	// 	mlx_string_put(game->mlx, game->win, 69, 62, LIME, "Up");
	// if (game->player.movement.direction == 'd')
	// 	mlx_string_put(game->mlx, game->win, 69, 62, YELLOW, "Down");
	// if (game->player.movement.direction == 'l')
	// 	mlx_string_put(game->mlx, game->win, 69, 62, PINK, "Left");
	// if (game->player.movement.direction == 'r')
	// 	mlx_string_put(game->mlx, game->win, 69, 62, TURQUOISE, "Right");
	// mlx_string_put(game->mlx, game->win, 62, 90, TURQUOISE, "FPS -> ");
	// mlx_string_put(game->mlx, game->win, 90, 90, TURQUOISE,
	//			game->hud.str_fps);
	//add lke esc, indication for deplacement
	ft_free_step_and_storage(game);
}


void	ft_display_digits_sprites(t_game *game, char *digits_str,
		t_point position)
{
	void	*digit_images[10];
	int		index;

	digit_images[0] = game->hud.digits.zero.current;
	digit_images[1] = game->hud.digits.one.current;
	digit_images[2] = game->hud.digits.two.current;
	digit_images[3] = game->hud.digits.three.current;
	digit_images[4] = game->hud.digits.four.current;
	digit_images[5] = game->hud.digits.five.current;
	digit_images[6] = game->hud.digits.six.current;
	digit_images[7] = game->hud.digits.seven.current;
	digit_images[8] = game->hud.digits.eight.current;
	digit_images[9] = game->hud.digits.nine.current;
	index = 0;
	while (digits_str[index] != '\0')
	{
		if ((digits_str[index] - '0') >= 0 && (digits_str[index] - '0') <= 9)
		{
			mlx_put_image_to_window(game->mlx, game->win, digit_images[(digits_str[index] - '0')],
					position.x, position.y);
			position.x += 24;
		}
		index++;
	}
}

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
		mlx_put_image_to_window(game->mlx, game->win, game->love.icon, x, y);//try transparence
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
