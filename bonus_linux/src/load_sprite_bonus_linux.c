/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_bonus_linux.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:49 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 01:23:20 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

/**
 * @brief
 *
 * 		Check after load to prevent segfault of all the loaded sprite
 * 			set of the frame of the animation in the struct
 *				print the good errorr message
 * 		Here lava love wall ground sprite close and open sprite
 *
 * 	ground is xpm black void only one the rest have 3 state frame 012
 * 				we also load the love icon struct 10x10
 * 			we can load the key icon struc in the future
 *				to display the number of key we have
 *				Same for step and small icon step(DLC 5)
 *
 *
 * @param game
 */
void	ft_load_lava_sprites(t_game *game)
{
	int			width;
	int			height;

	width = 0;
	height = 0;
	game->lava.animation.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/lava/lava_frame_0.xpm", &width, &height);
	if (game->lava.animation.frame_0 == NULL)
		ft_print_error(LAVA_0_XPM_ERROR, game);
	game->lava.animation.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/lava/lava_frame_1.xpm", &width, &height);
	if (game->lava.animation.frame_1 == NULL)
		ft_print_error(LAVA_1_XPM_ERROR, game);
	game->lava.animation.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/lava/lava_frame_2.xpm", &width, &height);
	if (game->lava.animation.frame_2 == NULL)
		ft_print_error(LAVA_2_XPM_ERROR, game);
	game->lava.animation.current = game->lava.animation.frame_0;
	if (game->lava.animation.current == NULL)
		ft_print_error(LAVA_0_XPM_ERROR, game);
}

void	ft_load_key_sprites(t_game *game)
{
	int	width;
	int	height;

	game->key.animation.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/key/key_frame_0.xpm", &width, &height);
	if (game->key.animation.frame_0 == NULL)
		ft_print_error(KEY_0_XPM_ERROR, game);
	game->key.animation.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/key/key_frame_1.xpm", &width, &height);
	if (game->key.animation.frame_1 == NULL)
		ft_print_error(KEY_1_XPM_ERROR, game);
	game->key.animation.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/key/key_frame_2.xpm", &width, &height);
	if (game->key.animation.frame_2 == NULL)
		ft_print_error(KEY_2_XPM_ERROR, game);
	game->key.animation.current = game->key.animation.frame_0;
	if (game->key.animation.current == NULL)
		ft_print_error(KEY_0_XPM_ERROR, game);
}

void	ft_load_wall_sprites(t_game *game)
{
	int			width;
	int			height;

	game->wall.animation.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/wall/wall_frame_0.xpm", &width, &height);
	if (game->wall.animation.frame_0 == NULL)
		ft_print_error(WALL_0_XPM_ERROR, game);
	game->wall.animation.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/wall/wall_frame_1.xpm", &width, &height);
	if (game->wall.animation.frame_1 == NULL)
		ft_print_error(WALL_1_XPM_ERROR, game);
	game->wall.animation.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/wall/wall_frame_2.xpm", &width, &height);
	if (game->wall.animation.frame_2 == NULL)
		ft_print_error(WALL_2_XPM_ERROR, game);
	game->wall.animation.current = game->wall.animation.frame_0;
	if (game->wall.animation.current == NULL)
		ft_print_error(WALL_0_XPM_ERROR, game);
}

void	ft_load_borders_sprite(t_game *game)
{
	int			width;
	int			height;

	game->grass.animation.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/grass/grass_frame_0.xpm", &width, &height);
	if (game->grass.animation.frame_0 == NULL)
		ft_print_error(GRASS_0_XPM_ERROR, game);
	game->grass.animation.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/grass/grass_frame_1.xpm", &width, &height);
	if (game->grass.animation.frame_1 == NULL)
		ft_print_error(GRASS_1_XPM_ERROR, game);
	game->grass.animation.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/grass/grass_frame_0.xpm", &width, &height);
	if (game->grass.animation.frame_2 == NULL)
		ft_print_error(GRASS_2_XPM_ERROR, game);
	game->grass.animation.current = game->grass.animation.frame_0;
	if (game->grass.animation.current == NULL)
		ft_print_error(GRASS_2_XPM_ERROR, game);

}

