/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:17:50 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 01:12:35 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

void	ft_free_zero(t_game *game)
{
	if (game->hud.digits.zero.frame_0 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.zero.frame_0);
	if (game->hud.digits.zero.frame_1 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.zero.frame_1);
	if (game->hud.digits.zero.frame_2 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.zero.frame_2);
}

void	ft_free_one(t_game *game)
{
	if (game->hud.digits.one.frame_0)
		mlx_destroy_image(game->mlx, game->hud.digits.one.frame_0);
	if (game->hud.digits.one.frame_1 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.one.frame_1);
	if (game->hud.digits.one.frame_2 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.one.frame_2);
}

void	ft_free_two(t_game *game)
{
	if (game->hud.digits.two.frame_0)
		mlx_destroy_image(game->mlx, game->hud.digits.two.frame_0);
	if (game->hud.digits.two.frame_1)
		mlx_destroy_image(game->mlx, game->hud.digits.two.frame_1);
	if (game->hud.digits.two.frame_2 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.two.frame_2);
}

void	ft_free_tree(t_game *game)
{
	if (game->hud.digits.tree.frame_0)
		mlx_destroy_image(game->mlx, game->hud.digits.tree.frame_0);
	if (game->hud.digits.tree.frame_1)
		mlx_destroy_image(game->mlx, game->hud.digits.tree.frame_1);
	if (game->hud.digits.tree.frame_2)
		mlx_destroy_image(game->mlx, game->hud.digits.tree.frame_2);
}

void	ft_free_four(t_game *game)
{
	if (game->hud.digits.four.frame_0)
		mlx_destroy_image(game->mlx, game->hud.digits.four.frame_0);
	if (game->hud.digits.four.frame_1 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.four.frame_1);
	if (game->hud.digits.four.frame_2 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.four.frame_2);
}

void	ft_free_five(t_game *game)
{
	if (game->hud.digits.five.frame_0)
		mlx_destroy_image(game->mlx, game->hud.digits.five.frame_0);
	if (game->hud.digits.five.frame_1 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.five.frame_1);
	if (game->hud.digits.five.frame_2 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.five.frame_2);
}

void	ft_free_six(t_game *game)
{
	if (game->hud.digits.six.frame_0)
		mlx_destroy_image(game->mlx, game->hud.digits.six.frame_0);
	if (game->hud.digits.six.frame_1)
		mlx_destroy_image(game->mlx, game->hud.digits.six.frame_1);
	if (game->hud.digits.six.frame_2 != NULL)
		mlx_destroy_image(game->mlx, game->hud.digits.six.frame_2);
}

void	ft_free_seven(t_game *game)
{
	if (game->hud.digits.seven.frame_0)
		mlx_destroy_image(game->mlx, game->hud.digits.seven.frame_0);
	if (game->hud.digits.seven.frame_1)
		mlx_destroy_image(game->mlx, game->hud.digits.seven.frame_1);
	if (game->hud.digits.seven.frame_2)
		mlx_destroy_image(game->mlx, game->hud.digits.seven.frame_2);
}

void	ft_free_eight(t_game *game)
{
	if (game->hud.digits.eight.frame_0)
		mlx_destroy_image(game->mlx, game->hud.digits.eight.frame_0);
	if (game->hud.digits.eight.frame_1)
		mlx_destroy_image(game->mlx, game->hud.digits.eight.frame_1);
	if (game->hud.digits.eight.frame_2)
		mlx_destroy_image(game->mlx, game->hud.digits.eight.frame_2);
}

void	ft_free_nine(t_game *game)
{
	if (game->hud.digits.nine.frame_0)
		mlx_destroy_image(game->mlx, game->hud.digits.nine.frame_0);
	if (game->hud.digits.nine.frame_1)
		mlx_destroy_image(game->mlx, game->hud.digits.nine.frame_1);
	if (game->hud.digits.nine.frame_2)
		mlx_destroy_image(game->mlx, game->hud.digits.nine.frame_2);
}

void	ft_free_digits(t_game *game)
{
	ft_free_zero(game);
	ft_free_one(game);
	ft_free_two(game);
	ft_free_tree(game);
	ft_free_four(game);
	ft_free_five(game);
	ft_free_six(game);
	ft_free_seven(game);
	ft_free_eight(game);
	ft_free_nine(game);
}

void	ft_free_animation(t_game *game)
{
	ft_free_player_move(game);
	ft_free_player(game);
	ft_free_ground(game);
	ft_free_life(game);
	ft_free_lava(game);
	ft_free_key(game);
	ft_free_wall(game);
	ft_free_door(game);
	ft_free_grass(game);
	ft_free_digits(game);
}

void	ft_free_mlx(t_game *game)
{
	if (game->window.img)
		mlx_destroy_image(game->mlx, game->window.img);
	if (game->window.img_data)
		free(game->window.img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game)
		free(game);
}

void	ft_free_grass(t_game *game)
{
	if (game->grass.animation.frame_0)
		mlx_destroy_image(game->mlx, game->grass.animation.frame_0);
	if (game->grass.animation.frame_1)
		mlx_destroy_image(game->mlx, game->grass.animation.frame_1);
	if (game->grass.animation.frame_2)
		mlx_destroy_image(game->mlx, game->grass.animation.frame_2);
}

void	ft_free_key(t_game *game)
{
	if (game->key.animation.frame_0)
		mlx_destroy_image(game->mlx, game->key.animation.frame_0);
	if (game->key.animation.frame_1)
		mlx_destroy_image(game->mlx, game->key.animation.frame_1);
	if (game->key.animation.frame_2)
		mlx_destroy_image(game->mlx, game->key.animation.frame_2);
}

void	ft_free_wall(t_game *game)
{
	if (game->wall.animation.frame_0)
		mlx_destroy_image(game->mlx, game->wall.animation.frame_0);
	if (game->wall.animation.frame_1)
		mlx_destroy_image(game->mlx, game->wall.animation.frame_1);
	if (game->wall.animation.frame_2)
		mlx_destroy_image(game->mlx, game->wall.animation.frame_2);
}

void	ft_free_door(t_game *game)
{
	if (game->door.closed.frame_0)
		mlx_destroy_image(game->mlx, game->door.closed.frame_0);
	if (game->door.closed.frame_1)
		mlx_destroy_image(game->mlx, game->door.closed.frame_1);
	if (game->door.closed.frame_2)
		mlx_destroy_image(game->mlx, game->door.closed.frame_2);
	if (game->door.open.frame_0)
		mlx_destroy_image(game->mlx, game->door.open.frame_0);
	if (game->door.open.frame_1)
		mlx_destroy_image(game->mlx, game->door.open.frame_1);
	if (game->door.open.frame_2)
		mlx_destroy_image(game->mlx, game->door.open.frame_2);
}
