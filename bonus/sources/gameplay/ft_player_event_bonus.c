/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_event_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:23:29 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 11:54:01 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

// if ((game->fps.current_time.tv_sec - game->fps.last_time.tv_sec) > 1.0)
void	ft_play_movement_sound(t_game *game)
{
	game->player.step++;
	system("aplay sounds/special-effects/baba_move.wav &");
}

void	ft_player_take_coin(t_game *game)
{
	game->player.storage++;
	system("aplay sounds/special-effects/baba_take_key.wav &");
}

void	ft_player_take_life(t_game *game)
{
	game->player.life++;
	system("aplay sounds/special-effects/baba_take_life.wav &");
}

void	ft_player_get_hit(t_game *game)
{
	game->player.life--;
	system("aplay sounds/special-effects/baba_take_damage.wav &");
	ft_camera_shake(game);
}

void	ft_baba_forbidden(t_game *game)
{
	ft_camera_shake(game);
}
