/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook_loop_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:09:22 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:15:40 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_mlx_hook_loop(t_game *game)
{
	mlx_do_key_autorepeaton(game->mlx);
	mlx_hook(game->win, LINUX_KEY_PRESS, TRUE, &ft_input_manager, game);
	mlx_hook(game->win, LINUX_CLOSE_ICON, TRUE, &ft_exit_game, game);
	mlx_loop_hook(game->mlx, &ft_update, game);
	mlx_loop(game->mlx);
}