void	ft_load_ground_sprites(t_game *game)
{
	int	width;
	int	height;

	game->map.ground = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/ground/ground.xpm", &width, &height);
	if (game->map.ground == NULL)
		ft_print_error(GROUND_XPM_ERROR, game);
}

void	ft_load_love_sprites(t_game *game)
{
	int	width;
	int	height;

	game->love.animation.frame_0 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/love/love_frame_0.xpm", &width, &height);
	if (game->love.animation.frame_0 == NULL)
		ft_print_error(LOVE_0_XPM_ERROR, game);
	game->love.animation.frame_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/love/love_frame_1.xpm", &width, &height);
	if (game->love.animation.frame_1 == NULL)
		ft_print_error(LOVE_1_XPM_ERROR, game);
	game->love.animation.frame_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/love/love_frame_2.xpm", &width, &height);
	if (game->love.animation.frame_2 == NULL)
		ft_print_error(LOVE_2_XPM_ERROR, game);
	game->love.icon = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/love/love_small_icon.xpm", &width, &height);
	if (game->love.icon == NULL)
		ft_print_error(LOVE_ICON_ERROR, game);
	game->love.animation.current = game->love.animation.frame_0;
	if (game->love.animation.current == NULL)
		ft_print_error(LOVE_0_XPM_ERROR, game);
	game->love.nope = mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/love/love_frame_no.xpm", &width, &height);
	if (game->love.nope == NULL)
		ft_print_error("love_frame_no.xpm", game);
}

void	ft_load_digit_zero(t_game *game)
{
	int	width;
	int	height;

	game->hud.digits.zero.frame_0 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/0/digit_0_frame_0.xpm", &width, &height);
	if (game->hud.digits.zero.frame_0 == NULL)
		ft_print_error("00", game);
	game->hud.digits.zero.frame_1 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/0/digit_0_frame_1.xpm", &width, &height);
	if (game->hud.digits.zero.frame_1 == NULL)
		ft_print_error("0000", game);
	game->hud.digits.zero.frame_2 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/0/digit_0_frame_2.xpm", &width, &height);
	if (game->hud.digits.zero.frame_2 == NULL)
		ft_print_error("000000", game);
	game->hud.digits.zero.current = game->hud.digits.zero.frame_0;
	if (game->hud.digits.zero.current == NULL)
		ft_print_error("nope", game);
}

void	ft_load_digit_one(t_game *game)
{
	int	width;
	int	height;

	game->hud.digits.one.frame_0 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/1/digit_1_frame_0.xpm", &width, &height);
	if (game->hud.digits.one.frame_0 == NULL)
		ft_print_error("", game);
	game->hud.digits.one.frame_1 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/1/digit_1_frame_1.xpm", &width, &height);
	if (game->hud.digits.one.frame_1 == NULL)
		ft_print_error("", game);
	game->hud.digits.one.frame_2 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/1/digit_1_frame_2.xpm", &width, &height);
	if (game->hud.digits.one.frame_2 == NULL)
		ft_print_error("", game);
	game->hud.digits.one.current = game->hud.digits.one.frame_0;
	if (game->hud.digits.one.current == NULL)
		ft_print_error("", game);
}


