/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_door_sprite_bonus_linux.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:11:37 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/01 04:57:56 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_linux/so_long_bonus_linux.h"

void	ft_load_door_closed_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/door/closed/door_closed_frame_0.xpm",
		"assets/xpm/Bonus/door/closed/door_closed_frame_1.xpm",
		"assets/xpm/Bonus/door/closed/door_closed_frame_2.xpm"};
	const char	*error_messages[] = {
		DOOR_C_0_XPM_ERROR,
		DOOR_C_1_XPM_ERROR,
		DOOR_C_2_XPM_ERROR};

	ft_load_animation_sprites((t_animation *)&(game->door.closed), game, paths,
		error_messages);
}

void	ft_load_door_open_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/door/open/door_open_frame_0.xpm",
		"assets/xpm/Bonus/door/open/door_open_frame_1.xpm",
		"assets/xpm/Bonus/door/open/door_open_frame_2.xpm"};
	const char	*error_messages[] = {
		DOOR_O_0_XPM_ERROR,
		DOOR_O_1_XPM_ERROR,
		DOOR_O_2_XPM_ERROR};

	ft_load_animation_sprites((t_animation *)&(game->door.open), game, paths,
		error_messages);
}

void	ft_load_box_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/box/box_frame_0.xpm",
		"assets/xpm/Bonus/box/box_frame_1.xpm",
		"assets/xpm/Bonus/box/box_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message eeferror replace soon",
		"Generic message ererror replace soon",
		"Generic message erererror replace soon"};

	ft_load_animation_sprites(&(game->box.animation), game, paths,
		error_messages);
}
