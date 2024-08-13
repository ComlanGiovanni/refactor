/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_odd_digts_assets_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:21:40 by gicomlan          #+#    #+#             */
/*   Updated: 2024/08/12 19:43:01 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

void	ft_load_digit_one(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/1/digit_1_frame_0.xpm",
		"assets/xpm/Bonus/digits/1/digit_1_frame_1.xpm",
		"assets/xpm/Bonus/digits/1/digit_1_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.one), game, paths,
		error_messages);
}

void	ft_load_digit_tree(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/3/digit_3_frame_0.xpm",
		"assets/xpm/Bonus/digits/3/digit_3_frame_1.xpm",
		"assets/xpm/Bonus/digits/3/digit_3_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.three), game, paths,
		error_messages);
}

void	ft_load_digit_five(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/5/digit_5_frame_0.xpm",
		"assets/xpm/Bonus/digits/5/digit_5_frame_1.xpm",
		"assets/xpm/Bonus/digits/5/digit_5_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.five), game, paths,
		error_messages);
}

void	ft_load_digit_seven(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/7/digit_7_frame_0.xpm",
		"assets/xpm/Bonus/digits/7/digit_7_frame_1.xpm",
		"assets/xpm/Bonus/digits/7/digit_7_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.seven), game, paths,
		error_messages);
}

void	ft_load_digit_nine(t_game *game)
{
	const char	*paths[] = {
		"assets/xpm/Bonus/digits/9/digit_9_frame_0.xpm",
		"assets/xpm/Bonus/digits/9/digit_9_frame_1.xpm",
		"assets/xpm/Bonus/digits/9/digit_9_frame_2.xpm"};
	const char	*error_messages[] = {
		"Generic message error replace soon",
		"Generic message error replace soon",
		"Generic message error replace soon"};

	ft_load_animation_sprites(&(game->hud.digits.nine), game, paths,
		error_messages);
}