void	ft_load_digit_two(t_game *game)
{
	int	width;
	int	height;

	game->hud.digits.two.frame_0 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/2/digit_2_frame_0.xpm", &width, &height);
	if (game->hud.digits.two.frame_0 == NULL)
		ft_print_error("", game);
	game->hud.digits.two.frame_1 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/2/digit_2_frame_1.xpm", &width, &height);
	if (game->hud.digits.two.frame_1 == NULL)
		ft_print_error("", game);
	game->hud.digits.two.frame_2 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/2/digit_2_frame_2.xpm", &width, &height);
	if (game->hud.digits.two.frame_2 == NULL)
		ft_print_error("", game);
	game->hud.digits.two.current = game->hud.digits.two.frame_0;
	if (game->hud.digits.two.current == NULL)
		ft_print_error("", game);
}

void	ft_load_digit_tree(t_game *game)
{
	int	width;
	int	height;

	game->hud.digits.tree.frame_0 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/3/digit_3_frame_0.xpm", &width, &height);
	if (game->hud.digits.tree.frame_0 == NULL)
		ft_print_error("", game);
	game->hud.digits.tree.frame_1 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/3/digit_3_frame_1.xpm", &width, &height);
	if (game->hud.digits.tree.frame_1 == NULL)
		ft_print_error("", game);
	game->hud.digits.tree.frame_2 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/3/digit_3_frame_2.xpm", &width, &height);
	if (game->hud.digits.tree.frame_2 == NULL)
		ft_print_error("", game);
	game->hud.digits.tree.current = game->hud.digits.tree.frame_0;
	if (game->hud.digits.tree.current == NULL)
		ft_print_error("", game);
}


void	ft_load_digit_four(t_game *game)
{
	int	width;
	int	height;

	game->hud.digits.four.frame_0 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/4/digit_4_frame_0.xpm", &width, &height);
	if (game->hud.digits.four.frame_0 == NULL)
		ft_print_error("", game);
	game->hud.digits.four.frame_1 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/4/digit_4_frame_1.xpm", &width, &height);
	if (game->hud.digits.four.frame_1 == NULL)
		ft_print_error("", game);
	game->hud.digits.four.frame_2 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/4/digit_4_frame_2.xpm", &width, &height);
	if (game->hud.digits.four.frame_2 == NULL)
		ft_print_error("", game);
	game->hud.digits.four.current = game->hud.digits.four.frame_0;
	if (game->hud.digits.four.current == NULL)
		ft_print_error("", game);
}

void	ft_load_digit_five(t_game *game)
{
	int	width;
	int	height;

	game->hud.digits.five.frame_0 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/5/digit_5_frame_0.xpm", &width, &height);
	if (game->hud.digits.five.frame_0 == NULL)
		ft_print_error("", game);
	game->hud.digits.five.frame_1 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/5/digit_5_frame_1.xpm", &width, &height);
	if (game->hud.digits.five.frame_1 == NULL)
		ft_print_error("", game);
	game->hud.digits.five.frame_2 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/5/digit_5_frame_2.xpm", &width, &height);
	if (game->hud.digits.five.frame_2 == NULL)
		ft_print_error("", game);
	game->hud.digits.five.current = game->hud.digits.five.frame_0;
	if (game->hud.digits.five.current == NULL)
		ft_print_error("", game);
}


void	ft_load_digit_six(t_game *game)
{
	int	width;
	int	height;

	game->hud.digits.six.frame_0 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/6/digit_6_frame_0.xpm", &width, &height);
	if (game->hud.digits.six.frame_0 == NULL)
		ft_print_error("", game);
	game->hud.digits.six.frame_1 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/6/digit_6_frame_1.xpm", &width, &height);
	if (game->hud.digits.six.frame_1 == NULL)
		ft_print_error("", game);
	game->hud.digits.six.frame_2 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/6/digit_6_frame_2.xpm", &width, &height);
	if (game->hud.digits.six.frame_2 == NULL)
		ft_print_error("", game);
	game->hud.digits.six.current = game->hud.digits.six.frame_0;
	if (game->hud.digits.six.current == NULL)
		ft_print_error("", game);
}


