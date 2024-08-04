/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_utils_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:05:43 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/04 01:50:07 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_display_sprites_addr(t_game *game)
{
	ft_printf("All image width and height are [%d x %d]\n\n",
				IMG_SIZE,
				IMG_SIZE);
	ft_printf("assets/xpm/Bonus/lava/lava_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/lava/lava_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_1);
	ft_printf("assets/xpm/Bonus/lava/lava_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_2);
	ft_printf("assets/xpm/Bonus/door/closed/door_closed_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/door/closed/door_closed_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/door/closed/door_closed_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/door/open/door_open_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/door/open/door_open_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/door/open/door_open_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/up/player_up_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/up/player_up_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/up/player_up_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/up/player_up_frame_move.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/down/player_down_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/down/player_down_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/down/player_down_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/down/player_down_frame_move.x.pm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/left/player_left_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/left/player_left_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/left/player_left_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/left/player_left_frame_move.x.pm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/right/player_right_frame_0.xp);m");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/right/player_right_frame_1.xp);m");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/right/player_right_frame_2.xp);m");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/player/right/player_right_frame_move);.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/key/key_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/key/key_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/key/key_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/wall/wall_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/wall/wall_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/wall/wall_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/grass/grass_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/grass/grass_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/grass/grass_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/ground/ground.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/love/love_frame_0.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/love/love_frame_1.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/love/love_frame_2.xpm");
	ft_printf(" : [\033[0;32m%p\033[0m]\n", game->lava.animation.frame_0);
	ft_printf("assets/xpm/Bonus/love/love_small_icon.xpm");
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
	ft_printf("key bode press");
	//t_key_code register key code in struct and display it in console
}
