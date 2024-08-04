/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_gameplay_portal_assets_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:25:32 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:15:15 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_portal_z_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/portal/second/portal_2_frame_1.xpm",
		"assets/xpm/Bonus/portal/second/portal_2_frame_0.xpm",
		"assets/xpm/Bonus/portal/second/portal_2_frame_2.xpm",};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon",
	};

	ft_load_animation_sprites((t_animation *)&(game->portal.z), game,
		paths, error_messages);
}

void	ft_load_portal_n_sprites(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/portal/first/portal_1_frame_1.xpm",
		"assets/xpm/Bonus/portal/first/portal_1_frame_0.xpm",
		"assets/xpm/Bonus/portal/first/portal_1_frame_2.xpm",};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon",
	};

	ft_load_animation_sprites((t_animation *)&(game->portal.n), game,
		paths, error_messages);
}