void	ft_load_digit_seven(t_game *game)
{
	int	width;
	int	height;

	game->hud.digits.seven.frame_0 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/7/digit_7_frame_0.xpm", &width, &height);
	if (game->hud.digits.seven.frame_0 == NULL)
		ft_print_error("", game);
	game->hud.digits.seven.frame_1 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/7/digit_7_frame_1.xpm", &width, &height);
	if (game->hud.digits.seven.frame_1 == NULL)
		ft_print_error("", game);
	game->hud.digits.seven.frame_2 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/7/digit_7_frame_2.xpm", &width, &height);
	if (game->hud.digits.seven.frame_2 == NULL)
		ft_print_error("", game);
	game->hud.digits.seven.current = game->hud.digits.seven.frame_0;
	if (game->hud.digits.seven.current == NULL)
		ft_print_error("", game);
}


void	ft_load_digit_eight(t_game *game)
{
	int	width;
	int	height;

	game->hud.digits.eight.frame_0 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/8/digit_8_frame_0.xpm", &width, &height);
	if (game->hud.digits.eight.frame_0 == NULL)
		ft_print_error("", game);
	game->hud.digits.eight.frame_1 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/8/digit_8_frame_1.xpm", &width, &height);
	if (game->hud.digits.eight.frame_1 == NULL)
		ft_print_error("", game);
	game->hud.digits.eight.frame_2 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/8/digit_8_frame_2.xpm", &width, &height);
	if (game->hud.digits.eight.frame_2 == NULL)
		ft_print_error("", game);
	game->hud.digits.eight.current = game->hud.digits.eight.frame_0;
	if (game->hud.digits.eight.current == NULL)
		ft_print_error("", game);
}

void	ft_load_digit_nine(t_game *game)
{
	int	width;
	int	height;

	game->hud.digits.nine.frame_0 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/9/digit_9_frame_0.xpm", &width, &height);
	if (game->hud.digits.nine.frame_0 == NULL)
		ft_print_error("", game);
	game->hud.digits.nine.frame_1 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/9/digit_9_frame_1.xpm", &width, &height);
	if (game->hud.digits.nine.frame_1 == NULL)
		ft_print_error("", game);
	game->hud.digits.nine.frame_2 =  mlx_xpm_file_to_image(game->mlx,
			"assets/xpm/Bonus/digits/9/digit_9_frame_2.xpm", &width, &height);
	if (game->hud.digits.nine.frame_2 == NULL)
		ft_print_error("", game);
	game->hud.digits.nine.current = game->hud.digits.nine.frame_0;
	if (game->hud.digits.nine.current == NULL)
		ft_print_error("", game);
}

// void	ft_load_digit_tab(t_game *game)
// {
// 	game->hud.digits.tab[0] = game->hud.digits.zero.current;
// 	game->hud.digits.tab[1] = game->hud.digits.one.current;
// 	game->hud.digits.tab[2] = game->hud.digits.two.current;
// 	game->hud.digits.tab[3] = game->hud.digits.tree.current;
// 	game->hud.digits.tab[4] = game->hud.digits.four.current;
// 	game->hud.digits.tab[5] = game->hud.digits.five.current;
// 	game->hud.digits.tab[6] = game->hud.digits.six.current;
// 	game->hud.digits.tab[7] = game->hud.digits.seven.current;
// 	game->hud.digits.tab[8] = game->hud.digits.eight.current;
// 	game->hud.digits.tab[9] = game->hud.digits.nine.current;
// 	game->hud.digits.tab[10] = NULL;
// }

void ft_load_digits_sprites(t_game *game)
{
	ft_load_digit_zero(game);
	ft_load_digit_one(game);
	ft_load_digit_two(game);
	ft_load_digit_tree(game);
	ft_load_digit_four(game);
	ft_load_digit_five(game);
	ft_load_digit_six(game);
	ft_load_digit_seven(game);
	ft_load_digit_eight(game);
	ft_load_digit_nine(game);
	//ft_load_digit_tab(game);
}
