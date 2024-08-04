/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_even_digts_assets_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:21:10 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/02 13:15:08 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_digit_zero(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/0/digit_0_frame_0.xpm",
		"assets/xpm/Bonus/digits/0/digit_0_frame_1.xpm",
		"assets/xpm/Bonus/digits/0/digit_0_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.zero), game, paths,
		error_messages);
}

void	ft_load_digit_two(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/2/digit_2_frame_0.xpm",
		"assets/xpm/Bonus/digits/2/digit_2_frame_1.xpm",
		"assets/xpm/Bonus/digits/2/digit_2_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.two), game, paths,
		error_messages);
}

void	ft_load_digit_four(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/4/digit_4_frame_0.xpm",
		"assets/xpm/Bonus/digits/4/digit_4_frame_1.xpm",
		"assets/xpm/Bonus/digits/4/digit_4_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.four), game, paths,
		error_messages);
}

void	ft_load_digit_six(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/6/digit_6_frame_0.xpm",
		"assets/xpm/Bonus/digits/6/digit_6_frame_1.xpm",
		"assets/xpm/Bonus/digits/6/digit_6_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.six), game, paths,
		error_messages);
}

void	ft_load_digit_eight(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/8/digit_8_frame_0.xpm",
		"assets/xpm/Bonus/digits/8/digit_8_frame_1.xpm",
		"assets/xpm/Bonus/digits/8/digit_8_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.eight), game, paths,
		error_messages);
}
